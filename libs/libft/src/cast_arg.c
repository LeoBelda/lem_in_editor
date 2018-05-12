/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:27:47 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/18 15:14:33 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		scroll_args(t_ptenv *e, va_list args)
{
	int	i;

	i = 0;
	while (++i <= e->info.arg_i)
		va_arg(args, uintmax_t);
	i = 0;
	while (++i <= e->info.arg_f)
		va_arg(args, double);
}

intmax_t	cast_signed_arg(t_ptenv *e, va_list args)
{
	intmax_t	ret;

	if (e->info.flags & F_TSHORTSHORT)
		ret = (signed char)va_arg(args, intmax_t);
	else if (e->info.flags & F_TSHORT)
		ret = (signed short)va_arg(args, intmax_t);
	else if (e->info.flags & F_TLONG)
		ret = (signed long)va_arg(args, intmax_t);
	else if (e->info.flags & F_TLONGLONG)
		ret = (signed long long)va_arg(args, intmax_t);
	else if (e->info.flags & F_TSIZE)
		ret = (size_t)va_arg(args, intmax_t);
	else if (e->info.flags & F_TMAX)
		ret = (intmax_t)va_arg(args, intmax_t);
	else
		ret = (signed int)va_arg(args, intmax_t);
	return (ret);
}

uintmax_t	cast_unsigned_arg(t_ptenv *e, va_list args)
{
	uintmax_t	ret;

	if (e->info.flags & F_MEMORY)
		ret = (uintmax_t)va_arg(args, void*);
	else if (e->info.flags & F_TSHORTSHORT)
		ret = (unsigned char)va_arg(args, uintmax_t);
	else if (e->info.flags & F_TSHORT)
		ret = (unsigned short)va_arg(args, uintmax_t);
	else if (e->info.flags & F_TLONG)
		ret = (unsigned long)va_arg(args, uintmax_t);
	else if (e->info.flags & F_TLONGLONG)
		ret = (unsigned long long)va_arg(args, uintmax_t);
	else if (e->info.flags & F_TSIZE)
		ret = (size_t)va_arg(args, uintmax_t);
	else if (e->info.flags & F_TMAX)
		ret = (uintmax_t)va_arg(args, uintmax_t);
	else
		ret = (unsigned int)va_arg(args, uintmax_t);
	return (ret);
}

void		cast_ptr_arg(t_ptenv *e, va_list args)
{
	if (e->info.flags & F_TSHORTSHORT)
		*va_arg(args, signed char *) =
			(signed char)get_total_size(e->string_parts);
	else if (e->info.flags & F_TSHORT)
		*va_arg(args, short *) =
			(short)get_total_size(e->string_parts);
	else if (e->info.flags & F_TLONG)
		*va_arg(args, long *) =
			(signed long)get_total_size(e->string_parts);
	else if (e->info.flags & F_TLONGLONG)
		*va_arg(args, long long *) =
			(signed long long)get_total_size(e->string_parts);
	else if (e->info.flags & F_TSIZE)
		*va_arg(args, size_t *) =
			(size_t)get_total_size(e->string_parts);
	else if (e->info.flags & F_TMAX)
		*va_arg(args, intmax_t *) =
			(intmax_t)get_total_size(e->string_parts);
	else
	{
		*(va_arg(args, int *)) =
			(int)(get_total_size(e->string_parts));
	}
}
