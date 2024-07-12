/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 09:06:20 by maxliew           #+#    #+#             */
/*   Updated: 2024/07/12 11:35:45 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_map	*make_map(char *map_file_path)
{
	t_map	*map;
	int		map_height;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map_height = get_map_height(map_file_path);
	map->lines = make_map_lines(map_file_path, map_height);
	if (map->lines == NULL)
	{
		free_map(map);
		return (NULL);
	}
	map->map_file_path = ft_strdup(map_file_path);
	assign_map_size(map);
	assign_map_counts(map);
	is_map_valid(map);
	free_str_list(map->lines);
	map->lines = make_map_lines(map_file_path, map_height);
	return (map);
}

int	get_map_height(char *map_file_path)
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

char	**make_map_lines(char *map_file_path, int map_height)
{
	int		fd;
	char	**map_lines;
	int		index;
	char	*trim_char;

	fd = open(map_file_path, O_RDONLY);
	if (fd == -1)
		error_exit("Invalid map: Invalid file path");
	map_lines = ft_calloc(map_height + NULL_SIZE, sizeof(char *));
	if (map_lines == NULL)
		return (NULL);
	index = 0;
	while (index < map_height)
	{
		map_lines[index] = get_next_line(fd);
		trim_char = &(map_lines[index][ft_strlen(map_lines[index]) - 1]);
		if (*trim_char == '\n')
			*trim_char = '\0';
		index++;
	}
	map_lines[index] = NULL;
	close(fd);
	return (map_lines);
}
