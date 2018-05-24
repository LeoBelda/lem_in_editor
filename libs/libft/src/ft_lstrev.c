/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:01:12 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/24 14:01:12 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **lst)
{
	t_list *prec;
	t_list *tmp;
	t_list *tmp_n;

	prec = NULL;
	tmp = *lst;
	while (tmp)
	{
		tmp_n = tmp->next;
		tmp->next = prec;
		prec = tmp;
		tmp = tmp_n;
	}
	*lst = prec;
}
