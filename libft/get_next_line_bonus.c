/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:58:46 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/14 10:35:43 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*joined_str;
	size_t	joined_str_size;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	joined_str_size = ft_strlen(s1) + ft_strlen(s2) + NULL_SIZE;
	joined_str = ft_calloc(joined_str_size, sizeof(char));
	if (joined_str == NULL)
		return (NULL);
	ft_strlcpy(joined_str, s1, ft_strlen(s1) + NULL_SIZE);
	ft_strlcat(joined_str, s2, joined_str_size);
	free(s1);
	return (joined_str);
}

char	*append_buff(int fd, char *line)
{
	char	*buffer;
	ssize_t	size_read;

	buffer = ft_calloc(BUFFER_SIZE + NULL_SIZE, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	size_read = 1;
	while (ft_strchr(line, '\n') == NULL)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		else if (size_read == 0)
			break ;
		buffer[size_read] = '\0';
		line = ft_strjoin_gnl(line, buffer);
		if (line == NULL)
			break ;
	}
	free(buffer);
	return (line);
}

char	*clean_buff_line(char *buff_line)
{
	int		index;
	char	*clean_line;

	index = 0;
	while (buff_line[index] != '\n' && buff_line[index] != '\0')
		index++;
	if (buff_line[index] == '\0' && index == 0)
		return (NULL);
	clean_line = ft_calloc(index + 2, sizeof(char));
	if (clean_line == NULL)
		return (NULL);
	ft_strlcpy(clean_line, buff_line, index + 2);
	return (clean_line);
}

char	*set_buff_bit(char *buff_line)
{
	int		index;
	int		buff_bits_count;
	int		buff_bits_index;
	char	*buff_bits;

	index = 0;
	while (buff_line[index] != '\n' && buff_line[index] != '\0')
		index++;
	if (buff_line[index] == '\0')
	{
		free(buff_line);
		return (NULL);
	}
	buff_bits_count = 0;
	while (buff_line[index + buff_bits_count] != '\0')
		buff_bits_count++;
	buff_bits = ft_calloc(buff_bits_count + NULL_SIZE, sizeof(char));
	if (buff_bits == NULL)
		return (NULL);
	buff_bits_index = 0;
	while (buff_bits_index < buff_bits_count)
		buff_bits[buff_bits_index++] = buff_line[++index];
	buff_bits[buff_bits_index] = '\0';
	free(buff_line);
	return (buff_bits);
}

char	*get_next_line(int fd)
{
	static char	*buff_line[512];
	char		*next_line;

	if (fd < 0 || fd > 511 || BUFFER_SIZE < 0)
		return (NULL);
	if (buff_line[fd] == NULL)
	{
		buff_line[fd] = ft_calloc(NULL_SIZE, sizeof(char));
		if (buff_line[fd] == NULL)
			return (NULL);
	}
	buff_line[fd] = append_buff(fd, buff_line[fd]);
	if (buff_line[fd] == NULL)
		return (NULL);
	next_line = clean_buff_line(buff_line[fd]);
	buff_line[fd] = set_buff_bit(buff_line[fd]);
	return (next_line);
}
