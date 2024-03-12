/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:39:26 by hlindeza          #+#    #+#             */
/*   Updated: 2024/03/12 15:52:21 by hlindeza         ###   ########.fr       */
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

char	**save_map(char **content)
{
	char	**map_save;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (check_texture_and_color(content[i]))
		i++;
	map_save = malloc(sizeof(char *) * (map_size(&content[i]) + 1));
	if (!map_save)
		return (NULL);
	while (content[i])
		map_save[j++] = ft_strdup(content[i++]);
	map_save[j] = NULL;
	return (map_save);
}

char	**save_textures(char **content)
{
	char	**textures;
	int		i;
	int		j;

	j = 0;
	i = 0;
	textures = malloc(sizeof(char *) * 5);
	if (!textures)
		return (NULL);
	while (content[i])
	{
		if (check_texture_and_color(content[i]) == 1)
			textures[j++] = ft_strdup(content[i]);
		/*else if(check_texture_and_color(content[i]) == 2)
			color[k++] =  ft_strdup(content[i]);*/
		i++;
	}
	textures[j] = NULL;
	return (textures);
}

/*int check_map_surrounded(char **content)
{
	char **map = save_map(content);
	int i = 0;
	while(map[i])
	{
		if()
		i++;
	}
}*/
void	parser(char *filename)
{
	char	**content;

	if (!check_file_extension(filename, ".cub"))
	{
		ft_putstr_fd("Error\nInvalid file extension\n", 2);
		return ;
	}
	content = save_file_content(filename);
	cub()->map_info = malloc(sizeof(t_map));
	cub()->map_info->map = save_map(content);
	cub()->map_info->textures = save_textures(content);
	
}
