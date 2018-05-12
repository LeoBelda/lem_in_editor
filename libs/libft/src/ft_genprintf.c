/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:41:56 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/23 10:28:53 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	next_percent(const char *format, t_ptenv *e)
{
	size_t	ret;
	char	*str;

	ret = ft_strcspn(format, "%");
	e->fpos += ret;
	if (!(str = ft_strndup(format, ret)))
		return (-1);
	return (ft_lstadd(&e->string_parts, ft_lstnewref(str, ret)));
}

static void	cleanup_flags(int *flags, t_types *type)
{
	int	mask;

	mask = F_TMAX;
	if (*flags & F_NEGATIVE_FIELD || (*flags & F_PRECISION_ON
									&& *flags & F_INTEGER))
		*flags = ~(~*flags | F_ZERO_PADDING);
	if (*flags & F_SIGN_POSITIVE)
		*flags = ~(~*flags | F_BLANK_POSITIVE);
	if (*flags & F_WIDE && *type == T_CHAR)
		*type = T_WCHAR;
	if (*flags & F_WIDE && *type == T_STRING)
		*type = T_WSTRING;
	while (mask & ~*flags && mask != F_TSHORT)
		mask = mask >> 1;
	while (mask != F_TSHORT)
	{
		mask = mask >> 1;
		*flags = ~(~*flags | mask);
	}
}

static int	parse_fmt(const char *format, va_list args, t_ptenv *e)
{
	int	pos;

	pos = 1;
	ft_bzero(&e->info, sizeof(t_arg_info));
	e->info.precision_val = -1;
	e->info.field_width_val = -1;
	e->info.arg_i = e->arg_pos_i;
	e->info.arg_f = e->arg_pos_f;
	e->fpos++;
	while (pos)
	{
		va_copy(e->info.args_ref, args);
		e->info.fmt_ref = &format[e->fpos];
		pos = e->funcs[(unsigned char)format[e->fpos]](&e->info);
		if (pos == -1)
			return (0);
		e->fpos += (pos ? pos : 1);
		va_end(e->info.args_ref);
	}
	cleanup_flags(&e->info.flags, &e->info.type);
	e->arg_pos_i = e->info.arg_i;
	e->arg_pos_f = e->info.arg_f;
	return (e->treat_funcs[e->info.type](e, args) != -1 ?
			ft_lstadd(&e->string_parts,
				ft_lstnewref(e->info.arg_str, e->info.arg_size)) : -1);
}

int			ft_genprintf(const char *format, va_list ap, t_ptenv *e)
{
	va_list	ap_cpy;
	int		ret;

	ret = 0;
	while (format[e->fpos] && ret != -1)
	{
		va_copy(ap_cpy, ap);
		ret = (format[e->fpos] == '%' ?
					parse_fmt(format, ap_cpy, e)
					: next_percent(&format[e->fpos], e));
		va_end(ap_cpy);
	}
	ret = (ret != -1 ? build_final_string(&e->final_str, e->string_parts)
					: cleanup(e->string_parts));
	return (ret);
}
