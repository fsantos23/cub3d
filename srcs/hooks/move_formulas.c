/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_formulas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:26:50 by hlindeza          #+#    #+#             */
/*   Updated: 2024/04/24 11:28:27 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	move_w_or_s(char c)
{
	if (c == 'w')
	{
		if (cub()->map_info->map[(int)(cub()->v.posY)][(int)(cub()->v.posX
				+ cub()->v.dirX * MOVE_SPEED)] != '1')
			cub()->v.posX += cub()->v.dirX * MOVE_SPEED;
		if (cub()->map_info->map[(int)(cub()->v.posY + cub()->v.dirY
				* MOVE_SPEED)][(int)cub()->v.posX] != '1')
			cub()->v.posY += cub()->v.dirY * MOVE_SPEED;
	}
	else if (c == 's')
	{
		if (cub()->map_info->map[(int)(cub()->v.posY)][(int)(cub()->v.posX
				- cub()->v.dirX * MOVE_SPEED)] != '1')
			cub()->v.posX -= cub()->v.dirX * MOVE_SPEED;
		if (cub()->map_info->map[(int)(cub()->v.posY - cub()->v.dirY
				* MOVE_SPEED)][(int)cub()->v.posX] != '1')
			cub()->v.posY -= cub()->v.dirY * MOVE_SPEED;
	}
}

void	move_a_or_d(char c)
{
	if (c == 'a')
	{
		if (cub()->map_info->map[(int)cub()->v.posY][(int)(cub()->v.posX
				+ cub()->v.dirY * MOVE_SPEED)] != '1')
			cub()->v.posX += cub()->v.dirY * MOVE_SPEED;
		if (cub()->map_info->map[(int)(cub()->v.posY - cub()->v.dirX
				* MOVE_SPEED)][(int)cub()->v.posX] != '1')
			cub()->v.posY -= cub()->v.dirX * MOVE_SPEED;
	}
	else if (c == 'd')
	{
		if (cub()->map_info->map[(int)cub()->v.posY][(int)(cub()->v.posX
				- cub()->v.dirY * MOVE_SPEED)] != '1')
			cub()->v.posX -= cub()->v.dirY * MOVE_SPEED;
		if (cub()->map_info->map[(int)(cub()->v.posY + cub()->v.dirX
				* MOVE_SPEED)][(int)cub()->v.posX] != '1')
			cub()->v.posY += cub()->v.dirX * MOVE_SPEED;
	}
}

void	rotate_left(double old_dirX, double old_planeX)
{
	cub()->v.dirX = cub()->v.dirX * cos(-ROTATION_SPEED) - cub()->v.dirY
		* sin(-ROTATION_SPEED);
	cub()->v.dirY = old_dirX * sin(-ROTATION_SPEED) + cub()->v.dirY
		* cos(-ROTATION_SPEED);
	cub()->v.planeX = cub()->v.planeX * cos(-ROTATION_SPEED) - cub()->v.planeY
		* sin(-ROTATION_SPEED);
	cub()->v.planeY = old_planeX * sin(-ROTATION_SPEED) + cub()->v.planeY
		* cos(-ROTATION_SPEED);
}

void	rotate_right(double old_dirX, double old_planeX)
{
	cub()->v.dirX = cub()->v.dirX * cos(ROTATION_SPEED) - cub()->v.dirY
		* sin(ROTATION_SPEED);
	cub()->v.dirY = old_dirX * sin(ROTATION_SPEED) + cub()->v.dirY
		* cos(ROTATION_SPEED);
	cub()->v.planeX = cub()->v.planeX * cos(ROTATION_SPEED) - cub()->v.planeY
		* sin(ROTATION_SPEED);
	cub()->v.planeY = old_planeX * sin(ROTATION_SPEED) + cub()->v.planeY
		* cos(ROTATION_SPEED);
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
