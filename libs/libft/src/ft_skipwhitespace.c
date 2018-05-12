/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipwhitespace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:26:00 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/07 16:26:00 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_skipwhitespace(const char *str)
{
	int	count;

	count = 0;
	while (ft_iswhitespace(str[count]))
		count++;
	return (count);
}
