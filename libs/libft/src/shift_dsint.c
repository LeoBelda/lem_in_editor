/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_sint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:28:28 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/03 11:42:36 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		lshift_dsint(t_dsint a, unsigned int val)
{
	while (val--)
		mul_dsint(a, 2);
}

void		rshift_dsint(t_dsint a, unsigned int val)
{
	while (val--)
		div_dsint(a, 2);
}
