/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fclamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:58:38 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/24 13:58:39 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_fmin(float a, float b)
{
	return (a > b ? b : a);
}

float	ft_fmax(float a, float b)
{
	return (a < b ? b : a);
}

float	ft_fclamp(float min, float max, float val)
{
	return (ft_fmax(ft_fmin(max, val), min));
}
