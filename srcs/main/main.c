/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:00:02 by hlindeza          #+#    #+#             */
/*   Updated: 2024/04/24 23:04:07 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_cub	*cub(void)
{
	static t_cub	cub;

	return (&cub);
}

void	set_dir(double dirX, double dirY, double planeX, double planeY)
{
	cub()->v.dirX = dirX;
	cub()->v.dirY = dirY;
	cub()->v.planeX = planeX;
	cub()->v.planeY = planeY;
}

void	set_player_dir(void)
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
