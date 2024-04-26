/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_formulas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:26:50 by hlindeza          #+#    #+#             */
/*   Updated: 2024/04/26 10:48:09 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	move_w_or_s(char c)
{
	if (c == 'w')
	{
		if (cub()->map_info->map[(int)(cub()->v.pos_y)][(int)(cub()->v.pos_x + \
			cub()->v.dir_x * MOVE_SPEED)] != '1')
			cub()->v.pos_x += cub()->v.dir_x * MOVE_SPEED;
		if (cub()->map_info->map[(int)(cub()->v.pos_y + cub()->v.dir_y \
				* MOVE_SPEED)][(int)cub()->v.pos_x] != '1')
			cub()->v.pos_y += cub()->v.dir_y * MOVE_SPEED;
	}
	else if (c == 's')
	{
		if (cub()->map_info->map[(int)(cub()->v.pos_y)][(int)(cub()->v.pos_x \
				- cub()->v.dir_x * MOVE_SPEED)] != '1')
			cub()->v.pos_x -= cub()->v.dir_x * MOVE_SPEED;
		if (cub()->map_info->map[(int)(cub()->v.pos_y - cub()->v.dir_y \
				* MOVE_SPEED)][(int)cub()->v.pos_x] != '1')
			cub()->v.pos_y -= cub()->v.dir_y * MOVE_SPEED;
	}
}

void	move_a_or_d(char c)
{
	if (c == 'a')
	{
		if (cub()->map_info->map[(int)cub()->v.pos_y][(int)(cub()->v.pos_x \
				+ cub()->v.dir_y * MOVE_SPEED)] != '1')
			cub()->v.pos_x += cub()->v.dir_y * MOVE_SPEED;
		if (cub()->map_info->map[(int)(cub()->v.pos_y - cub()->v.dir_x \
				* MOVE_SPEED)][(int)cub()->v.pos_x] != '1')
			cub()->v.pos_y -= cub()->v.dir_x * MOVE_SPEED;
	}
	else if (c == 'd')
	{
		if (cub()->map_info->map[(int)cub()->v.pos_y][(int)(cub()->v.pos_x \
				- cub()->v.dir_y * MOVE_SPEED)] != '1')
			cub()->v.pos_x -= cub()->v.dir_y * MOVE_SPEED;
		if (cub()->map_info->map[(int)(cub()->v.pos_y + cub()->v.dir_x \
				* MOVE_SPEED)][(int)cub()->v.pos_x] != '1')
			cub()->v.pos_y += cub()->v.dir_x * MOVE_SPEED;
	}
}

void	rotate_left(double old_dirx, double old_planex)
{
	cub()->v.dir_x = cub()->v.dir_x * cos(-ROTATION_SPEED) - cub()->v.dir_y \
		* sin(-ROTATION_SPEED);
	cub()->v.dir_y = old_dirx * sin(-ROTATION_SPEED) + cub()->v.dir_y \
		* cos(-ROTATION_SPEED);
	cub()->v.plane_x = cub()->v.plane_x * cos(-ROTATION_SPEED) - \
		cub()->v.plane_y * sin(-ROTATION_SPEED);
	cub()->v.plane_y = old_planex * sin(-ROTATION_SPEED) + cub()->v.plane_y \
		* cos(-ROTATION_SPEED);
}

void	rotate_right(double old_dirx, double old_planex)
{
	cub()->v.dir_x = cub()->v.dir_x * cos(ROTATION_SPEED) - cub()->v.dir_y \
		* sin(ROTATION_SPEED);
	cub()->v.dir_y = old_dirx * sin(ROTATION_SPEED) + cub()->v.dir_y * \
		cos(ROTATION_SPEED);
	cub()->v.plane_x = cub()->v.plane_x * cos(ROTATION_SPEED) - \
		cub()->v.plane_y * sin(ROTATION_SPEED);
	cub()->v.plane_y = old_planex * sin(ROTATION_SPEED) + cub()->v.plane_y \
		* cos(ROTATION_SPEED);
}

void	rotate(char c)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = cub()->v.dir_x;
	old_planex = cub()->v.plane_x;
	if (c == 'l')
		rotate_left(old_dirx, old_planex);
	else if (c == 'r')
		rotate_right(old_dirx, old_planex);
}
