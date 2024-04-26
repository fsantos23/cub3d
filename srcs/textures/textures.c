/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:03:05 by fsantos2          #+#    #+#             */
/*   Updated: 2024/04/26 10:44:14 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_data	create_img(char *path)
{
	t_data	img;

	img.ptr = mlx_xpm_file_to_image(cub()->initmlx, path, &img.x, &img.y);
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.line_length,
			&img.endian);
	return (img);
}

void	xpm_to_image(void)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (i == 0)
			cub()->textures[i] = create_img(cub()->map_info->no_texture);
		else if (i == 1)
			cub()->textures[i] = create_img(cub()->map_info->so_texture);
		else if (i == 2)
			cub()->textures[i] = create_img(cub()->map_info->we_texture);
		else if (i == 3)
			cub()->textures[i] = create_img(cub()->map_info->ea_texture);
	}
}

void	wall_hit_point(void)
{
	double	wall;

	if (cub()->v.side == 0)
		wall = cub()->v.pos_y + (cub()->v.walldist * cub()->v.ray_diry);
	else
		wall = cub()->v.pos_x + (cub()->v.walldist * cub()->v.ray_dirx);
	wall -= floor(wall);
	cub()->v.tex_x = (int)(wall * (double)cub()->textures[cub()->v.index].x);
	if (cub()->v.side == 1 && cub()->v.ray_diry < 0)
		cub()->v.tex_x = cub()->textures[cub()->v.index].x - cub()->v.tex_x - 1;
}
