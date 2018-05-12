/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:23:01 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/18 11:16:11 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		create_dsint(t_dsint *a, size_t size)
{
	a->size = size;
	if (!(a->tab = (uintmax_t*)malloc(size * sizeof(uintmax_t))))
		return (0);
	ft_bzero(a->tab, a->size * sizeof(uintmax_t));
	return (1);
}

void	set_dsint_val_all(t_dsint a, uintmax_t val)
{
	while (a.size--)
		a.tab[a.size] = val;
}

void	set_dsint_val(t_dsint a, uintmax_t val)
{
	a.tab[0] = val;
}

void	print_dsint(t_dsint a)
{
	size_t			i;
	unsigned char	*ptr;

	i = (a.size / 2) * sizeof(uintmax_t) / sizeof(unsigned char);
	ptr = (unsigned char*)a.tab;
	while (i--)
	{
		ft_printf("%08jb ", ptr[i]);
		if (!(i % 8))
			ft_putendl("");
	}
}

void	destroy_dsint(t_dsint a)
{
	a.size = 0;
	free(a.tab);
	a.tab = NULL;
}
