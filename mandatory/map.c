/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 09:06:20 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/20 11:46:56 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*get_map(char *map_file_path)
{
	t_map	*map;
	char	**map_lines;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map_lines = get_map_lines(map_file_path);
	map->lines = ft_dupe_map_lines(map_lines);
	if (map_lines == NULL || map->lines == NULL)
	{
		if (map_lines != NULL)
			free(map_lines);
		free_map(map);
		return (NULL);
	}
	map->map_file_path = ft_strdup(map_file_path);
	assign_map_size(map);
	assign_map_counts(map);
	is_map_valid(map);
	free(map->lines);
	map->lines = ft_dupe_map_lines(map_lines);
	free(map_lines);
	return (map);
}

char	**get_map_lines(char *map_file_path)
{
	int		fd;
	char	*text_buf;
	char	**map_lines;

	fd = open(map_file_path, O_RDONLY);
	if (fd == -1)
		error_exit("Invalid map: Invalid file path");
	text_buf = ft_calloc(INT_MAX / 4, sizeof(char)); // INT MAX? maybe make this more efficient by SOMEHOW counting before allocating, can use gnl
	if (text_buf == NULL)
		error_exit("Invalid map: Unable to allocate memory");
	read(fd, text_buf, INT_MAX / 4);
	map_lines = ft_split(text_buf, '\n');
	free(text_buf);
	return (map_lines);
}

char	**ft_dupe_map_lines(char **map_lines)
{
	char	**dupe_map_lines;
	int		index;

	if (map_lines == NULL)
		return (NULL);
	dupe_map_lines = malloc(sizeof(char *) * ft_strlist_count(map_lines));
	if (dupe_map_lines == NULL)
		return (NULL);
	index = 0;
	while (map_lines[index] != NULL)
	{
		dupe_map_lines[index] = ft_strdup(map_lines[index]);
		index++;
	}
	dupe_map_lines[index] = NULL;
	return (dupe_map_lines);
}
