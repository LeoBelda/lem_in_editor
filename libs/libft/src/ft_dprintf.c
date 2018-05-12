/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 11:10:58 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/16 11:10:59 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int		ret;
	t_ptenv	e;

	if (init_ptenv(&e) == -1)
		return (-1);
	ret = ft_genprintf(format, ap, &e);
	if (ret != -1)
	{
		ret = write(fd, e.final_str, ret);
		if (e.final_str)
			free(e.final_str);
	}
	return (ret);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, format);
	ret = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ret);
}
