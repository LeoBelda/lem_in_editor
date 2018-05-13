/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 09:58:37 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/02 12:22:29 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "unistd.h"
# include "fcntl.h"
# include "libft.h"
# include "ft_printf.h"

void			m_pro(int ret);
void			m_pro_null(void *ret);
void			free_pro(void **ptr);

void			error_exit(const char *str);

#endif
