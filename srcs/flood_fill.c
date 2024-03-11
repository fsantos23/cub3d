/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:14:50 by fsantos2          #+#    #+#             */
/*   Updated: 2024/03/07 15:14:51 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	flood_fill(int x, int y, char **map, int *counter)
{
	if (map[y][x] == 'E' || map[y][x] == 'C')
		*counter += 1;
	if (map[y][x] == 'E')
	{
		map[y][x] = '1';
		return ;
	}
	map[y][x] = 'F';
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'F')
		flood_fill(x + 1, y, map, counter);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'F')
		flood_fill(x - 1, y, map, counter);
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'F')
		flood_fill(x, y + 1, map, counter);
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'F')
		flood_fill(x, y - 1, map, counter);
}