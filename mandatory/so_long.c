/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:10:28 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/25 17:45:18 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 2)
		error_exit("Too many arguments");
	else if (argc != 2)
		error_exit("No map found");
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (EXIT_FAILURE);
	data.textures = get_textures(&data);
	if (data.textures == NULL)
		error_exit("Textures not found");
	data.map = get_map(argv[1]);
	if (data.map == NULL)
		error_exit("Unable to get map, is map path file correct?");
	data.player = get_player(data.map);
	if (data.player == NULL)
		error_exit("Player not found");
	data.window = mlx_new_window(data.mlx, data.map->width * IMAGE_SIZE, \
		data.map->height * IMAGE_SIZE, "so_long");
	put_map(&data);
	mlx_key_hook(data.window, key_manager, &data);
	mlx_hook(data.window, X_BUTTON, 1L << 0, game_over, &data);
	mlx_loop(data.mlx);
}
