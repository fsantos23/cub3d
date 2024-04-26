/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:00:02 by hlindeza          #+#    #+#             */
/*   Updated: 2024/04/26 10:47:16 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_cub	*cub(void)
{
	static t_cub	cub;

	return (&cub);
}

void	set_dir(double dir_x, double dir_y, double plane_x, double plane_y)
{
	cub()->v.dir_x = dir_x;
	cub()->v.dir_y = dir_y;
	cub()->v.plane_x = plane_x;
	cub()->v.plane_y = plane_y;
}

void	set_player_dir(void)
{
	cub()->v.pos_x = cub()->map_info->x + 0.5;
	cub()->v.pos_y = cub()->map_info->y + 0.5;
	if (cub()->map_info->p_dir == 'N')
		set_dir(0, -1, 0.85, 0);
	else if (cub()->map_info->p_dir == 'S')
		set_dir(0, 1, -0.85, 0);
	else if (cub()->map_info->p_dir == 'E')
		set_dir(1, 0, 0, 0.85);
	else if (cub()->map_info->p_dir == 'W')
		set_dir(-1, 0, 0, -0.85);
}

void	init_tmap(void)
{
	cub()->map_info = malloc(sizeof(t_map));
	cub()->map_info->map = NULL;
	cub()->map_info->textures = NULL;
	cub()->map_info->colors = NULL;
	cub()->map_info->no_texture = NULL;
	cub()->map_info->so_texture = NULL;
	cub()->map_info->we_texture = NULL;
	cub()->map_info->ea_texture = NULL;
}

int	main(int argc, char **argv)
{
	(void)argc;
	if (init_map_struct(argv[1]))
	{
		free_struct_map(cub()->map_info);
		return (1);
	}
	ft_memset(&cub()->v, 0, sizeof(t_values));
	ft_memset(&cub()->hook, 0, sizeof(t_hooks));
	color_convert_init();
	init_graph();
	free_struct_map(cub()->map_info);
	return (0);
}
