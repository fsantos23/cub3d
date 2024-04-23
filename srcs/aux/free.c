/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:15:56 by hlindeza          #+#    #+#             */
/*   Updated: 2024/03/17 12:41:29 by hlindeza         ###   ########.fr       */
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
	free(map);
}
