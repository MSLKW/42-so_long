/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 09:06:20 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/25 14:30:27 by maxliew          ###   ########.fr       */
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
			free_str_list(map_lines);
		free_map(map);
		return (NULL);
	}
	map->map_file_path = ft_strdup(map_file_path);
	assign_map_size(map);
	assign_map_counts(map);
	is_map_valid(map);
	free_str_list(map->lines);
	map->lines = ft_dupe_map_lines(map_lines);
	free_str_list(map_lines);
	return (map);
}

int		get_map_height(char *map_file_path)
{
	int		fd;
	int		height;
	char	*map_line;
	
	fd = open(map_file_path, O_RDONLY);
	if (fd == -1)
		error_exit("Invalid map: Invalid file path");
	map_line = get_next_line(fd);
	free(map_line);
	height = 0;
	if (map_line == NULL)
		error_exit("Invalid map: No content in file");
	while (map_line != NULL)
	{
		height++;
		map_line = get_next_line(fd);
		free(map_line);
	}
	return (height);
}

char	**get_map_lines(char *map_file_path, int map_height)
{
	int		fd;
	char	**map_lines;
	int		index;

	fd = open(map_file_path, O_RDONLY);
	if (fd == -1)
		error_exit("Invalid map: Invalid file path");
	map_lines = ft_calloc(map_height, sizeof(char *));
	while (index < map_height)
	{
		map_lines[index] = get_next_line(fd);
		map_height--;
	}
	close(fd);
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
