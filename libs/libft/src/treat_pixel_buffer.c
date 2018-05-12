/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_pixel_buffer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:09:39 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/22 12:59:36 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static wchar_t	determine_wchar_p2(unsigned int *b1, unsigned int *b2)
{
	if (!b1[0] && b1[1] && !b2[0] && b2[1])
		return (0x2590);
	else if (b1[0] && !b1[1] && !b2[0] && b2[1])
		return (0x259A);
	else if (!b1[0] && b1[1] && b2[0] && !b2[1])
		return (0x259E);
	else if (b1[0] && !b1[1] && !b2[0] && !b2[1])
		return (0x2598);
	else if (!b1[0] && b1[1] && !b2[0] && !b2[1])
		return (0x259D);
	else if (!b1[0] && !b1[1] && b2[0] && !b2[1])
		return (0x2596);
	else if (!b1[0] && !b1[1] && !b2[0] && b2[1])
		return (0x2597);
	else
		return (0x20);
}

static wchar_t	determine_wchar_p1(unsigned int *b1, unsigned int *b2)
{
	if ((!b1[0] && !b1[1] && !b2[0] && !b2[1]))
		return (0x20);
	else if (b1[0] && b1[1] && b2[0] && b2[1])
		return (0x2588);
	else if (b1[0] && b1[1] && b2[0] && !b2[1])
		return (0x259B);
	else if (b1[0] && b1[1] && !b2[0] && b2[1])
		return (0x259C);
	else if (b1[0] && !b1[1] && b2[0] && b2[1])
		return (0x2599);
	else if (!b1[0] && b1[1] && b2[0] && b2[1])
		return (0x259F);
	else if (b1[0] && b1[1] && !b2[0] && !b2[1])
		return (0x2580);
	else if (!b1[0] && !b1[1] && b2[0] && b2[1])
		return (0x2584);
	else if (b1[0] && !b1[1] && b2[0] && !b2[1])
		return (0x258C);
	else
		return (determine_wchar_p2(b1, b2));
}

static char		*pixels_to_wstr(unsigned int *buf, int width,
								int height, int *size)
{
	int		i;
	int		j;
	wchar_t	str[*size + 1];

	(void)height;
	i = 0;
	j = 0;
	while (i < *size - width - height)
	{
		str[j] = determine_wchar_p1(&buf[i], &buf[i + width]);
		if (i % width == width - 2)
		{
			j++;
			i += width;
			str[j] = 0xa;
		}
		i += 2;
		j++;
	}
	str[*size] = 0;
	return (ft_wstrtostr(str, *size, size));
}

static char		*pixels_to_str(unsigned int *buf, int width,
							int height, int size)
{
	int		i;
	int		j;
	char	str[size + 1];

	i = 0;
	j = 0;
	while (i < size - height)
	{
		if (buf[i])
			str[j] = 0x58;
		else
			str[j] = 0x20;
		if (i % width == width - 1)
		{
			j++;
			str[j] = 0xa;
		}
		i++;
		j++;
	}
	str[size] = 0;
	return (ft_strdup(str));
}

int				treat_pixel_buffer(t_ptenv *e, va_list args)
{
	int	i;

	i = 0;
	while (++i <= e->info.arg_i)
		va_arg(args, uintmax_t);
	e->info.arg_size = e->info.field_width_val * (e->info.precision_val + 1);
	if (!(e->info.arg_str =
		e->info.type == T_PIXEL_BUFFER ?
			pixels_to_str((unsigned int*)va_arg(args, unsigned int*),
			e->info.field_width_val, e->info.precision_val, e->info.arg_size)
			: pixels_to_wstr((unsigned int*)va_arg(args, unsigned int*),
			e->info.field_width_val, e->info.precision_val, &e->info.arg_size)))
		return (-1);
	e->arg_pos_i++;
	return (0);
}
