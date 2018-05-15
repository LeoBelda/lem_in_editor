/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_funcs_spe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:24:17 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/07 16:24:18 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

#define I_COMMENT 1
#define I_COMMAND 2

#define SEP_CHAR ' '
#define LEM_CHAR 'L'
#define LINK_CHAR '-'
#define START_STR "start"
#define END_STR "end"

static int	valid_moves(const char **tab)
{
	int	len;
	int	i;

	len = 0;
	while (tab[len])
	{
		i = 0;
		if (tab[len][i] != LEM_CHAR)
			return (0);
		i++;
		while (ft_isdigit(tab[len][i]))
			i++;
		if (i == 1 || tab[len][i] != LINK_CHAR)
			return (0);
		if(!tab[len][++i])
			return (0);
		len++;
	}
	return (len);
}

int			parse_moves(const char *line, t_parse *parse)
{
	char		**tab;
	t_moveparse	*moves;
	int			i;
	int			len;

	m_pro_null(tab = ft_strsplit(line, SEP_CHAR));
	if (!(len = valid_moves((const char **)tab)))
		return (LINE_USR_BAD);
	m_pro_null(moves = ft_memalloc(sizeof(t_moveparse) * (len + 1)));
	len = -1;
	while (tab[++len])
	{
		i = 1;
		moves[len].ant_id = ft_atoui(&tab[len][i]);
		if (!moves[len].ant_id || moves[len].ant_id > parse->ant_count)
			return (LINE_USR_BAD);
		while (ft_isdigit(tab[len][i]))
			i++;
		i++;
		m_pro_null(moves[len].name = ft_strdup(&tab[len][i]));
	}
	m_pro(ft_lstadd(&parse->turns, ft_lstnewref((void*)moves, len)));
	ft_tabdel(&tab);
	ft_putendl(line);
	return (LINE_OK);
}

int			parse_command(const char *line, t_parse *parse)
{
	if (ft_strequ(&line[I_COMMAND], START_STR))
	{
		parse->command = COMMAND_START;
		ft_putendl(line);
	}
	else if (ft_strequ(&line[I_COMMAND], END_STR))
	{
		parse->command = COMMAND_END;
		ft_putendl(line);
	}
	return (LINE_OK);
}

int			parse_comment(const char *line, t_parse *parse)
{
	(void)parse;
	ft_putendl(line);
	return (LINE_OK);
}
