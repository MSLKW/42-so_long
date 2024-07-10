/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:11:52 by maxliew           #+#    #+#             */
/*   Updated: 2024/07/10 12:20:51 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/ft_printf.h"
# include "../libft/libft.h"
# include "../libft/get_next_line_bonus.h"
# include <fcntl.h>
# include <errno.h>
# include <math.h>

# ifdef __APPLE__
#  include "../minilibx_opengl/mlx.h"
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define ESC 53
# else 
#  include "../minilibx-linux/mlx.h"
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define ESC 65307
#  define __APPLE__ 0
# endif

# define X_BUTTON 17

# define INT_MAX 2147483647
# define IMAGE_SIZE 32
# define TRUE 1
# define FALSE 0

# define PLAYER 'P'
# define WALL '1'
# define EMPTY '0'
# define EXIT 'E'
# define COLLECTIBLE 'C'

# define UP 1
# define RIGHT 2
# define DOWN 3
# define LEFT 4

typedef int	t_bool;
typedef int	t_direction;

typedef struct s_textures
{
	void	*wall;
	void	*player_left;
	void	*player_right;
	void	*collectible;
	void	*background;
	void	*exit_closed;
	void	*exit_open;
	int		width;
	int		height;
}	t_textures;

typedef struct s_map
{
	char	**lines;
	char	*map_file_path;
	int		collectibles_count;
	int		exits_count;
	int		players_count;
	int		width;
	int		height;
}	t_map;

typedef struct s_player
{
	int			moves_count;
	int			*collectibles_collected;
	t_direction	direction;
	t_bool		*escaped;
	int			x;
	int			y;
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
void		error_exit(char *str);
int			game_over(t_data *data);
int			key_manager(int keycode, t_data *data);

// movement_manager.c
void		movement_manager(int keycode, t_data *data);
void		move_player(t_data *data, int x, int y);

// graphics.c
t_textures	*get_textures(t_data *data);
void		set_textures(t_data *data, t_textures *textures);
void		put_image(t_data *data, void *img_ptr, int x, int y);
void		put_map(t_data *data);
void		put_map_img(t_data *data, int x, int y);

// map.c
t_map		*get_map(char *map_file_path);
char		**get_map_lines(char *map_file_path, int map_height);
int			get_map_height(char *map_file_path);

// map_validator.c
t_bool		is_map_valid(t_map *map);
t_bool		is_rectangle(t_map *map);
t_bool		is_only_one(t_map *map);
t_bool		is_walled(t_map *map);

// map_validator2.c
t_bool		is_pathable(t_map *map, t_player sim, t_bool path_found);
t_bool		path_conds(t_map *map, t_player sim, t_bool path_found);

// map_validator3.c
t_bool		path_up(t_map *map, t_player sim, t_bool path_found);
t_bool		path_down(t_map *map, t_player sim, t_bool path_found);
t_bool		path_left(t_map *map, t_player sim, t_bool path_found);
t_bool		path_right(t_map *map, t_player sim, t_bool path_found);

// map_utils.c
t_bool		is_all_same(char *str, char c);
t_player	*get_player(t_map *map);
t_bool		assign_player_pos(t_player *player, t_map *map);
void		assign_map_size(t_map *map);
void		assign_map_counts(t_map *map);

// free_data.c
void		free_data(t_data *data);
void		free_textures(t_data *data, t_textures *textures);
void		free_map(t_map *map);
void		free_player(t_player *player);
void		free_str_list(char **str_list);

#endif