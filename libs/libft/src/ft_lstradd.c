/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstradd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:04:19 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/25 16:41:47 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstradd(t_list **alst, t_list *new)
{
	t_list	*i;

	if (!new)
		return (-1);
	if (!*alst)
		*alst = new;
	else
	{
		i = *alst;
		while (i->next)
			i = i->next;
		i->next = new;
	}
	return (0);
}
