/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:02:43 by hlindeza          #+#    #+#             */
/*   Updated: 2024/04/24 15:35:54 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_num(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
	}
	return (0);
}
void	save_rgb(int *r, int *g, int *b, char **rgb)
{
	*r = ft_atoi(rgb[0]);
	*g = ft_atoi(rgb[1]);
	*b = ft_atoi(rgb[2]);
}

void	save_stuff(char **content)
{
	save_map(content);
	save_player(cub()->map_info->map);
	save_textures(content);
	save_colors(content);
}

int	init_map_struct(char *file)
{
	char	**content;

	init_tmap();
	if (!check_file_extension(file, ".cub"))
	{
		printf("Error, Invalid file extension\n");
		return (1);
	}
	content = save_file_content(file);
	if (!content)
		return (1);
	if (check_textures_color(content) != 6)
	{
		printf("Error, Invalid number of colors or textures\n");
		free_matriz(&content);
		return (1);
	}
	save_stuff(content);
	if (parse_map(cub()->map_info->map) || parse_textures_colors(content))
	{
		free_matriz(&content);
		return (1);
	}
	save_path_texture();
	free_matriz(&content);
	return (0);
}
