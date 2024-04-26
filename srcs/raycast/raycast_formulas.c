/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_formulas.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:19:11 by hlindeza          #+#    #+#             */
/*   Updated: 2024/04/26 10:48:31 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	calculate_ray_pos(int x)
{
	double	camerax;

	camerax = (2 * x / (double)SCREEN_WIDTH) - 1;
	cub()->v.ray_dirx = cub()->v.dir_x + (cub()->v.plane_x * camerax);
	cub()->v.ray_diry = cub()->v.dir_y + (cub()->v.plane_y * camerax);
	if (cub()->v.ray_dirx == 0)
		cub()->v.delta_distx = 1e30;
	else
		cub()->v.delta_distx = fabs(1 / cub()->v.ray_dirx);
	if (cub()->v.ray_diry == 0)
		cub()->v.delta_disty = 1e30;
	else
		cub()->v.delta_disty = fabs(1 / cub()->v.ray_diry);
}

void	calculate_initial_sidedist(void)
{
	if (cub()->v.ray_dirx < 0)
	{
		cub()->v.side_distx = (cub()->v.pos_x - cub()->v.mapx) \
		* cub()->v.delta_distx;
		cub()->v.stepx = -1;
	}
	else
	{
		cub()->v.side_distx = (cub()->v.mapx + 1.0 - cub()->v.pos_x) \
			* cub()->v.delta_distx;
		cub()->v.stepx = 1;
	}
	if (cub()->v.ray_diry < 0)
	{
		cub()->v.side_disty = (cub()->v.pos_y - cub()->v.mapy) \
			* cub()->v.delta_disty;
		cub()->v.stepy = -1;
	}
	else
	{
		cub()->v.side_disty = (cub()->v.mapy + 1.0 - cub()->v.pos_y) \
			* cub()->v.delta_disty;
		cub()->v.stepy = 1;
	}
}

void	dda_loop(void)
{
	cub()->v.hit = 0;
	while (cub()->v.hit == 0)
	{
		if (cub()->v.side_distx < cub()->v.side_disty)
		{
			cub()->v.side_distx += cub()->v.delta_distx;
			cub()->v.mapx += cub()->v.stepx;
			cub()->v.side = 0;
		}
		else
		{
			cub()->v.side_disty += cub()->v.delta_disty;
			cub()->v.mapy += cub()->v.stepy;
			cub()->v.side = 1;
		}
		if (cub()->map_info->map[cub()->v.mapy][cub()->v.mapx] == '1')
		{
			cub()->v.hit = 1;
			set_texture();
		}
	}
}

void	wall_height(void)
{
	if (cub()->v.side == 0)
		cub()->v.walldist = cub()->v.side_distx - cub()->v.delta_distx;
	else
		cub()->v.walldist = cub()->v.side_disty - cub()->v.delta_disty;
	cub()->v.line_length = (int)(SCREEN_HEIGHT / cub()->v.walldist);
	cub()->v.draw_start = -cub()->v.line_length / 2 + SCREEN_HEIGHT / 2;
	if (cub()->v.draw_start < 0)
		cub()->v.draw_start = 0;
	cub()->v.draw_end = (SCREEN_HEIGHT / 2) + (cub()->v.line_length / 2);
	if (cub()->v.draw_end >= SCREEN_HEIGHT)
		cub()->v.draw_end = SCREEN_HEIGHT - 1;
}

void	draw_wall(int x)
{
	double			step;
	double			tex_pos;
	double			tex_y;
	int				y;
	unsigned int	color;

	step = (double)cub()->textures[cub()->v.index].y / cub()->v.line_length;
	tex_pos = (cub()->v.draw_start - SCREEN_HEIGHT / 2 + \
		cub()->v.line_length / 2) * step;
	y = cub()->v.draw_start;
	while (y < cub()->v.draw_end)
	{
		tex_y = (int)tex_pos & (cub()->textures[cub()->v.index].y - 1);
		tex_pos += step;
		color = *(unsigned int *)(cub()->textures[cub()->v.index].addr
				+ (int)tex_y * cub()->textures[cub()->v.index].line_length
				+ cub()->v.tex_x * (cub()->textures[cub()->v.index].bpp / 8));
		put_pixel(x, y, color);
		y++;
	}
}
