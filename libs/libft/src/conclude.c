/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conclude.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 15:31:59 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/30 11:55:40 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	concat_str_parts_clean(char *str, t_list *str_parts)
{
	t_list	*tmp;

	while (str_parts)
	{
		str -= str_parts->content_size;
		ft_memmove(str, str_parts->content, str_parts->content_size);
		free(str_parts->content);
		tmp = str_parts;
		str_parts = str_parts->next;
		free(tmp);
	}
}

int			cleanup(t_list *str_parts)
{
	while (str_parts)
	{
		free(str_parts->content);
		str_parts = str_parts->next;
	}
	return (-1);
}

int			get_total_size(t_list *str_parts)
{
	int	size;

	size = 0;
	while (str_parts)
	{
		size += str_parts->content_size;
		str_parts = str_parts->next;
	}
	return (size);
}

int			build_final_string(char **final_str, t_list *str_parts)
{
	int		size;

	size = get_total_size(str_parts);
	if (!(*final_str = ft_strnew(size)))
		return (cleanup(str_parts));
	concat_str_parts_clean(&(*final_str)[size], str_parts);
	return (size);
}
