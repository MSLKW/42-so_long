/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_manager_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 09:29:07 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/29 22:42:20 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	movement_manager(int keycode, t_data *data)
{
	if (keycode == W)
		move_player(data, 0, -1);
	else if (keycode == A)
	{
		data->player->direction = LEFT;
		move_player(data, -1, 0);
	}
	else if (keycode == S)
		move_player(data, 0, 1);
	else if (keycode == D)
	{
		data->player->direction = RIGHT;
		move_player(data, 1, 0);
	}
	move_enemy(data);
}

void	move_player(t_data *data, int x, int y)
{
	char	tile;

	if (data->map->lines[data->player->y + y][data->player->x + x] == WALL)
		return ;
	else if (data->map->lines[data->player->y + y][data->player->x + x] == \
			EXIT && *data->player->escaped == FALSE)
		return ;
	data->map->lines[data->player->y][data->player->x] = EMPTY;
	data->player->y += y;
	data->player->x += x;
	tile = data->map->lines[data->player->y][data->player->x];
	if (tile == COLLECTIBLE)
	{
		*data->player->collectibles_collected += 1;
		if (*data->player->collectibles_collected == \
				data->map->collectibles_count)
			*data->player->escaped = TRUE;
	}
	if (tile == EXIT && *data->player->escaped == TRUE)
		game_over(data);
	data->map->lines[data->player->y][data->player->x] = PLAYER;
	data->player->moves_count++;
	ft_printf("Moves: %i\n", data->player->moves_count);
	put_map(data);
}

void	move_enemy(t_data *data)
{
	t_enemies *head;

	head = data->enemies;
	while (head != NULL)
	{
		// move enemy
		head = head->next;
	}
}