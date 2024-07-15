/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:16:49 by maxliew           #+#    #+#             */
/*   Updated: 2024/07/15 12:14:14 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include <stdio.h>

int	update_tick(int *loops)
{
	static int tick = 0;
	static int second = 0;

	if (*loops > 1350)
	{
		*loops = 0;
		tick++;
	}
	if (tick > 20)
	{
		tick = 0;
		second++;
		printf("second: %i\n", second);
	}
	(*loops)++;
}

int	key_manager(int keycode, void *loops)
{
	printf("Keycode: %i\n", keycode);
}

int	main(void)
{
	int	loops = 0;


	void *mlx_ptr = mlx_init();
	void *window = mlx_new_window(mlx_ptr, 40, 40, "test");
	printf("BEGIN!\n");
	mlx_key_hook(window, key_manager, &loops);
	mlx_loop_hook(mlx_ptr, update_tick,  &loops);
	// printf("%i tick\n", tick);
	mlx_loop(mlx_ptr);
}