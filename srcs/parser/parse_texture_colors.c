/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_colors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:15:15 by hlindeza          #+#    #+#             */
/*   Updated: 2024/04/26 10:15:26 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_identifier(char **content, int id)
{
	int	i;

	i = -1;
	while (content[++i])
		if (ft_istexture_or_color(content[i]) != id)
			return (1);
	return (0);
}

int	multi_identifier(char **content, char *identifier)
{
	int	amount;
	int	i;

	amount = -1;
	i = -1;
	while (content[++i])
		if (!ft_strncmp(content[i], identifier, ft_strlen(identifier)))
			amount++;
	return (amount);
}

int	check_multi_identifier(char **textures, char **color)
{
	if (multi_identifier(textures, "EA") != 0 || multi_identifier(textures,
			"WE") != 0 || multi_identifier(textures, "SO") != 0
		|| multi_identifier(textures, "NO") != 0 || multi_identifier(color,
			"C") != 0 || multi_identifier(color, "F") != 0)
		return (1);
	return (0);
}

int	check_textures_path(char **textures)
{
	int		i;
	int		fd;
	char	**path;

	i = -1;
	while (textures[++i])
	{
		path = ft_split(textures[i], ' ');
		if (matriz_size(path) != 2)
		{
			free_matriz(&path);
			return (1);
		}
		fd = open(path[1], O_RDONLY);
		if (fd < 0)
		{
			close(fd);
			free_matriz(&path);
			return (1);
		}
		free_matriz(&path);
	}
	return (0);
}
