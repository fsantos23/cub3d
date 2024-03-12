/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrique <henrique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:21:11 by henrique          #+#    #+#             */
/*   Updated: 2023/05/22 15:46:36 by henrique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_limits(t_game *game)
{
	int	i;
	int	lp;

	lp = game->map_height - 1;
	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] == '1' && game->map[lp][i] == '1')
			i++;
		else
			return (0);
	}
	lp = game->map_width - 1;
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] == '1' && game->map[i][lp] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

void	line_map_size(t_game *game)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = 0;
	while (game->map[i] && game->map[i][j])
		if (game->map[i][j++] != '\n')
			size++;
	game->map_width = size;
}

int	check_map_size(t_game *game)
{
	int	i;
	int	j;
	int	line_size;

	i = 1;
	while (game->map[i])
	{
		j = 0;
		line_size = 0;
		while (game->map[i][j])
			if (game->map[i][j++] != '\n')
				line_size++;
		if (line_size != game->map_width)
			return (0);
		i++;
	}
	return (1);
}

int	save_line(t_game *game, char *line)
{
	char	**temp_map;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->map_height += 1;
	temp_map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!temp_map)
		return (0);
	temp_map[game->map_height] = NULL;
	while (i < game->map_height - 1)
	{
		temp_map[i] = game->map[i];
		i++;
	}
	temp_map[i] = line;
	if (game->map)
		free(game->map);
	game->map = temp_map;
	return (1);
}

int	read_map(t_game *game, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!save_line(game, line))
			break ;
	}
	close(fd);
	line_map_size(game);
	return (1);
}
