/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:11:52 by maxliew           #+#    #+#             */
/*   Updated: 2024/07/16 14:01:57 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
#  define LOOP_RATE 500
#  define TEXT_POS 5
# else 
#  include "../minilibx-linux/mlx.h"
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define ESC 65307
#  define LOOP_RATE 1350
#  define TEXT_POS 20
#  define __APPLE__ 0
# endif

# define X_BUTTON 17

# define INT_MAX 2147483647
# define IMAGE_SIZE 32
# define TRUE 1
# define FALSE 0
# define TICK_RATE 20

# define PLAYER 'P'
# define WALL '1'
# define EMPTY '0'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define ENEMY 'G'

# define UP 1
# define RIGHT 2
# define DOWN 3
# define LEFT 4

typedef int	t_bool;
typedef int	t_direction;
typedef int	t_miliseconds;

typedef struct s_frame
{
	char	*file_name;
	void	*image;
}	t_frame;

typedef struct s_texture
{
	char		*name;
	t_list		*frames;
	int			total_frames;
	int			frame_delay_count;
	t_bool		is_looping;
	t_bool		is_playing;
	int			current_frame;
}	t_texture;

typedef struct s_textures
{
	t_list	*texture_list;
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
	int			*collects_collected;
	t_direction	direction;
	t_bool		*escaped;
	int			x;
	int			y;
}	t_player;

typedef struct s_enemy
{
	int			x;
	int			y;
	t_direction	direction;
	int			direction_x;
	int			direction_y;
	int			move_attempts;	
	t_bool		is_on_collectible;
}	t_enemy;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	int			tick;
	t_textures	*textures;
	t_map		*map;
	t_player	*player;
	t_list		*enemies;
}	t_data;

// so_long.c
void		error_exit(char *str);
int			game_over(t_data *data);
int			key_manager(int keycode, t_data *data);
void		assign_data(t_data *data);

// movement_manager.c
void		movement_manager(int keycode, t_data *data);
void		move_player(t_data *data, int x, int y);
void		move_enemies(t_data *data);
void		move_enemy(t_data *data, t_enemy *enemy);
void		chk_enemy_col(t_enemy *enemy, char *cur_tile, char *look_tile);

// graphics.c
t_textures	*make_textures(t_data *data);
void		put_texture(t_data *data, t_texture *texture_ptr, int x, int y);
void		put_map(t_data *data);
void		put_map_img(t_data *data, int x, int y);
void		put_player(t_data *data, int x, int y);

// graphics2.c

t_texture	*make_manual_texture(t_data *data, char *name, char *file_name);
t_texture	*make_texture(char *name, t_list *frames);
t_texture	*get_texture(t_list *texture_list, char *name);
t_list		*make_frames(t_data *data, char *file_name);
t_frame		*make_frame(t_data *data, char *file_name);

// map.c
t_map		*make_map(char *map_file_path);
char		**make_map_lines(char *map_file_path, int map_height);
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
t_player	*make_player(t_map *map);
t_bool		assign_player_pos(t_player *player, t_map *map);
void		assign_map_size(t_map *map);
void		assign_map_counts(t_map *map);

// enemy_utils.c
t_list		*make_enemies(t_map *map);
t_enemy		*make_enemy(int x, int y);
void		assign_enemy_dir_vector(t_enemy *enemy);
void		flip_enemy_dir(t_enemy *enemy);
void		rotate_enemy_dir(t_enemy *enemy);

// animation_manager.c
int			update_tick(t_data *data);
void		next_frame(t_list **texture_list);
void		update_current_frame(t_texture *texture);

// free_data.c
void		free_data(t_data *data);
void		destroy_texture(t_data *data, t_texture *texture);
void		destroy_textures(t_data *data, t_textures *textures);
void		free_map(t_map *map);
void		free_player(t_player *player);
void		free_str_list(char **str_list);
void		free_enemies(t_list *enemies);

#endif