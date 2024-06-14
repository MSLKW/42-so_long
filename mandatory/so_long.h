/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:11:52 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/14 09:09:11 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/ft_printf.h"
#include <fcntl.h>
#include <errno.h>
#include <math.h>
// LINUX:
// #include "../minilibx-linux/mlx.h"

// MAC:
#include "../minilibx_opengl/mlx.h"

# define IMAGE_SIZE 32

typedef struct s_textures
{
	void	*wall;
	void	*player;
	void	*collectible;
	void	*background;
	void	*map_exit;
	int		width;
	int		height;
}	t_textures;

typedef struct s_map
{
	int	width;
	int	height;
}	t_map;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	int			moves_count;
	t_textures	*textures;
	t_map		*map;
}	t_data;

// so_long.c
void	error_exit(char *str);
int		game_over(t_data *data);
void	movement_manager(int keycode, t_data *data);
int		key_manager(int keycode, t_data *data);

// graphics.c
t_textures	*get_textures(t_data *data);
void		set_background(t_data *data);

// map.c
t_map	*get_map(void);
#endif