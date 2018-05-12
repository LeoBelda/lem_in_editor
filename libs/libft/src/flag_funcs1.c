/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_funcs1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:36:35 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/21 18:24:50 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_hashtag_flag(t_arg_info *inf)
{
	inf->flags |= F_ALTERNATE_FORM;
	return (1);
}

int	p_zero_flag(t_arg_info *inf)
{
	inf->flags |= F_ZERO_PADDING;
	return (1);
}

int	p_minus_flag(t_arg_info *inf)
{
	inf->flags |= F_NEGATIVE_FIELD;
	return (1);
}

int	p_space_flag(t_arg_info *inf)
{
	inf->flags |= F_BLANK_POSITIVE;
	return (1);
}

int	p_plus_flag(t_arg_info *inf)
{
	inf->flags |= F_SIGN_POSITIVE;
	return (1);
}
