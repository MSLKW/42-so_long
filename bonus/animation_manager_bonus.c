/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_manager_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:56:05 by maxliew           #+#    #+#             */
/*   Updated: 2024/07/16 10:01:44 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	update_tick(t_data *data)
{
	static int	loops = 0;

	if (loops >= 1350)
	{
		loops = 0;
		data->tick++;
		next_frame(&data->textures->texture_list);
		put_map(data);
		if (data->tick == 10 || data->tick == 20)
		{
			move_enemies(data);
		}
	}
	if (data->tick >= TICK_RATE)
		data->tick = 0;
	loops++;
	return (0);
}

void	next_frame(t_list **texture_list)
{
	int frame_delay;
	t_list *head;
	t_texture *texture;

	head = *texture_list;
	while (head != NULL)
	{
		texture = head->content;
		if (texture == NULL)
			return ;
		if (texture->is_playing == TRUE)
		{
			frame_delay = TICK_RATE / texture->total_frames;
			// if (texture->is_looping == FALSE && texture->reset_flag == FALSE)
			// {
			// 	texture->reset_flag = TRUE;
			// 	data->tick = 0;
			// 	// maybe put the tick system in the texture so every texture has its own separate tick system
			// }
			// texture->current_frame = round_up((float)data->tick / (float)frame_delay) - 1;
			// can play anim when data->tick is at 20, so it immediately turns greenw ithout anim
			// solution: use current_frame++ each tick and loop it., figure out frame delay inbetween

			if (texture->frame_delay_count < frame_delay)
			{
				texture->frame_delay_count++;
				head = head->next;
				continue;
			}
			texture->current_frame++;
			texture->frame_delay_count = 0;
			if (texture->is_looping == TRUE && texture->current_frame >= texture->total_frames)
				texture->current_frame = 0;
			if (texture->is_looping == FALSE && texture->current_frame >= texture->total_frames - 1)
				texture->is_playing = FALSE;
		}		
		head = head->next;
	}
}

int	round_up(float num)
{
	if ((int)num == num)
	{
		return ((int)num);
	}
	return ((int)(num + 1));
}