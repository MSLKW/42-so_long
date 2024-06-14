/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:32:04 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/14 13:30:34 by maxliew          ###   ########.fr       */
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
	}
	return (TRUE);
}

t_player	*get_position(t_map *map)
{
	t_player	*player;

	player = malloc(sizeof(player));
	if (player == NULL)
		return (NULL);
	player->x = 0;
	player->y = 0;
	while (player->y < map->height)
	{
		while (player->x < map->width)
		{
			if (map->map_lines[player->y][player->x] == 'P')
				return (player);
			player->x++;
		}
		player->y++;
	}
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
	while ((line = map->map_lines[y]) != NULL)
	{
		while (line[x] != '\0')
		{
			if (line[x] == 'C')
				map->collectibles_count++;
			else if (line[x] == 'E')
				map->exits_count++;
			else if (line[x] == 'P')
				map->players_count++;
			x++;
		}
		y++;
	}
}

void	assign_map_size(t_map *map)
{
	int	height;
	int	width;
	char	*first_line;

	height = 0;
	width = 0;
	while (map->map_lines[height] != NULL)
		height++;
	first_line = map->map_lines[0];
	if (first_line == NULL)
		error_exit("Invalid map: No content");
	while(first_line[width] != '\0')
		width++;
	map->height = height;
	map->width = width;
}