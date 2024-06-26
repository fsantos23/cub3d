/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:49:13 by hlindeza          #+#    #+#             */
/*   Updated: 2024/04/26 10:47:16 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	save_player(char **map)
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
				cub()->map_info->x = j;
				cub()->map_info->y = i;
				cub()->map_info->p_dir = map[i][j];
				return ;
			}
		}
	}
}

void	save_map(char **content)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (content[i] && !ft_have_only_number(content[i]))
		i++;
	cub()->map_info->map = malloc(sizeof(char *) * (matriz_size(&content[i])
			+ 1));
	if (!cub()->map_info->map)
		return ;
	cub()->map_info->width = 0;
	while (content[i])
	{
		if (cub()->map_info->width < ft_strlen(content[i]))
			cub()->map_info->width = ft_strlen(content[i]);
		cub()->map_info->map[j++] = ft_strdup(content[i++]);
	}
	cub()->map_info->map[j] = NULL;
	cub()->map_info->height = j;
}

char	**save_file_content(char *file)
{
	int		fd;
	char	*str;
	char	*line;
	char	*tmp;
	char	**content;

	fd = open(file, O_RDONLY);
	str = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = ft_strjoin(str, line);
		free(str);
		str = tmp;
		free(line);
	}
	close(fd);
	content = ft_split(str, '\n');
	free(str);
	return (content);
}

void	save_textures(char **content)
{
	int		i;
	int		j;
	char	**tmp;
	int		size;

	i = 0;
	j = 0;
	size = texture_color_size(content, 1);
	cub()->map_info->textures = malloc(sizeof(char *) * (size + 1));
	if (!cub()->map_info->textures)
		return ;
	while (content[i])
	{
		tmp = ft_split(content[i], ' ');
		if (tmp && tmp[0] && !ft_have_only_number(content[i])
			&& ft_strlen(tmp[0]) == 2)
			cub()->map_info->textures[j++] = ft_strdup(content[i]);
		free_matriz(&tmp);
		i++;
	}
	cub()->map_info->textures[j] = NULL;
}

void	save_colors(char **content)
{
	int		i;
	int		j;
	char	**tmp;
	int		size;

	i = 0;
	j = 0;
	size = texture_color_size(content, 0);
	cub()->map_info->colors = malloc(sizeof(char *) * (size + 1));
	if (!cub()->map_info->colors)
		return ;
	while (content[i])
	{
		tmp = ft_split(content[i], ' ');
		if (tmp && tmp[0] && !ft_have_only_number(content[i])
			&& ft_strlen(tmp[0]) == 1)
			cub()->map_info->colors[j++] = ft_strdup(content[i]);
		free_matriz(&tmp);
		i++;
	}
	cub()->map_info->colors[j] = NULL;
}
