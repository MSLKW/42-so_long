/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:32:04 by maxliew           #+#    #+#             */
/*   Updated: 2024/07/12 11:35:17 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	is_all_same(char *str, char c)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] != c)
			return (FALSE);
		index++;
	}
	return (TRUE);
}

t_player	*make_player(t_map *map)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (player == NULL)
		return (NULL);
	player->collectibles_collected = malloc(sizeof(int *));
	player->escaped = malloc(sizeof(t_bool));
	if (player->collectibles_collected == NULL || player->escaped == NULL)
		return (NULL);
	player->moves_count = 0;
	*player->collectibles_collected = 0;
	*player->escaped = FALSE;
	player->direction = RIGHT;
	if (assign_player_pos(player, map) == FALSE)
		return (NULL);
	return (player);
}

t_bool	assign_player_pos(t_player *player, t_map *map)
{
	player->y = 0;
	while (player->y < map->height)
	{
		player->x = 0;
		while (player->x < map->width)
		{
			if (map->lines[player->y][player->x] == PLAYER)
				return (TRUE);
			player->x++;
		}
		player->y++;
	}
	return (FALSE);
}

void	assign_map_counts(t_map *map)
{
	int		y;
	int		x;
	char	*line;

	map->collectibles_count = 0;
	map->exits_count = 0;
	map->players_count = 0;
	y = 0;
	line = map->lines[y];
	while (line != NULL)
	{
		x = 0;
		while (line[x] != '\0')
		{
			if (line[x] == COLLECTIBLE)
				map->collectibles_count++;
			else if (line[x] == EXIT)
				map->exits_count++;
			else if (line[x] == PLAYER)
				map->players_count++;
			x++;
		}
		y++;
		line = map->lines[y];
	}
}

void	assign_map_size(t_map *map)
{
	int		height;
	int		width;
	char	*first_line;

	height = 0;
	width = 0;
	while (map->lines[height] != NULL)
		height++;
	first_line = map->lines[0];
	if (first_line == NULL)
		error_exit("Invalid map: No content");
	while (first_line[width] != '\0')
		width++;
	map->height = height;
	map->width = width;
}
