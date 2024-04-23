/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:14:44 by hlindeza          #+#    #+#             */
/*   Updated: 2024/04/23 17:57:50 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"



void	set_dir(double dirX, double dirY, double planeX, double planeY)
{
	cub()->v.dirX = dirX;
	cub()->v.dirY = dirY;
	cub()->v.planeX = planeX;
	cub()->v.planeY = planeY;
}


void set_player_dir(void)
{   
    cub()->v.posX = cub()->map_info->x + 0.5;
    cub()->v.posY = cub()->map_info->y + 0.5;
    
    if (cub()->map_info->pDir == 'N')
        set_dir(0, -1, 0.85, 0);
    else if (cub()->map_info->pDir == 'S')
        set_dir(0, 1, -0.85, 0);
    else if (cub()->map_info->pDir == 'E')
        set_dir(1, 0, 0, 0.85);
    else if (cub()->map_info->pDir == 'W')
        set_dir(-1, 0, 0, -0.85);
}


void	calculate_ray_pos(int x)
{
	double	cameraX;

	cameraX = (2 * x / (double)SCREEN_WIDTH ) - 1;
	cub()->v.rayDirX = cub()->v.dirX + (cub()->v.planeX * cameraX);
	cub()->v.rayDirY = cub()->v.dirY + (cub()->v.planeY * cameraX);
    
	if (cub()->v.rayDirX == 0)
		cub()->v.deltaDistX = 1e30;
	else
		cub()->v.deltaDistX = fabs(1/ cub()->v.rayDirX);
	if (cub()->v.rayDirY == 0)
		cub()->v.deltaDistY = 1e30;
	else
		cub()->v.deltaDistY = fabs(1/ cub()->v.rayDirY);
}

void	calculate_initial_sideDist(void)
{
	if (cub()->v.rayDirX < 0)
	{
		cub()->v.sideDistX = (cub()->v.posX - cub()->v.mapX) * cub()->v.deltaDistX;
		cub()->v.stepX = -1;
	}
	else
	{
		cub()->v.sideDistX = (cub()->v.mapX + 1.0 - cub()->v.posX) * cub()->v.deltaDistX;
		cub()->v.stepX = 1;
	}
	if (cub()->v.rayDirY < 0)
	{
		cub()->v.sideDistY = (cub()->v.posY - cub()->v.mapY) * cub()->v.deltaDistY;
		cub()->v.stepY = -1;
	}
	else
	{
		cub()->v.sideDistY = (cub()->v.mapY + 1.0 - cub()->v.posY) * cub()->v.deltaDistY;
		cub()->v.stepY = 1;
	}
}

void dda_loop()
{
    cub()->v.hit = 0;
    while(cub()->v.hit == 0)
    {
        if(cub()->v.sideDistX < cub()->v.sideDistY)
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
        if(cub()->map_info->map[cub()->v.mapY][cub()->v.mapX] == '1')
        {   
            cub()->v.hit = 1;
            //set_texture();
        }
    }
}

void wall_height(void)
{
    if(cub()->v.side == 0)
        cub()->v.WallDist = cub()->v.sideDistX - cub()->v.deltaDistX;
    else
        cub()->v.WallDist = cub()->v.sideDistY - cub()->v.deltaDistY;

    cub()->v.lineLength = (int)(SCREEN_HEIGHT / cub()->v.WallDist);

    cub()->v.drawStart = (SCREEN_HEIGHT / 2) - (cub()->v.lineLength / 2);
    if(cub()->v.drawStart < 0)
        cub()->v.drawStart = 0;
    cub()->v.drawEnd = (SCREEN_HEIGHT / 2) + (cub()->v.lineLength / 2);
    if(cub()->v.drawEnd >= SCREEN_HEIGHT)
        cub()->v.drawEnd = SCREEN_HEIGHT - 1;
}

void save_mapxy(void)
{
    cub()->v.mapX = (int)cub()->v.posX;
    cub()->v.mapY = (int)cub()->v.posY;
}

void draw_wall_x(int x)
{
    int y;
    unsigned int color;

    if (cub()->v.side == 1)
        color = 0x008000; // Verde escuro para o lado 1 (leste ou oeste)
    else
        color = 0x00FF00; // Verde para o lado 0 (norte ou sul)

    y = cub()->v.drawStart;
    while (y < cub()->v.drawEnd)
    {
        put_pixel(x, y, color);
        y++;
    }
}

int mega_loop(void)
{
    int x;

    x = -1;
    while(++x < SCREEN_WIDTH)
    {
        save_mapxy();
        calculate_ray_pos(x);
        calculate_initial_sideDist();
        dda_loop();
        wall_height();
        draw_wall_x(x);
    }
    return (0);
}

int desenhar(void)
{
    draw_floor();
    draw_ceiling();
    mega_loop();
    hooks();
    mlx_put_image_to_window(cub()->initmlx, cub()->winmlx, cub()->img.ptr, 0, 0);
    return 1;
}
void	init_graph(void)
{
	cub()->initmlx = mlx_init();
	cub()->winmlx = mlx_new_window(cub()->initmlx, SCREEN_WIDTH, SCREEN_HEIGHT,"cub3d");
    cub()->img.ptr = mlx_new_image(cub()->initmlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    cub()->img.addr = mlx_get_data_addr(cub()->img.ptr, &cub()->img.bpp, &cub()->img.line_length, &cub()->img.endian);
    
    set_player_dir();
    mlx_loop_hook(cub()->initmlx, desenhar, NULL);
    
    mlx_hook(cub()->initmlx, 2, (1L << 0), key_press, NULL);
	mlx_hook(cub()->initmlx, 3, (1L << 1), key_release, NULL);
    mlx_hook(cub()->initmlx, 17, 0, quit_game, NULL);
    mlx_loop(cub()->initmlx);
}