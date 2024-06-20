/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:22:52 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/20 12:12:32 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_data(t_data *data)
{
	free_textures(data->textures);
	free_map(data->map);
	free_player(data->player);
	// free(data->mlx);
	// free(data->window);
}

void	free_textures(t_textures *textures)
{
	if (textures->wall != NULL)
		free(textures->wall);
	if (textures->player != NULL)
		free(textures->player);
	if (textures->collectible != NULL)
		free(textures->collectible);
	if (textures->background != NULL)
		free(textures->background);
	if (textures->exit_closed != NULL)
		free(textures->exit_closed);
	if (textures->exit_open != NULL)
		free(textures->exit_open);
	if (textures != NULL)
		free(textures);
}

void	free_map(t_map *map)
{
	if (map->map_file_path != NULL)
		free(map->map_file_path);
	if (map->lines != NULL)
		free(map->lines);
	if (map != NULL)
		free(map);
}

void	free_player(t_player *player)
{
	// ft_printf("%p\n", player->collectibles_collected);
	// if (player->collectibles_collected != NULL)
	// 	free(player->collectibles_collected); // free problem (munchunk pointer error)
	if (player->escaped != NULL)
		free(player->escaped);
	if (player != NULL)
		free(player);
}