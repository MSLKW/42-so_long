/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:10:28 by maxliew           #+#    #+#             */
/*   Updated: 2024/07/15 15:03:14 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_exit(char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

int	game_over(t_data *data)
{
	ft_printf("Game over!");
	free_data(data);
	exit(EXIT_SUCCESS);
}

int	key_manager(int keycode, t_data *data)
{
	if (keycode == ESC)
		game_over(data);
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
		movement_manager(keycode, data);
	return (0);
}

void	assign_data(t_data *data)
{
	ft_printf("a\n");
	data->textures = make_textures(data);
	if (data->textures == NULL)
		error_exit("Textures not found");
	ft_printf("b\n");
	data->player = make_player(data->map);
	if (data->player == NULL)
		error_exit("Player not found");
	ft_printf("c\n");	
	data->enemies = make_enemies(data->map);
	if (data->enemies == NULL)
		error_exit("No enemies found"); // turn this into warning
	ft_printf("d\n");
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_printf("A\n");
	data.tick = 0;
	if (argc > 2)
		error_exit("Too many arguments");
	else if (argc != 2)
		error_exit("No map found");
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (EXIT_FAILURE);
	data.map = make_map(argv[1]);
	if (data.map == NULL)
		error_exit("Unable to get map, is map path file correct?");
	ft_printf("B\n");
	assign_data(&data);
	data.window = mlx_new_window(data.mlx, data.map->width * IMAGE_SIZE, \
		data.map->height * IMAGE_SIZE, "so_long");
	ft_printf("C\n");
	put_map(&data);
	ft_printf("D\n");
	mlx_key_hook(data.window, key_manager, &data);
	mlx_loop_hook(data.mlx, update_tick, &data); 
	mlx_hook(data.window, X_BUTTON, 1L << 0, game_over, &data);
	mlx_loop(data.mlx);
}
