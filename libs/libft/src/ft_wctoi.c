/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:39:56 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/18 12:28:31 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define WCH_2 0x000080c0
#define WCH_3 0x008080e0
#define WCH_4 0x808080f0

#define MSK_I 0x0010ffff
#define MSK_4 0x001f0000
#define MSK_3 0x0000f800
#define MSK_2 0x00000780
#define MSK_1 0x0000007f

#define SHIFT_4 0x001c0000
#define SHIFT_3 0x0003f000
#define SHIFT_2 0x00000fc0
#define SHIFT_1 0x0000003f

static int	check_zones(const wchar_t wch)
{
	if (wch >= 0xD800 && wch <= 0xDFFF)
		return (1);
	else
		return (0);
}

int			ft_wctoi(const wchar_t wch, int *size)
{
	if ((unsigned)wch > MSK_I || check_zones(wch))
		return (-1);
	else if (wch & MSK_4)
	{
		*size = 4;
		return (((wch & SHIFT_4) >> 18) | ((wch & SHIFT_3) >> 4)
				| ((wch & SHIFT_2) << 10) | ((wch & SHIFT_1) << 24) | WCH_4);
	}
	else if (wch & MSK_3)
	{
		*size = 3;
		return (((wch & SHIFT_3) >> 12)
				| ((wch & SHIFT_2) << 2) | ((wch & SHIFT_1) << 16) | WCH_3);
	}
	else if (wch & MSK_2)
	{
		*size = 2;
		return (((wch & SHIFT_2) >> 6) | ((wch & SHIFT_1) << 8) | WCH_2);
	}
	else
	{
		*size = 1;
		return (wch);
	}
}
