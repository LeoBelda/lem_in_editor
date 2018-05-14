/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:13:03 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/02 12:15:15 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	kb_quit(void *e, int type)
{
	(void)type;
	((t_env*)e)->quit = 1;
}

void	kb_debug(void *e, int type)
{
	(void)e;
	(void)type;
}

void	kb_none(void *e, int type)
{
	(void)e;
	(void)type;
}
