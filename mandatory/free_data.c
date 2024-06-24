/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:22:52 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/24 15:41:25 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_data(t_data *data)
{
	free_textures(data->textures);
	free_map(data->map);
	free_player(data->player);
	free(data->mlx);
	// free(data->window);
}

void	free_textures(t_data *data, t_textures *textures) // how to free textures without definitely lost
{
	mlx_destroy_image(data->mlx, textures->wall); // just do this for all the imgs
	free(textures->player);
	free(textures->collectible);
	free(textures->background);
	free(textures->exit_closed);
	free(textures->exit_open);
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
	ft_printf("%p\n", player->collectibles_collected);
	if (player->collectibles_collected != NULL)
		free(player->collectibles_collected); // free problem (munchunk pointer error)
	if (player->escaped != NULL)
		free(player->escaped);
	if (player != NULL)
		free(player);
}