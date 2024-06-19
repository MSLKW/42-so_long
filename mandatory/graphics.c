/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 08:21:51 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/19 13:01:28 by maxliew          ###   ########.fr       */
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
	textures->player = mlx_xpm_file_to_image(data->mlx, "./textures/player.xpm", &textures->width, &textures->height);
	textures->collectible = mlx_xpm_file_to_image(data->mlx, "./textures/collectible.xpm", &textures->width, &textures->height);
	textures->exit_closed = mlx_xpm_file_to_image(data->mlx, "./textures/exit_closed.xpm", &textures->width, &textures->height);
	textures->exit_open = mlx_xpm_file_to_image(data->mlx, "./textures/exit_open.xpm", &textures->width, &textures->height);	
	textures->wall = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm", &textures->width, &textures->height);
	return (textures);
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

void	put_image(t_data *data, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window, img_ptr, x * data->textures->width, y * data->textures->height);
}