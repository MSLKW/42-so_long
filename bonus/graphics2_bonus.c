/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:39:51 by maxliew           #+#    #+#             */
/*   Updated: 2024/07/16 14:26:35 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_texture	*make_manual_texture(t_data *data, char *name, char *file_name)
{
	t_texture	*texture;

	texture = make_texture(name, make_frames(data, file_name));
	texture->is_looping = FALSE;
	texture->is_playing = FALSE;
	return (texture);
}

t_texture	*make_texture(char *name, t_list *frames)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	if (texture == NULL)
		return (NULL);
	texture->frames = frames;
	texture->total_frames = ft_lstsize(frames);
	texture->name = name;
	texture->is_looping = TRUE;
	texture->is_playing = TRUE;
	texture->current_frame = 0;
	texture->frame_delay_count = 0;
	return (texture);
}

t_texture	*get_texture(t_list *texture_list, char *name)
{
	t_list		*head;
	t_texture	*texture;

	head = texture_list;
	while (head != NULL)
	{
		texture = head->content;
		if (ft_strncmp(texture->name, name, ft_strlen(texture->name)) == 0)
			return (texture);
		head = head->next;
	}
	return (NULL);
}

t_list	*make_frames(t_data *data, char *file_name)
{
	t_list	*frames;
	t_frame	*frame;
	int		index;
	char	*itoa_index;
	char	*full_filename;

	frame = make_frame(data, file_name);
	if (frame == NULL)
		error_exit("Required texture not found");
	frames = ft_lstnew(frame);
	index = 1;
	while (frame != NULL)
	{
		itoa_index = ft_itoa(index);
		full_filename = ft_strjoin(file_name, itoa_index);
		frame = make_frame(data, full_filename);
		if (frame != NULL)
			ft_lstadd_back(&frames, ft_lstnew(frame));
		index++;
		free(itoa_index);
		free(full_filename);
	}
	return (frames);
}

t_frame	*make_frame(t_data *data, char *file_name)
{
	t_frame	*frame;
	char	*full_file_name;

	frame = malloc(sizeof(t_frame));
	if (frame == NULL)
		return (NULL);
	full_file_name = ft_strjoin(file_name, ".xpm");
	frame->image = mlx_xpm_file_to_image(data->mlx, full_file_name, \
		&data->textures->width, &data->textures->height);
	if (frame->image == NULL)
	{
		free(frame);
		free(full_file_name);
		return (NULL);
	}
	frame->file_name = full_file_name;
	return (frame);
}
