/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:48:03 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/14 17:35:14 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	is_pathable(t_map *map, t_player sim, t_bool path_found)
{
	t_bool	path_up_found;
	t_bool	path_left_found;
	t_bool	path_right_found;
	t_bool	path_down_found;

	path_up_found = path_up(map, sim, path_found);
	path_left_found = path_left(map, sim, path_found);
	path_right_found = path_right(map, sim, path_found);
	path_down_found = path_down(map, sim, path_found);
	if (path_up_found == TRUE || path_left_found == TRUE || path_right_found == TRUE || path_down_found == TRUE)
		return (TRUE);
	return (FALSE);
}

t_bool	path_up(t_map *map, t_player sim, t_bool path_found)
{
	if (map->map_lines[sim.y - 1][sim.x] != '1')
	{
		if (map->map_lines[sim.y - 1][sim.x] == 'E' && sim.collectibles_collected == map->collectibles_count)
			return (TRUE);
	}
	else
	{
		sim.y--;
		path_found = is_pathable(map, sim, path_found);
	}
	return (path_found);
}

t_bool	path_down(t_map *map, t_player sim, t_bool path_found)
{
	if (map->map_lines[sim.y + 1][sim.x] != '1')
	{
		if (map->map_lines[sim.y + 1][sim.x] == 'E' && sim.collectibles_collected == map->collectibles_count)
			return (TRUE);
	}
	else
	{
		sim.y++;
		path_found = is_pathable(map, sim, path_found);
	}
	return (path_found);
}

t_bool	path_left(t_map *map, t_player sim, t_bool path_found)
{
	if (map->map_lines[sim.y][sim.x - 1] != '1')
	{
		if (map->map_lines[sim.y][sim.x - 1] == 'E' && sim.collectibles_collected == map->collectibles_count)
			return (TRUE);
	}
	else
	{
		sim.x--;
		path_found = is_pathable(map, sim, path_found);
	}
	return (path_found);
}

t_bool	path_right(t_map *map, t_player sim, t_bool path_found)
{
	if (map->map_lines[sim.y][sim.x + 1] != '1')
	{
		if (map->map_lines[sim.y][sim.x + 1] == 'E' && sim.collectibles_collected == map->collectibles_count)
			return (TRUE);
	}
	else
	{
		sim.x++;
		path_found = is_pathable(map, sim, path_found);
	}
	return (path_found);
}