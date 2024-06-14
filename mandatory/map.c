/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 09:06:20 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/14 13:28:55 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*get_map(char *map_file_path)
{
	t_map	*map;
	int		fd;
	char	*text_buf;
	char	**map_lines;

	fd = open(map_file_path, O_RDONLY);
	if (fd == -1)
		error_exit("Invalid map: file path");
	map = malloc(sizeof(t_map));
	text_buf = ft_calloc(INT_MAX / 4, sizeof(char)); // INT MAX? maybe make this more efficient by SOMEHOW counting before allocating, can use gnl
	if (map == NULL || text_buf == NULL)
		error_exit("Invalid map: Unable to allocate memory");
	read(fd, text_buf, INT_MAX / 4);
	map_lines = ft_split(text_buf, '\n');
	if (map_lines == NULL)
	{
		free(map);
		free(text_buf);
		error_exit("Invalid map: Unable to split");
	}
	map->map_lines = map_lines;
	assign_map_size(map);
	assign_map_counts(map);
	return (map);
}
