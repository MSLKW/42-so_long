/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 08:21:51 by maxliew           #+#    #+#             */
/*   Updated: 2024/07/16 13:44:21 by maxliew          ###   ########.fr       */
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
	data->textures = textures;
	texture_list = ft_lstnew(make_manual_texture(data, \
		"player", "./textures/player"));
	ft_lstadd_back(&texture_list, ft_lstnew(make_texture(\
		"wall", make_frames(data, "./textures/wall"))));
	ft_lstadd_back(&texture_list, ft_lstnew(make_texture(\
		"collectible", make_frames(data, "./textures/collectible"))));
	ft_lstadd_back(&texture_list, ft_lstnew(make_texture(\
		"background", make_frames(data, "./textures/background"))));
	ft_lstadd_back(&texture_list, ft_lstnew(make_manual_texture(data, \
		"exit", "./textures/exit")));
	ft_lstadd_back(&texture_list, ft_lstnew(make_texture(\
		"enemy", make_frames(data, "./textures/enemy"))));
	textures->texture_list = texture_list;
	return (textures);
}

void	put_texture(t_data *data, t_texture *texture_ptr, int x, int y)
{
	t_frame	*frame;

	frame = ft_lstindex(&texture_ptr->frames, \
		texture_ptr->current_frame)->content;
	mlx_put_image_to_window(data->mlx, data->window, frame->image, \
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
	put_texture(data, get_texture(data->textures->texture_list, \
		"background"), x, y);
	if (data->map->lines[y][x] == PLAYER)
		put_player(data, x, y);
	else if (data->map->lines[y][x] == WALL)
		put_texture(data, get_texture(data->textures->texture_list, \
			"wall"), x, y);
	else if (data->map->lines[y][x] == COLLECTIBLE)
		put_texture(data, get_texture(data->textures->texture_list, \
			"collectible"), x, y);
	else if (data->map->lines[y][x] == EXIT)
		put_texture(data, get_texture(data->textures->texture_list, \
			"exit"), x, y);
	else if (data->map->lines[y][x] == ENEMY)
		put_texture(data, get_texture(data->textures->texture_list, \
			"enemy"), x, y);
}

void	put_player(t_data *data, int x, int y)
{
	char	*moves_count_str;
	char	*moves_text;

	put_texture(data, get_texture(data->textures->texture_list, \
		"player"), x, y);
	moves_count_str = ft_itoa(data->player->moves_count);
	moves_text = ft_strjoin("Moves: ", moves_count_str);
	mlx_string_put(data->mlx, data->window, \
		TEXT_POS, TEXT_POS, INT_MAX, moves_text);
	free(moves_count_str);
	free(moves_text);
}
