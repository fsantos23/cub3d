/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:29:06 by hlindeza          #+#    #+#             */
/*   Updated: 2024/04/25 00:12:29 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	put_pixel(int x, int y, int color)
{
	char	*dst;

	dst = cub()->img.addr + (y * cub()->img.line_length + x * (cub()->img.bpp
				/ 8));
	*(unsigned int *)dst = color;
}

unsigned long	rgb_to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	color_convert_init(void)
{
	int		i;
	char	**rgb;

	i = -1;
	while (cub()->map_info->colors[++i])
	{
		rgb = split_trim(&cub()->map_info->colors[i][2], ',');
		if (cub()->map_info->colors[i][0] == 'F')
			cub()->map_info->floor_color = rgb_to_hex(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
		else
			cub()->map_info->ceil_color = rgb_to_hex(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
		free_matriz(&rgb);
	}
	free_matriz(&cub()->map_info->colors);
}

void	draw_floor(void)
{
	int	x;
	int	y;

	x = -1;
	while (++x < SCREEN_WIDTH)
	{
		y = SCREEN_HEIGHT / 2 - 1;
		while (++y < SCREEN_HEIGHT)
			put_pixel(x, y, cub()->map_info->floor_color);
	}
}

void	draw_ceiling(void)
{
	int	x;
	int	y;

	x = -1;
	while (++x < SCREEN_WIDTH)
	{
		y = -1;
		while (++y < SCREEN_HEIGHT / 2)
			put_pixel(x, y, cub()->map_info->ceil_color);
	}
}
