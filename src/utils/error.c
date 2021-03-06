/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 09:51:53 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/25 03:33:07 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	error_exit(const char *str)
{
	ft_putstr_fd("visu:ERR: ", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	usage_exit(void)
{
	ft_putendl_fd("usage: ./visu [-e]", 2);
	exit(EXIT_FAILURE);
}
