/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:00:52 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/24 14:00:53 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_n(t_list **lst, int n, void (*del)(void*, size_t))
{
	t_list	*it;
	t_list	*prec;
	int		i;

	it = *lst;
	i = 0;
	while (i++ < n)
	{
		prec = it;
		it = it->next;
	}
	if (it == *lst)
	{
		it = it->next;
		ft_lstdelone(lst, del);
		*lst = it;
	}
	else
	{
		prec->next = it->next;
		ft_lstdelone(&it, del);
	}
}
