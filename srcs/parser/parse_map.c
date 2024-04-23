/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:34:35 by hlindeza          #+#    #+#             */
/*   Updated: 2024/03/20 11:47:35 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_check_unclosed(char **map, char c, int i, int j)
{
	if (c == '0' && ((map[i][j] != '\0' && map[i][j] == ' ')
			|| map[i][j] == '\0'))
		return (1);
	return (0);
}

int	first_last_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (1);
	}
	return (0);
}

int	mid_line(char **map, int i)
{
	int	j;

	j = -1;
	while (map[i][++j])
	{
		if (ft_check_unclosed(map, map[i][j], i + 1, j)
			|| ft_check_unclosed(map, map[i][j], i - 1, j)
			|| ft_check_unclosed(map, map[i][j], i, j + 1)
			|| ft_check_unclosed(map, map[i][j], i, j - 1))
			return (1);
	}
	return (0);
}

int	check_close_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (i == 0 || i == matriz_size(map) - 1)
		{
			if (first_last_line(map[i]))
				return (1);
		}
		else
		{
			if (mid_line(map, i))
				return (1);
		}
	}
	return (0);
}

int	check_multi_player(char **map)
{
	int	amount;
	int	i;
	int	j;

	amount = -1;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_isplayer(map[i][j]))
				amount++;
		}
	}
	return (amount);
}


