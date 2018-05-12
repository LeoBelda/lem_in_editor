/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 11:11:16 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/20 12:53:47 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vsprintf(char *str, const char *format, va_list ap)
{
	return (ft_vsnprintf(str, (size_t)INT_MAX + 1u, format, ap));
}

int	ft_sprintf(char *str, const char *format, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, format);
	ret = ft_vsprintf(str, format, ap);
	va_end(ap);
	return (ret);
}
