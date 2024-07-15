/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_manager_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:56:05 by maxliew           #+#    #+#             */
/*   Updated: 2024/07/15 15:27:36 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// IDEA
// Create a tick system ( 24 ticks per second )
// Base enemy movement on tick system ( 0.5 to 1 second delay)
// Linked lists for textures
//		Set up textures
// 		Search for texture and get it
// 		Update all of the frame numbers

#include "so_long_bonus.h"

int	update_tick(t_data *data)
{
	static int	loops = 0;

	if (loops >= 1350)
	{
		loops = 0;
		data->tick++;
		next_frame(data, &data->textures->texture_list);
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

void	next_frame(t_data *data, t_list **texture_list)
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
		frame_delay = TICK_RATE / texture->total_frames;
		texture->current_frame = round_up((float)data->tick / (float)frame_delay) - 1;
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