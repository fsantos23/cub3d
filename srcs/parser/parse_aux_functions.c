/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_aux_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:46:22 by hlindeza          #+#    #+#             */
/*   Updated: 2024/03/20 13:50:41 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_file_extension(char *filename, char *extension)
{
	char	*file_extension;

	file_extension = ft_strrchr(filename, '.');
	if (file_extension && ft_strlen(file_extension) == ft_strlen(extension)
		&& ft_strncmp(file_extension, extension, ft_strlen(extension)) == 0)
		return (1);
	return (0);
}

int	check_characters(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!ft_ischaracters(map[i][j]))
				return (1);
		}
	}
	return (0);
}

int	check_textures_color(char **content)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (content[i] && !ft_have_only_number(content[i]))
	{
		count++;
		i++;
	}
	return (count);
}

int	check_textures_color_id(char **content)
{
	int		i;
	char	**str;

	i = 0;
	while (content[i] && !ft_have_only_number(content[i]))
	{
		str = split_trim(content[i], ' ');
		if (str && str[0] && (!ft_strcmp(str[0], "NO") || !ft_strcmp(str[0],
					"SO") || !ft_strcmp(str[0], "WE") || !ft_strcmp(str[0],
					"EA") || !ft_strcmp(str[0], "F") || !ft_strcmp(str[0],
					"C")))
			i++;
		else
		{
			free_matriz(&str);
			return (1);
		}
		free_matriz(&str);
	}
	return (0);
}

int	check_rgb_color(char **colors)
{
	char	**rgb;
	int		i;
	int		r;
	int		g;
	int		b;

	i = -1;
	while (colors[++i])
	{
		rgb = split_trim(&colors[i][2], ',');
		if (matriz_size(rgb) != 3 || check_num(rgb[0]) || check_num(rgb[1])
			|| check_num(rgb[2]))
		{
			free_matriz(&rgb);
			return (1);
		}
		save_rgb(&r, &g, &b, rgb);
		if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		{
			free_matriz(&rgb);
			return (1);
		}
		free_matriz(&rgb);
	}
	return (0);
}
