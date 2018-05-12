/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 11:11:07 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/20 13:17:04 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	int		ret;
	t_ptenv	e;

	if (init_ptenv(&e) == -1)
		return (-1);
	ret = ft_genprintf(format, ap, &e);
	if (ret != -1)
	{
		ft_strncpy(str, e.final_str, size ? size - 1 : 0);
		if (e.final_str)
			free(e.final_str);
	}
	return (ret);
}

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, format);
	ret = ft_vsnprintf(str, size, format, ap);
	va_end(ap);
	return (ret);
}
