/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:15:56 by hlindeza          #+#    #+#             */
/*   Updated: 2024/04/24 23:26:15 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	free_matriz(char ***mrtz)
{
	int	i;

	i = 0;
	if (*mrtz)
	{
		while ((*mrtz)[i])
		{
			free((*mrtz)[i]);
			i++;
		}
	}
	free(*mrtz);
	*mrtz = NULL;
}

void	free_struct_map(t_map *map)
{
	if (map->map)
		free_matriz(&map->map);
	if (map->textures)
		free_matriz(&map->textures);
	if (map->colors)
		free_matriz(&map->colors);
	if (map->no_texture)
		free(map->no_texture);
	if (map->so_texture)
		free(map->so_texture);
	if (map->we_texture)
		free(map->we_texture);
	if (map->ea_texture)
		free(map->ea_texture);
	free(map);
}
