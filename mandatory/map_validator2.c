/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:48:03 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/19 15:46:23 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	is_pathable(t_map *map, t_player sim, t_bool path_found)
{
	t_bool	path_up_found = FALSE;
	t_bool	path_left_found = FALSE;
	t_bool	path_right_found = FALSE;
	t_bool	path_down_found = FALSE;
	
	ft_printf("Starting path cycle | x: %i y: %i\n",  sim.x, sim.y);
	path_up_found = path_up(map, sim, path_found);
	path_left_found = path_left(map, sim, path_found);
	path_right_found = path_right(map, sim, path_found);
	path_down_found = path_down(map, sim, path_found);
	if (path_up_found == TRUE || path_left_found == TRUE || path_right_found == TRUE || path_down_found == TRUE)
		return (TRUE);
	ft_printf("Completed path cycle | x: %i y: %i | sim.collectibles_collected: %i | path_up_found: %i path_left_found: %i path_right_found: %i path_down_found: %i\n", sim.x, sim.y, sim.collectibles_collected, path_up_found, path_left_found, path_right_found, path_down_found);
	return (FALSE);
}

t_bool	path_conds(t_map *map, t_player sim, t_bool path_found) // just need to do | able to access exit, able to access all collectibles, then VALID
{
	if (map->map_lines[sim.y][sim.x] != '1')
	{
		if (map->map_lines[sim.y][sim.x] == 'E' && sim.collectibles_collected == map->collectibles_count)
			return (TRUE);
		if (map->map_lines[sim.y][sim.x] == 'C')
			sim.collectibles_collected++;
		map->map_lines[sim.y][sim.x] = '1';
		path_found = is_pathable(map, sim, path_found);
	}
	return (path_found);
}
