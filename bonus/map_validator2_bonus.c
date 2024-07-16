/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:48:03 by maxliew           #+#    #+#             */
/*   Updated: 2024/07/16 13:52:58 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_bool	is_pathable(t_map *map, t_player sim, t_bool path_found)
{
	t_bool	path_up_found;
	t_bool	path_left_found;
	t_bool	path_right_found;
	t_bool	path_down_found;

	path_up_found = FALSE;
	path_left_found = FALSE;
	path_right_found = FALSE;
	path_down_found = FALSE;
	path_up_found = path_up(map, sim, path_found);
	path_left_found = path_left(map, sim, path_found);
	path_right_found = path_right(map, sim, path_found);
	path_down_found = path_down(map, sim, path_found);
	if (path_up_found == TRUE || path_left_found == TRUE || \
			path_right_found == TRUE || path_down_found == TRUE)
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
			*sim.collects_collected += 1;
		map->lines[sim.y][sim.x] = WALL;
		if (*sim.collects_collected == map->collectibles_count && \
			*(sim.escaped) == TRUE)
			return (TRUE);
		path_found = is_pathable(map, sim, path_found);
	}
	return (path_found);
}
