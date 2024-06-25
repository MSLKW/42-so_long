/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:22:52 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/25 13:55:00 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_data(t_data *data)
{
	free_textures(data, data->textures);
	free_map(data->map);
	free_player(data->player);
	// mlx_destroy_window(data->mlx, data->window); why seggy??, ptrs given are non-null
	if (__APPLE__ == 0)
		free(data->mlx); // MAC no need to free, linux need to free
}

void	free_textures(t_data *data, t_textures *textures)
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
	if (map->map_file_path != NULL)
		free(map->map_file_path);
	if (map->lines != NULL)
		free_str_list(map->lines);
	if (map != NULL)
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
	if (player->collectibles_collected != NULL)
		free(player->collectibles_collected); // free problem (munchunk pointer error)
	if (player->escaped != NULL)
		free(player->escaped);
	if (player != NULL)
		free(player);
}