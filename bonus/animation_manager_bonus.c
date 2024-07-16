/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_manager_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:56:05 by maxliew           #+#    #+#             */
/*   Updated: 2024/07/16 13:15:30 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	update_tick(t_data *data)
{
	static int	loops = 0;

	if (loops >= LOOP_RATE)
	{
		loops = 0;
		data->tick++;
		next_frame(&data->textures->texture_list);
		put_map(data);
		if (data->tick % 10 == 0)
			move_enemies(data);
	}
	if (data->tick >= TICK_RATE)
		data->tick = 0;
	loops++;
	return (0);
}

void	next_frame(t_list **texture_list)
{
	t_list		*head;
	t_texture	*texture;

	head = *texture_list;
	while (head != NULL)
	{
		texture = head->content;
		if (texture == NULL)
			return ;
		update_current_frame(texture);
		head = head->next;
	}
}

void	update_current_frame(t_texture *texture)
{
	int	frame_delay;

	if (texture->is_playing == FALSE)
		return ;
	frame_delay = TICK_RATE / texture->total_frames;
	if (texture->frame_delay_count < frame_delay)
	{
		texture->frame_delay_count++;
		return ;
	}
	texture->current_frame++;
	texture->frame_delay_count = 0;
	if (texture->is_looping == TRUE && \
		texture->current_frame >= texture->total_frames)
		texture->current_frame = 0;
	if (texture->is_looping == FALSE && \
		texture->current_frame >= texture->total_frames - 1)
		texture->is_playing = FALSE;
}
