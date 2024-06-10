/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:10:28 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/08 11:49:42 by maxliew          ###   ########.fr       */
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

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 100, 100, "Hello World!");
	sleep(5);
	mlx_destroy_window(mlx_ptr, win_ptr);
}