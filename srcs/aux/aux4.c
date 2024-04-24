/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:24:05 by hlindeza          #+#    #+#             */
/*   Updated: 2024/04/25 00:08:30 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	save_path_texture(void)
{
	int		i;
	char	**temp;

	i = -1;
	temp = split_trim(cub()->map_info->textures[0], ' ');
	while (cub()->map_info->textures[++i])
	{
		temp = split_trim(cub()->map_info->textures[i], ' ');
		if (!ft_strncmp(temp[0], "NO", 2))
			cub()->map_info->no_texture = ft_strdup(temp[1]);
		if (!ft_strncmp(temp[0], "SO", 2))
			cub()->map_info->so_texture = ft_strdup(temp[1]);
		if (!ft_strncmp(temp[0], "WE", 2))
			cub()->map_info->we_texture = ft_strdup(temp[1]);
		if (!ft_strncmp(temp[0], "EA", 2))
			cub()->map_info->ea_texture = ft_strdup(temp[1]);
		free_matriz(&temp);
	}
	free_matriz(&cub()->map_info->textures);
}

int	check_player_space(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_isplayer(map[i][j]))
			{
				if (map[i - 1][j] == ' ')
					return (1);
				else if (map[i + 1][j] == ' ')
					return (1);
				else if (map[i][j - 1] == ' ')
					return (1);
				else if (map[i][j + 1] == ' ')
					return (1);
			}
		}
	}
	return (0);
}
