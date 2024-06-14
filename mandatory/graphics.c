/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 08:21:51 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/14 11:19:01 by maxliew          ###   ########.fr       */
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
	return (textures);
}

void	set_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->height * data->textures->height)
	{
		x = 0;
		while (x < data->map->width * data->textures->width)
		{
			mlx_put_image_to_window(data->mlx, data->window, data->textures->background, x, y);
			x += data->textures->width;	
		}
		y += data->textures->height;
	}
	// mlx_put_image_to_window(data->mlx, data->window, data->textures->player, 0, 0);
}