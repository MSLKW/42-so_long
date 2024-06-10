/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:10:28 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/10 21:21:55 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*

TODO:

PRELIMINARIES
---
Create functioning window
Display images
	Convert xpm to img



GAME
---
Display map onto windows
Implement movement


VALIDATE MAP








*/

int	game_over(t_data *data)
{
	mlx_destroy_window(data->mlx, data->windows);
	ft_printf("Game over!");
	exit(0);
}

void	movement_manager(int keycode, t_data *data)
{
	if (keycode == 13)
		ft_printf("W");
	else if (keycode == 0)
		ft_printf("A");
	else if (keycode == 1)
		ft_printf("S");
	else if (keycode == 2)
		ft_printf("D");
	data->moves_count++;
	ft_printf("Moves: %i\n", data->moves_count);
}

int	key_manager(int keycode, t_data *data)
{
	if (keycode == 53)
		game_over(data);
	else if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		movement_manager(keycode, data);
	else
		ft_printf("Keycode: %i\n", keycode);
	return (0);
}

int	main()
{
	t_data data;

	data.moves_count = 0;
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);
	data.windows = mlx_new_window(data.mlx, 500, 500, "so_long");
	mlx_key_hook(data.windows, key_manager, &data);
	mlx_hook(data.windows, 17, 1L, game_over, &data);
	mlx_loop(data.mlx);
}