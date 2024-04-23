/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:34:26 by hlindeza          #+#    #+#             */
/*   Updated: 2024/04/23 18:05:39 by hlindeza         ###   ########.fr       */
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
	exit (0);
	return (1);
}

int	key_press(int keycode)
{
	if (keycode == 97)
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
	else if (keycode == 65307)
		quit_game();
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

void	move_vertical(char c)
{
	if (c == 'w')
	{
		if (cub()->map_info->map[(int) cub()->v.posY][(int)(cub()->v.posX + cub()->v.dirX * MOVE_SPEED)] != '1')
			cub()->v.posX += cub()->v.dirX * MOVE_SPEED;
		if (cub()->map_info->map[(int)(cub()->v.posY + cub()->v.dirY * MOVE_SPEED)]
			[(int)cub()->v.posX] != '1')
			cub()->v.posY += cub()->v.dirY * MOVE_SPEED;
	}
	else if (c == 's')
	{
		if (cub()->map_info->map[(int) cub()->v.posY]
			[(int)(cub()->v.posX - cub()->v.dirX * MOVE_SPEED)] != '1')
			cub()->v.posX -= cub()->v.dirX * MOVE_SPEED;
		if (cub()->map_info->map[(int)(cub()->v.posY - cub()->v.dirY * MOVE_SPEED)]
			[(int)cub()->v.posX] != '1')
			cub()->v.posY -= cub()->v.dirY * MOVE_SPEED;
	}
}

void	move_horizontal(char c)
{
	if (c == 'a')
	{
		if (cub()->map_info->map[(int)cub()->v.posY]
			[(int)(cub()->v.posX + cub()->v.dirY * MOVE_SPEED)] != '1')
			cub()->v.posX += cub()->v.dirY * MOVE_SPEED;
		if (cub()->map_info->map[(int)(cub()->v.posY - cub()->v.dirX * MOVE_SPEED)]
			[(int)cub()->v.posX] != '1')
			cub()->v.posY -= cub()->v.dirX * MOVE_SPEED;
	}
	else if (c == 'd')
	{
		if (cub()->map_info->map[(int)cub()->v.posY]
			[(int)(cub()->v.posX - cub()->v.dirY * MOVE_SPEED)] != '1')
			cub()->v.posX -= cub()->v.dirY * MOVE_SPEED;
		if (cub()->map_info->map[(int)(cub()->v.posY + cub()->v.dirX * MOVE_SPEED)]
			[(int)cub()->v.posX] != '1')
			cub()->v.posY += cub()->v.dirX * MOVE_SPEED;
	}
}

void	rotate_left(double old_dirX, double old_planeX)
{
	cub()->v.dirX = cub()->v.dirX * cos(-ROTATION_SPEED)
	- cub()->v.dirY * sin(-ROTATION_SPEED);
	cub()->v.dirY = old_dirX * sin(-ROTATION_SPEED)
	+ cub()->v.dirY * cos(-ROTATION_SPEED);
	cub()->v.planeX = cub()->v.planeX * cos(-ROTATION_SPEED)
	- cub()->v.planeY * sin(-ROTATION_SPEED);
	cub()->v.planeY = old_planeX * sin(-ROTATION_SPEED)
	+ cub()->v.planeY * cos(-ROTATION_SPEED);
}

void	rotate_right(double old_dirX, double old_planeX)
{
	cub()->v.dirX = cub()->v.dirX * cos(ROTATION_SPEED)
	- cub()->v.dirY * sin(ROTATION_SPEED);
	cub()->v.dirY = old_dirX * sin(ROTATION_SPEED)
	+ cub()->v.dirY * cos(ROTATION_SPEED);
	cub()->v.planeX = cub()->v.planeX * cos(ROTATION_SPEED)
	- cub()->v.planeY * sin(ROTATION_SPEED);
	cub()->v.planeY = old_planeX * sin(ROTATION_SPEED)
	+ cub()->v.planeY * cos(ROTATION_SPEED);
}

void	rotate(char c)
{
	double	old_dirX;
	double	old_planeX;

	old_dirX = cub()->v.dirX;
	old_planeX = cub()->v.planeX;
	if (c == 'l')
		rotate_left(old_dirX, old_planeX);
	else if (c == 'r')
		rotate_right(old_dirX, old_planeX);
}

void	hooks(void)
{
	if (cub()->hook.w == 1)
		move_vertical('w');
	else if (cub()->hook.s == 1)
		move_vertical('s');
	if (cub()->hook.a == 1)
		move_horizontal('a');
	else if (cub()->hook.d == 1)
		move_horizontal('d');
	if (cub()->hook.arr_left == 1)
		rotate('l');
	else if (cub()->hook.arr_right == 1)
		rotate('r');
}