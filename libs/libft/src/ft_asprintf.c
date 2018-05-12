/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 11:10:52 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/20 13:24:02 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vasprintf(char **ret, const char *format, va_list ap)
{
	int		r;
	t_ptenv	e;

	if (init_ptenv(&e) == -1)
		return (-1);
	r = ft_genprintf(format, ap, &e);
	if (r != -1)
		*ret = e.final_str;
	return (r);
}

int	ft_asprintf(char **ret, const char *format, ...)
{
	int		r;
	va_list	ap;

	va_start(ap, format);
	r = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (r);
}
