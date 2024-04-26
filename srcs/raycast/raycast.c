/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:14:44 by hlindeza          #+#    #+#             */
/*   Updated: 2024/04/26 10:44:29 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	save_mapxy(void)
{
	cub()->v.mapx = (int)cub()->v.pos_x;
	cub()->v.mapy = (int)cub()->v.pos_y;
}

int	main_raycast_loop(void)
{
	int	x;

	x = -1;
	while (++x < SCREEN_WIDTH)
	{
		save_mapxy();
		calculate_ray_pos(x);
		calculate_initial_sidedist();
		dda_loop();
		wall_height();
		wall_hit_point();
		draw_wall(x);
	}
	return (0);
}

int	draw(void)
{
	draw_floor();
	draw_ceiling();
	main_raycast_loop();
	hooks();
	mlx_put_image_to_window(cub()->initmlx, cub()->winmlx, cub()->img.ptr, 0,
		0);
	return (1);
}

void	init_graph(void)
{
	cub()->initmlx = mlx_init();
	(cub()->winmlx) = mlx_new_window(cub()->initmlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, "cub3d");
	(cub()->img.ptr) = mlx_new_image(cub()->initmlx, SCREEN_WIDTH,
			SCREEN_HEIGHT);
	(cub()->img.addr) = mlx_get_data_addr(cub()->img.ptr, &cub()->img.bpp,
			&cub()->img.line_length, &cub()->img.endian);
	xpm_to_image();
	set_player_dir();
	mlx_loop_hook(cub()->initmlx, draw, NULL);
	mlx_hook(cub()->winmlx, 2, 1L << 0, key_press, NULL);
	mlx_hook(cub()->winmlx, 3, 1L << 1, key_release, NULL);
	mlx_hook(cub()->winmlx, 17, 0L, quit_game, NULL);
	mlx_loop(cub()->initmlx);
}
