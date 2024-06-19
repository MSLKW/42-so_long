/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:25:32 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/19 15:22:47 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	is_map_valid(t_map *map)
{
	t_player	*sim;

	if (is_rectangle(map) == FALSE)
		error_exit("Invalid map: Map is not rectangle");
	else if (is_only_one(map) == FALSE)
		error_exit("Invalid map: Map has no collectibles or too many exits or \
			too many players");
	else if (is_walled(map) == FALSE)
		error_exit("Invalid map: Map is not walled off");
	sim = get_player_pos(map);
	if (sim == NULL)
		error_exit("Invalid map: Player not found");
	else if (is_pathable(map, *sim, FALSE) == FALSE)
		error_exit("Invalid map: No path to exit found");
	return (TRUE);
}

t_bool	is_rectangle(t_map *map)
{
	int	index;

	index = 0;
	while (map->map_lines[index] != NULL)
	{
		if (ft_strlen(map->map_lines[index]) != map->width)
			return (FALSE);
		index++;
	}
	return (TRUE);
}

t_bool	is_only_one(t_map *map)
{
	if (map->collectibles_count <= 0 || map->exits_count != 1 || map->players_count != 1)
		return (FALSE);
	return (TRUE);
}

t_bool	is_walled(t_map *map)
{
	int		y;
	char	*line;

	if (is_all_same(map->map_lines[0], '1') == FALSE || \
		is_all_same(map->map_lines[map->height - 1], '1') == FALSE)
		return (FALSE);
	y = 0;
	while ((line = map->map_lines[y]) != NULL)
	{
		if (line[0] != '1' || line[map->width - 1] != '1')
			return (FALSE);
		y++;
	}
	return (TRUE);
}
