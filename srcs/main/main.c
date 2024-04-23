/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:00:02 by hlindeza          #+#    #+#             */
/*   Updated: 2024/04/23 18:06:14 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_cub	*cub(void)
{
	static t_cub	cub;

	return (&cub);
}

void	init_tmap(void)
{
	cub()->map_info = malloc(sizeof(t_map));
	cub()->map_info->map = NULL;
	cub()->map_info->textures = NULL;
	cub()->map_info->colors = NULL;
}

int	main(int argc, char **argv)
{
	(void)argc;
	if(init_map_struct(argv[1]))
		free_struct_map(cub()->map_info);
	ft_memset(&cub()->v, 0, sizeof(t_values));
	ft_memset(&cub()->hook, 0, sizeof(t_hooks));
	color_convert_init();
	
	init_graph();
	
	free_struct_map(cub()->map_info);
	return (0);
}
