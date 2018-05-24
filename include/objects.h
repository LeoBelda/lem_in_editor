/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:29:06 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/24 14:02:20 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "libftmath.h"
# include "libft.h"

typedef struct	s_room
{
	int				id;
	char			*name;
	t_vec2			coords;
	t_list			*links;
}				t_room;

typedef struct	s_link
{
	int		id;
	t_room	*a;
	t_room	*b;
}				t_link;

#endif
