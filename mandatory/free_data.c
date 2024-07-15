/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:22:52 by maxliew           #+#    #+#             */
/*   Updated: 2024/07/15 13:27:43 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_data(t_data *data)
{
	destroy_textures(data, data->textures);
	free_map(data->map);
	free_player(data->player);
	mlx_destroy_window(data->mlx, data->window);
	if (__APPLE__ == 0)
		free(data->mlx);
}

void	destroy_textures(t_data *data, t_textures *textures)
{
	mlx_destroy_image(data->mlx, textures->wall);
	mlx_destroy_image(data->mlx, textures->player_right);
	mlx_destroy_image(data->mlx, textures->player_left);
	mlx_destroy_image(data->mlx, textures->collectible);
	mlx_destroy_image(data->mlx, textures->background);
	mlx_destroy_image(data->mlx, textures->exit_closed);
	mlx_destroy_image(data->mlx, textures->exit_open);
	free(textures);
}

void	free_map(t_map *map)
{
	free(map->map_file_path);
	free_str_list(map->lines);
	free(map);
}

void	free_str_list(char **str_list)
{
	int	index;

	index = 0;
	while (str_list[index] != NULL)
	{
		free(str_list[index]);
		index++;
	}
	free(str_list);
}

void	free_player(t_player *player)
{
	free(player->collectibles_collected);
	free(player->escaped);
	free(player);
}
