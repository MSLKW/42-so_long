/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:10:28 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/14 22:02:03 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *str)
{
	ft_printf("Error\n");
	ft_printf(str);
	exit(EXIT_FAILURE);
}

int	game_over(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	ft_printf("Game over!");
	exit(EXIT_SUCCESS);
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
	data->player->moves_count++;
	ft_printf("Moves: %i\n", data->player->moves_count);
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

int	main(int argc, char **argv)
{
	t_data data;

	if (argc > 2)
		error_exit("Too many arguments");
	else if (argc != 2)
		error_exit("No map found");
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (EXIT_FAILURE);
	data.textures = get_textures(&data);
	ft_printf("done textures\n");
	data.map = get_map(argv[1]);
	ft_printf("done map stuff\n");
	data.window = mlx_new_window(data.mlx, data.map->width * IMAGE_SIZE, data.map->height * IMAGE_SIZE, "so_long");
	set_background(&data);
	mlx_key_hook(data.window, key_manager, &data); // maybev mlx_hook for key_repeat?
	mlx_hook(data.window, 17, 1L << 0, game_over, &data); // what is 17 and 1L? event and mask codes but i need to know where they get them
	mlx_loop(data.mlx);
}