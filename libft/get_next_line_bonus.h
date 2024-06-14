/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:58:25 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/14 10:37:38 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# include "./libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define NULL_SIZE 1
# define UINT_MAX 4294967296

// get_next_line.c
char	*get_next_line(int fd);
char	*append_buff(int fd, char *line);
char	*clean_buff_line(char *buff_line);
char	*set_buff_bit(char *buff_line);
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif