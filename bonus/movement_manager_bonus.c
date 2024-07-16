/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_manager_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 09:29:07 by maxliew           #+#    #+#             */
/*   Updated: 2024/07/16 14:06:12 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	movement_manager(int keycode, t_data *data)
{
	if (keycode == W)
	{
		data->player->direction = UP;
		move_player(data, 0, -1);
	}
	else if (keycode == A)
	{
		data->player->direction = LEFT;
		move_player(data, -1, 0);
	}
	else if (keycode == S)
	{
		data->player->direction = DOWN;
		move_player(data, 0, 1);
	}
	else if (keycode == D)
	{
		data->player->direction = RIGHT;
		move_player(data, 1, 0);
	}
	get_texture(data->textures->texture_list, "player")->current_frame \
		= data->player->direction - 1;
	put_map(data);
}

void	move_player(t_data *data, int x, int y)
{
	char	*look_at_tile;

	look_at_tile = &data->map->lines[data->player->y + y][data->player->x + x];
	if (*look_at_tile == ENEMY)
		game_over(data);
	if (*look_at_tile == WALL || \
		(*look_at_tile == EXIT && *data->player->escaped == FALSE))
		return ;
	data->map->lines[data->player->y][data->player->x] = EMPTY;
	if (*look_at_tile == COLLECTIBLE)
	{
		*data->player->collects_collected += 1;
		if (*data->player->collects_collected == data->map->collectibles_count)
		{
			*data->player->escaped = TRUE;
			get_texture(data->textures->texture_list, \
				"exit")->is_playing = TRUE;
		}
	}
	if (*look_at_tile == EXIT && *data->player->escaped == TRUE)
		game_over(data);
	*look_at_tile = PLAYER;
	data->player->x += x;
	data->player->y += y;
	data->player->moves_count++;
}

void	move_enemies(t_data *data)
{
	t_list	*head;

	head = data->enemies;
	while (head != NULL)
	{
		move_enemy(data, head->content);
		head = head->next;
	}
}

void	move_enemy(t_data *data, t_enemy *enemy)
{
	char	*look_at_tile;
	char	*current_tile;

	if (enemy == NULL || enemy->move_attempts == 4)
		return ;
	assign_enemy_dir_vector(enemy);
	look_at_tile = &data->map->lines[enemy->y + \
		enemy->direction_y][enemy->x + enemy->direction_x];
	if (*look_at_tile == WALL || *look_at_tile == ENEMY || \
		*look_at_tile == EXIT)
	{
		if (enemy->move_attempts == 1)
			rotate_enemy_dir(enemy);
		else if (enemy->move_attempts != 3)
			flip_enemy_dir(enemy);
		enemy->move_attempts++;
		move_enemy(data, enemy);
		return ;
	}
	else if (*look_at_tile == PLAYER)
		game_over(data);
	enemy->move_attempts = 0;
	chk_enemy_col(enemy, &data->map->lines[enemy->y][enemy->x], look_at_tile);
	enemy->x += enemy->direction_x;
	enemy->y += enemy->direction_y;
}

void	chk_enemy_col(t_enemy *enemy, char *current_tile, char *look_at_tile)
{
	if (enemy->is_on_collectible == TRUE)
	{
		*current_tile = COLLECTIBLE;
		enemy->is_on_collectible = FALSE;
	}
	else if (enemy->is_on_collectible == FALSE)
		*current_tile = EMPTY;
	if (*look_at_tile == COLLECTIBLE)
		enemy->is_on_collectible = TRUE;
	*look_at_tile = ENEMY;
}
