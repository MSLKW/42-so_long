/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 08:21:51 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/25 13:50:11 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_textures	*get_textures(t_data *data)
{
	t_textures *textures;

	textures = malloc(sizeof(t_textures));
	if (textures == NULL)
		return (NULL);
	textures->width = IMAGE_SIZE;
	textures->height = IMAGE_SIZE;
	textures->background = mlx_xpm_file_to_image(data->mlx, "./textures/background.xpm", &textures->width, &textures->height);
	textures->player_right = mlx_xpm_file_to_image(data->mlx, "./textures/player_right.xpm", &textures->width, &textures->height);
	textures->player_left = mlx_xpm_file_to_image(data->mlx, "./textures/player_test.xpm", &textures->width, &textures->height);
	textures->collectible = mlx_xpm_file_to_image(data->mlx, "./textures/collectible.xpm", &textures->width, &textures->height);
	textures->exit_closed = mlx_xpm_file_to_image(data->mlx, "./textures/exit_closed.xpm", &textures->width, &textures->height);
	textures->exit_open = mlx_xpm_file_to_image(data->mlx, "./textures/exit_open.xpm", &textures->width, &textures->height);	
	textures->wall = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm", &textures->width, &textures->height);
	if (textures->background == NULL || 
		textures->player_right == NULL ||
		textures->player_left == NULL || 
		textures->collectible == NULL || 
		textures->exit_closed == NULL || 
		textures->exit_open == NULL || 
		textures->wall == NULL)
	{
		free_textures(data, data->textures);
		return (NULL);
	}
	return (textures);
}

void	put_image(t_data *data, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window, img_ptr, x * data->textures->width, y * data->textures->height);
}
void	put_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			put_image(data, data->textures->background, x, y);
			x++;	
		}
		y++;
	}
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
			put_image(data, data->textures->background, x, y);
			if (data->map->lines[y][x] == PLAYER)
			{
				if (data->player->direction == LEFT)
					put_image(data, data->textures->player_left, x, y);
				else if (data->player->direction == RIGHT)
					put_image(data, data->textures->player_right, x, y);
			}
			else if (data->map->lines[y][x] == WALL)
				put_image(data, data->textures->wall, x, y);
			else if (data->map->lines[y][x] == COLLECTIBLE)
				put_image(data, data->textures->collectible, x, y);
			else if (data->map->lines[y][x] == EXIT && *data->player->escaped == FALSE)
				put_image(data, data->textures->exit_closed, x, y);
			else if (data->map->lines[y][x] == EXIT && *data->player->escaped == TRUE)
				put_image(data, data->textures->exit_open, x, y);
			x++;
		}
		y++;
	}
}
