/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:11:52 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/10 21:03:52 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./libft/ft_printf.h"
#include <fcntl.h>
#include <errno.h>
#include <math.h>
// LINUX:
// #include "./minilibx-linux/mlx.h"

// MAC:
#include "./minilibx_opengl/mlx.h"

typedef struct s_data
{
	void	*mlx;
	void	*windows;
	int		moves_count;
}	t_data;

#endif