/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_size_to_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:54:33 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/18 15:54:16 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_size_to_ptr(t_ptenv *e, va_list args)
{
	int	i;

	i = 0;
	while (++i <= e->info.arg_i)
		va_arg(args, uintmax_t);
	cast_ptr_arg(e, args);
	e->info.arg_str = NULL;
	e->info.arg_size = 0;
	e->arg_pos_i++;
	return (0);
}
