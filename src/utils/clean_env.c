/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_visu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:12:38 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/02 12:12:39 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void		clean_env(t_env e)
{
	SDL_GL_DeleteContext(e.ogl.context);
	SDL_DestroyWindow(e.win);
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
	SDL_Quit();
}
