/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:24:05 by hlindeza          #+#    #+#             */
/*   Updated: 2024/04/24 15:36:31 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	save_path_texture(void)
{
	int	i;

	i = -1;
	while (cub()->map_info->textures[++i])
	{
		if (!ft_strncmp(cub()->map_info->textures[i], "NO", 2))
			cub()->map_info->no_texture = ft_strdup(&cub()->map_info->textures[i][3]);
		if (!ft_strncmp(cub()->map_info->textures[i], "SO", 2))
			cub()->map_info->so_texture = ft_strdup(&cub()->map_info->textures[i][3]);
		if (!ft_strncmp(cub()->map_info->textures[i], "WE", 2))
			cub()->map_info->we_texture = ft_strdup(&cub()->map_info->textures[i][3]);
		if (!ft_strncmp(cub()->map_info->textures[i], "EA", 2))
			cub()->map_info->ea_texture = ft_strdup(&cub()->map_info->textures[i][3]);
	}
    free_matriz(&cub()->map_info->textures);
}
