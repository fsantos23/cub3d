/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_formulas.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:19:11 by hlindeza          #+#    #+#             */
/*   Updated: 2024/04/26 10:02:24 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	calculate_ray_pos(int x)
{
	double	cameraX;

	cameraX = (2 * x / (double)SCREEN_WIDTH) - 1;
	cub()->v.rayDirX = cub()->v.dirX + (cub()->v.planeX * cameraX);
	cub()->v.rayDirY = cub()->v.dirY + (cub()->v.planeY * cameraX);
	if (cub()->v.rayDirX == 0)
		cub()->v.deltaDistX = 1e30;
	else
		cub()->v.deltaDistX = fabs(1 / cub()->v.rayDirX);
	if (cub()->v.rayDirY == 0)
		cub()->v.deltaDistY = 1e30;
	else
		cub()->v.deltaDistY = fabs(1 / cub()->v.rayDirY);
}

void	calculate_initial_sideDist(void)
{
	if (cub()->v.rayDirX < 0)
	{
		cub()->v.sideDistX = (cub()->v.posX - cub()->v.mapX)
			* cub()->v.deltaDistX;
		cub()->v.stepX = -1;
	}
	else
	{
		cub()->v.sideDistX = (cub()->v.mapX + 1.0 - cub()->v.posX)
			* cub()->v.deltaDistX;
		cub()->v.stepX = 1;
	}
	if (cub()->v.rayDirY < 0)
	{
		cub()->v.sideDistY = (cub()->v.posY - cub()->v.mapY)
			* cub()->v.deltaDistY;
		cub()->v.stepY = -1;
	}
	else
	{
		cub()->v.sideDistY = (cub()->v.mapY + 1.0 - cub()->v.posY)
			* cub()->v.deltaDistY;
		cub()->v.stepY = 1;
	}
}

void	set_texture(void)
{
	if (cub()->v.side == 1)
	{
		if (cub()->v.mapY > cub()->v.posY)
			cub()->v.index = 1;
		else
			cub()->v.index = 0;
	}
	else if (cub()->v.side == 0)
	{
		if (cub()->v.mapX > cub()->v.posX)
			cub()->v.index = 3;
		else
			cub()->v.index = 2;
	}
}

void	dda_loop(void)
{
	cub()->v.hit = 0;
	while (cub()->v.hit == 0)
	{
		if (cub()->v.sideDistX < cub()->v.sideDistY)
		{
			cub()->v.sideDistX += cub()->v.deltaDistX;
			cub()->v.mapX += cub()->v.stepX;
			cub()->v.side = 0;
		}
		else
		{
			cub()->v.sideDistY += cub()->v.deltaDistY;
			cub()->v.mapY += cub()->v.stepY;
			cub()->v.side = 1;
		}
		if (cub()->map_info->map[cub()->v.mapY][cub()->v.mapX] == '1')
		{
			cub()->v.hit = 1;
			set_texture();
		}
	}
}

void	wall_height(void)
{
	if (cub()->v.side == 0)
		cub()->v.WallDist = cub()->v.sideDistX - cub()->v.deltaDistX;
	else
		cub()->v.WallDist = cub()->v.sideDistY - cub()->v.deltaDistY;
	cub()->v.lineLength = (int)(SCREEN_HEIGHT / cub()->v.WallDist);
	cub()->v.drawStart = - cub()->v.lineLength / 2 + SCREEN_HEIGHT / 2;
	if (cub()->v.drawStart < 0)
		cub()->v.drawStart = 0;
	cub()->v.drawEnd = (SCREEN_HEIGHT / 2) + (cub()->v.lineLength / 2);
	if (cub()->v.drawEnd >= SCREEN_HEIGHT)
		cub()->v.drawEnd = SCREEN_HEIGHT - 1;
}

void	draw_wall(int x)
{
	double			step;
	double			tex_pos;
	double			tex_y;
	int				y;
	unsigned int	color;

	step = (double)cub()->textures[cub()->v.index].y / cub()->v.lineLength;
	tex_pos = (cub()->v.drawStart - SCREEN_HEIGHT / 2 + cub()->v.lineLength / 2) * step;
	y = cub()->v.drawStart;
	while (y < cub()->v.drawEnd)
	{
		tex_y = (int)tex_pos &(cub()->textures[cub()->v.index].y - 1);
		tex_pos += step;
		color = *(unsigned int *)(cub()->textures[cub()->v.index].addr + (int)tex_y * \
		cub()->textures[cub()->v.index].line_length + cub()->v.tex_x * (cub()->textures[cub()->v.index].bpp / 8));
		put_pixel(x, y, color);
		y++;
	}
}
