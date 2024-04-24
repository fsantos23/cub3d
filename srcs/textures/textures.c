/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:03:05 by fsantos2          #+#    #+#             */
/*   Updated: 2024/04/24 15:20:14 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void xpm_to_image(void)
{
    int i;

    i = 0;
    while(i < 4)
    {
		//cub()->textures[i] = (t_data)malloc(sizeof(t_data));
        cub()->textures[i].ptr = mlx_xpm_file_to_image(cub()->initmlx, \
		&cub()->map_info->textures[i][2], &cub()->textures[i].x, &cub()->textures[i].y);
        cub()->textures[i].addr = mlx_get_data_addr(cub()->textures[i].ptr, \
		&cub()->textures[i].bpp, &cub()->textures[i].line_length, &cub()->textures[i].endian);
		i++;
    }
}

void    wall_hit_point(void)
{
	double wall;
    if (cub()->v.side == 0)
		wall = cub()->v.posY + (cub()->v.WallDist * cub()->v.rayDirY);
	else
		wall = cub()->v.posX + (cub()->v.WallDist * cub()->v.rayDirX);
	wall -= floor(wall);
	cub()->v.tex_x = (int)(wall * (double)cub()->textures[cub()->v.index].x);
	if(cub()->v.side == 1 && cub()->v.rayDirY < 0)
		cub()->v.tex_x = cub()->textures[cub()->v.index].x - cub()->v.tex_x - 1;
}