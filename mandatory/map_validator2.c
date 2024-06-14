/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:48:03 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/14 22:32:51 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	is_pathable(t_map *map, t_player sim, t_bool path_found, int no_path)
{
	t_bool	path_up_found = FALSE;
	t_bool	path_left_found = FALSE;
	t_bool	path_right_found = FALSE;
	t_bool	path_down_found = FALSE;
	
	ft_printf("Starting path cycle | x: %i y: %i\n",  sim.x, sim.y);
	if (no_path != NO_UP)
		path_up_found = path_up(map, sim, path_found);
	else if (no_path != NO_LEFT)
		path_left_found = path_left(map, sim, path_found);
	else if (no_path != NO_RIGHT)
		path_right_found = path_right(map, sim, path_found);
	else if (no_path != NO_DOWN)
		path_down_found = path_down(map, sim, path_found);
	if (path_up_found == TRUE || path_left_found == TRUE || path_right_found == TRUE || path_down_found == TRUE)
		return (TRUE);
	ft_printf("Completed path cycle\n");
	return (FALSE);
}

t_bool	path_up(t_map *map, t_player sim, t_bool path_found)
{
	if (sim.y > 0)
		sim.y--;
	if (map->map_lines[sim.y - 1][sim.x] != '1')
	{
		if (map->map_lines[sim.y - 1][sim.x] == 'E' && sim.collectibles_collected == map->collectibles_count)
			return (TRUE);
		is_pathable(map, sim, path_found, NO_DOWN);
	}
	return (path_found);
}

t_bool	path_down(t_map *map, t_player sim, t_bool path_found)
{
	if (sim.y < map->height)
		sim.y++;
	if (map->map_lines[sim.y][sim.x] != '1')
	{
		if (map->map_lines[sim.y][sim.x] == 'E' && sim.collectibles_collected == map->collectibles_count)
			return (TRUE);
		path_found = is_pathable(map, sim, path_found, NO_UP);
	}
	return (path_found);
}

t_bool	path_left(t_map *map, t_player sim, t_bool path_found)
{
	if (sim.x > 0)
		sim.x--;
	if (map->map_lines[sim.y][sim.x] != '1')
	{
		if (map->map_lines[sim.y][sim.x] == 'E' && sim.collectibles_collected == map->collectibles_count)
			return (TRUE);
		path_found = is_pathable(map, sim, path_found, NO_RIGHT);
	}
	return (path_found);
}

t_bool	path_right(t_map *map, t_player sim, t_bool path_found)
{
	if (sim.x < map->width)
		sim.x++;
	if (map->map_lines[sim.y][sim.x] != '1')
	{
		if (map->map_lines[sim.y][sim.x] == 'E' && sim.collectibles_collected == map->collectibles_count)
			return (TRUE);
		path_found = is_pathable(map, sim, path_found, NO_LEFT);
	}
	return (path_found);
}