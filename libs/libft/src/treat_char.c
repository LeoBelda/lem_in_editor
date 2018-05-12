/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 10:55:33 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/18 15:53:10 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_char(t_ptenv *e, va_list args)
{
	int	i;

	i = 0;
	while (++i <= e->info.arg_i)
		va_arg(args, uintmax_t);
	e->info.invalid_char = (char)va_arg(args, intmax_t);
	e->arg_pos_i++;
	return (treat_invalid(e, args));
}
