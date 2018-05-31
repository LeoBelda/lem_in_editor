/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 10:32:35 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/31 10:54:46 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	error_map(t_parse p, const char *str)
{
	clean_parse_full(p);
	ft_putstr_fd("visu:ERR: ", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}
