/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:22:52 by maxliew           #+#    #+#             */
/*   Updated: 2024/07/16 13:52:58 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_data(t_data *data)
{
	free_map(data->map);
	free_player(data->player);
	free_enemies(data->enemies);
	mlx_destroy_window(data->mlx, data->window);
	if (__APPLE__ == 0)
		free(data->mlx);
}

// void	destroy_texture(t_data *data, t_texture *texture)
// {
// 	t_list *head;
// 	t_list *temp;
// 	t_frame *frame;

// 	head = texture->frames;
// 	while (head != NULL)
// 	{
// 		frame = head->content;
// 		free(frame->file_name);
// 		mlx_destroy_image(data->mlx, frame->image);
// 		free(frame);
// 		temp = head->next;
// 		free(head);
// 		head = temp;
// 	}
// 	free(texture);
// }

// void	destroy_textures(t_data *data, t_textures *textures)
// {
// 	t_list	*head;

// 	if (textures == NULL)
// 		return ;
// 	head = textures->texture_list;
// 	while (head != NULL)
// 	{
// 		destroy_texture(data, head->content);
// 		head = head->next;
// 	}
// 	free(textures->texture_list);
// 	free(textures);
// }

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
	free(player->collects_collected);
	free(player->escaped);
	free(player);
}

void	free_enemies(t_list *enemies)
{
	t_list	*head;
	t_list	*temp;
	t_enemy	*enemy;

	head = enemies;
	while (head != NULL)
	{
		enemy = head->content;
		free(enemy);
		temp = head;
		head = head->next;
		free(temp);
	}
}
