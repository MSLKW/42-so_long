/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator3_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:58:43 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/29 21:35:44 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_bool	path_up(t_map *map, t_player sim, t_bool path_found)
{
	if (sim.y > 0)
		sim.y--;
	path_found = path_conds(map, sim, path_found);
	return (path_found);
}

t_bool	path_down(t_map *map, t_player sim, t_bool path_found)
{
	if (sim.y < map->height)
		sim.y++;
	path_found = path_conds(map, sim, path_found);
	return (path_found);
}

t_bool	path_left(t_map *map, t_player sim, t_bool path_found)
{
	if (sim.x > 0)
		sim.x--;
	path_found = path_conds(map, sim, path_found);
	return (path_found);
}

t_bool	path_right(t_map *map, t_player sim, t_bool path_found)
{
	if (sim.x < map->width)
		sim.x++;
	path_found = path_conds(map, sim, path_found);
	return (path_found);
}
