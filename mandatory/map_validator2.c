/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:48:03 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/20 12:05:33 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	is_pathable(t_map *map, t_player sim, t_bool path_found)
{
	t_bool	path_up_found = FALSE;
	t_bool	path_left_found = FALSE;
	t_bool	path_right_found = FALSE;
	t_bool	path_down_found = FALSE;
	
	path_up_found = path_up(map, sim, path_found);
	path_left_found = path_left(map, sim, path_found);
	path_right_found = path_right(map, sim, path_found);
	path_down_found = path_down(map, sim, path_found);
	if (path_up_found == TRUE || path_left_found == TRUE || path_right_found == TRUE || path_down_found == TRUE)
		return (TRUE);
	return (FALSE);
}

t_bool	path_conds(t_map *map, t_player sim, t_bool path_found)
{
	if (map->lines[sim.y][sim.x] != WALL)
	{
		if (map->lines[sim.y][sim.x] == EXIT)
			*(sim.escaped) = TRUE;
		if (map->lines[sim.y][sim.x] == COLLECTIBLE)
		{
			*sim.collectibles_collected += 1;
			ft_printf("sim.collectibles_collected: %p | sim.collectibles_collected: %i\n", sim.collectibles_collected, *sim.collectibles_collected);
		}
		map->lines[sim.y][sim.x] = WALL;
		if (*sim.collectibles_collected == map->collectibles_count && *(sim.escaped) == TRUE)
			return (TRUE);
		path_found = is_pathable(map, sim, path_found);
	}
	return (path_found);
}
