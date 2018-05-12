/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 09:51:53 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/25 09:53:39 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	m_pro(int ret)
{
	if (ret == -1)
		error_exit("malloc error");
}

void	m_pro_null(void *ret)
{
	if (!ret)
		error_exit("malloc error");
}

void	free_pro(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	map_error_exit(void)
{
	ft_putendl_fd("ERROR", 2);
	exit(EXIT_FAILURE);
}

void	error_exit(const char *str)
{
	ft_putstr_fd("ERR: ", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}
