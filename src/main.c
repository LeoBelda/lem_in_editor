/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:27:50 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/25 03:34:13 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

t_mode	parse_args(int argc, char **argv)
{
	if (argc == 1)
		return (V_VISU);
	else if (argc == 2 && !ft_strcmp(argv[1], "-e"))
		return (V_EDIT);
	else
		usage_exit();
	return (V_VISU);
}

int	main(int argc, char **argv)
{
	t_mode	mode;

	mode = parse_args(argc, argv);
	lem_in_visu(mode);
	return (0);
}
