/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 08:21:51 by maxliew           #+#    #+#             */
/*   Updated: 2024/07/12 11:51:43 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_textures	*make_textures(t_data *data)
{
	t_textures	*textures;
	t_list		*texture_list;

	textures = malloc(sizeof(t_textures));
	if (textures == NULL)
		return (NULL);
	textures->width = IMAGE_SIZE;
	textures->height = IMAGE_SIZE;
	texture_list = ft_lstnew(make_texture("player_right", make_frames(data, "player_right")));
	ft_lstadd_back(texture_list, ft_lstnew(make_texture("player_left", make_frames(data, "player_left"))));
	ft_lstadd_back(texture_list, ft_lstnew(make_texture("wall", make_frames(data, "wall"))));
	ft_lstadd_back(texture_list, ft_lstnew(make_texture("collectible", make_frames(data, "collectible"))));
	ft_lstadd_back(texture_list, ft_lstnew(make_texture("background", make_frames(data, "background"))));
	ft_lstadd_back(texture_list, ft_lstnew(make_texture("exit", make_frames(data, "exit"))));
	ft_lstadd_back(texture_list, ft_lstnew(make_texture("enemy", make_frames(data, "enemy"))));
	return (textures);
}

t_texture	*make_texture(char *name, t_list *frames)
{
	t_texture *texture;

	texture = malloc(sizeof(t_texture));
	if (texture == NULL)
		return (NULL);
	texture->frames = frames;
	texture->total_frames = ft_lstsize(frames);
	texture->is_looping = TRUE;
	texture->is_playing = TRUE;
	texture->current_frame = 0;
	return (texture);
}

t_texture	*get_texture(t_list *texture_list, char *name)
{
	t_list	*head;
	t_texture *texture;

	head = texture_list;
	while (head != NULL)
	{
		texture = head->content;
		if (texture->name == name)
			return (texture);
		head = head->next;
	}
	return (NULL);
}

t_list	*make_frames(t_data *data, char *file_name)
{
	t_list	*frames;
	t_frame	*frame;
	int		index;
	char	*itoa_index;
	char	*full_filename;

	frame = make_frame(data, file_name, 0);
	if (frame == NULL)
		return (NULL);
	frames = ft_lstnew(frame);
	index = 1;
	while (frame != NULL)
	{
		itoa_index = ft_itoa(index);
		full_filename = ft_strjoin(file_name, itoa_index);
		frame = make_frame(data, full_filename, index);
		if (frame != NULL)
			ft_lstadd_back(&frames, ft_lstnew(frame));
		index++;
		free(itoa_index);
		free(full_filename);
	}
	return (frames);
}

t_frame	*make_frame(t_data *data, char *file_name, int index)
{
	t_frame *frame;

	frame = malloc(sizeof(t_frame));
	if (frame == NULL)
		return (NULL);
	frame->image = mlx_xpm_file_to_image(data->mlx, file_name, &data->textures->width, &data->textures->height);
	if (frame->image == NULL)
	{
		free(frame);
		return (NULL);
	}
	frame->file_name = file_name;
	frame->index = index;
}

void	put_image(t_data *data, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window, img_ptr, \
		x * data->textures->width, y * data->textures->height);
}

void	put_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			put_map_img(data, x, y);
			x++;
		}
		y++;
	}
}

void	put_map_img(t_data *data, int x, int y)
{
	put_image(data, data->textures->background, x, y);
	if (data->map->lines[y][x] == PLAYER)
		put_player(data, x, y);
	else if (data->map->lines[y][x] == WALL)
		put_image(data, data->textures->wall, x, y);
	else if (data->map->lines[y][x] == COLLECTIBLE)
		put_image(data, data->textures->collectible, x, y);
	else if (data->map->lines[y][x] == EXIT && *data->player->escaped == FALSE)
		put_image(data, data->textures->exit_closed, x, y);
	else if (data->map->lines[y][x] == EXIT && *data->player->escaped == TRUE)
		put_image(data, data->textures->exit_open, x, y);
	else if (data->map->lines[y][x] == ENEMY)
		put_image(data, data->textures->enemy, x, y);
}

void	put_player(t_data *data, int x, int y)
{
	char	*moves_count_str;
	char	*moves_text;

	if (data->player->direction == LEFT)
		put_image(data, data->textures->player_left, x, y);
	else if (data->player->direction == RIGHT)
		put_image(data, data->textures->player_right, x, y);
	moves_count_str = ft_itoa(data->player->moves_count);
	moves_text = ft_strjoin("Moves: ", moves_count_str);
	mlx_string_put(data->mlx, data->window, 20, 20, INT_MAX, moves_text);
	free(moves_count_str);
	free(moves_text);
}