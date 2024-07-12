/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 22:06:32 by maxliew           #+#    #+#             */
/*   Updated: 2024/07/12 11:34:28 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_list	*make_enemies(t_map *map)
{
	t_list	*enemies;
	int 		x;
	int			y;
	char		*line;

	enemies = ft_lstnew(NULL);
	y = 0;
	line = map->lines[y];
	while (line != NULL)
	{
		x = 0;
		while (line[x] != '\0')
		{
			if(line[x] == ENEMY)
				ft_lstadd_back(&enemies, ft_lstnew(make_enemy(x, y)));
			x++;
		}
		y++;
		line = map->lines[y];
	}
	if (ft_lstsize(enemies) == 1)
		return (NULL);
	return (enemies);
}

t_enemy	*make_enemy(int x, int y)
{
	t_enemy	*enemy;
	
	enemy = malloc(sizeof(t_enemy));
	if (enemy == NULL)
		return (NULL);
	enemy->x = x;
	enemy->y = y;
	enemy->direction = (rand() % 4) + 1; // is it actually being random?
	enemy->move_attempts = 0;
	enemy->is_on_collectible = FALSE;
	assign_enemy_dir_vector(enemy);
	return (enemy);
}

void	assign_enemy_dir_vector(t_enemy *enemy)
{
	enemy->direction_x = 0;
	enemy->direction_y = 0;	
	if (enemy->direction == UP)
		enemy->direction_y = -1;
	else if (enemy->direction == DOWN)
		enemy->direction_y = 1;	
	else if (enemy->direction == LEFT)
		enemy->direction_x = -1;
	else if (enemy->direction == RIGHT)
		enemy->direction_x = 1;
}

void	flip_enemy_dir(t_enemy *enemy)
{
	if (enemy->direction == UP)
		enemy->direction = DOWN;
	else if (enemy->direction == DOWN)
		enemy->direction = UP;
	else if (enemy->direction == LEFT)
		enemy->direction = RIGHT;
	else if (enemy->direction == RIGHT)
		enemy->direction = LEFT;
}

void	rotate_enemy_dir(t_enemy *enemy)
{
	if (enemy->direction == UP)
		enemy->direction = RIGHT;
	else if (enemy->direction == DOWN)
		enemy->direction = LEFT;
	else if (enemy->direction == LEFT)
		enemy->direction = UP;
	else if (enemy->direction == RIGHT)
		enemy->direction = DOWN;
}