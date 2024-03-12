/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:32:04 by hlindeza          #+#    #+#             */
/*   Updated: 2024/03/12 12:54:00 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_texture_and_color(char *content)
{
	if (!ft_strncmp(content, "EA", 2) || !ft_strncmp(content, "WE", 2)
		|| !ft_strncmp(content, "SO", 2) || !ft_strncmp(content, "NO", 2))
		return (1);
	else if (!ft_strncmp(content, "F", 1) || !ft_strncmp(content, "C", 1))
		return (2);
	return (0);
}

int	map_size(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
void	print_map(char **map)
{
	int i = -1;
	while (map[++i])
		printf("%s\n", map[i]);
}