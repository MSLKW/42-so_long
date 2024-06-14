/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:11:52 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/14 13:30:51 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/ft_printf.h"
#include "../libft/libft.h"
#include "../libft/get_next_line_bonus.h"
#include <fcntl.h>
#include <errno.h>
#include <math.h>
// LINUX:
// #include "../minilibx-linux/mlx.h"

// MAC:
#include "../minilibx_opengl/mlx.h"

# define INT_MAX 2147483647
# define IMAGE_SIZE 32
# define TRUE 1
# define FALSE 0

typedef int t_bool;

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
	char	**map_lines;
	int		collectibles_count;
	int		exits_count;
	int		players_count;
	int		width;
	int		height;
}	t_map;

typedef struct s_player
{
	int		moves_count;
	int		collectibles_collected;
	int		x;
	int		y;
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	t_textures	*textures;
	t_map		*map;
	t_player	*player;
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
t_map	*get_map(char *map_file_path);

// map_validator.c

// map_utils.c
t_bool	is_all_same(char *str, char c);
void	assign_map_size(t_map *map);
void	assign_map_counts(t_map *map);

#endif