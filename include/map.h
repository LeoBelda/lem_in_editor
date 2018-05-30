/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:28:48 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/30 16:41:16 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "libft.h"
# include "printf.h"
# include "objects.h"

typedef struct	s_move
{
	t_room	*start;
	t_room	*end;
	t_link	*lk;
}				t_move;

typedef struct	s_map
{
	uintmax_t	nb_ants;
	int			nb_rooms;
	int			nb_links;
	int			nb_turns;
	t_list		*rooms;
	t_list		*links;
	t_move		**turns;
	t_room		*start;
	t_room		*end;
}				t_map;

void			print_map(t_map map);

void			lstdel_room(void *content, size_t size);
void			lstdel_link(void *content, size_t size);
void			lstdel_linkref(void *content, size_t size);

#endif
