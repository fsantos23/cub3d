/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:34:26 by hlindeza          #+#    #+#             */
/*   Updated: 2024/04/24 11:43:58 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	quit_game(void)
{
	free_struct_map(cub()->map_info);
	mlx_destroy_image(cub()->initmlx, cub()->img.ptr);
	mlx_destroy_window(cub()->initmlx, cub()->winmlx);
	mlx_destroy_display(cub()->initmlx);
	free(cub()->initmlx);
	exit(0);
	return (1);
}

int	key_press(int keycode)
{
	if (keycode == 65307)
		quit_game();
	else if (keycode == 97)
		cub()->hook.a = 1;
	else if (keycode == 100)
		cub()->hook.d = 1;
	else if (keycode == 115)
		cub()->hook.s = 1;
	else if (keycode == 119)
		cub()->hook.w = 1;
	else if (keycode == 65361)
		cub()->hook.arr_left = 1;
	else if (keycode == 65363)
		cub()->hook.arr_right = 1;
	return (1);
}

int	key_release(int keycode)
{
	if (keycode == 97)
		cub()->hook.a = 0;
	else if (keycode == 100)
		cub()->hook.d = 0;
	else if (keycode == 115)
		cub()->hook.s = 0;
	else if (keycode == 119)
		cub()->hook.w = 0;
	else if (keycode == 65361)
		cub()->hook.arr_left = 0;
	else if (keycode == 65363)
		cub()->hook.arr_right = 0;
	return (1);
}

void	hooks(void)
{
	if (cub()->hook.w == 1)
		move_w_or_s('w');
	else if (cub()->hook.s == 1)
		move_w_or_s('s');
	if (cub()->hook.a == 1)
		move_a_or_d('a');
	else if (cub()->hook.d == 1)
		move_a_or_d('d');
	if (cub()->hook.arr_left == 1)
		rotate('l');
	else if (cub()->hook.arr_right == 1)
		rotate('r');
}
