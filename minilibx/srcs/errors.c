/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrique <henrique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:35:07 by henrique          #+#    #+#             */
/*   Updated: 2023/05/22 15:46:33 by henrique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


void read_characters(t_game *game)
{
	int i;
	int j;

	i = 0;
	while(++i < game->map_height)
	{
		j = -1;
		while(++j < game->map_width)
		{
			if(game->map[i][j] == 'C')
				game->nmr_collectibles++;
			else if(game->map[i][j] == 'E')
				game->nmr_exit++;
			else if(game->map[i][j] == 'P')
				game->nmr_player++;
		}
	}
}

int	check_errors(t_game *game)
{
	int	error;

	error = 1;
	if (!check_map_size(game) || (game->map_height == game->map_width))
		ft_printf("Error(%d), the map is not rectangle\n", error--);
	else if (!check_limits(game))
		ft_printf("Error(%d), the map must be surrounded by walls!\n", error--);
	else if(game->nmr_collectibles < 1)
		ft_printf("Error(%d), the map must have at least 1 collectible !\n", error--);
	else if(game->nmr_exit != 1)
		ft_printf("Error(%d), the map must have only/at least 1 exit!\n", error--);
	else if(game->nmr_player != 1)
		ft_printf("Error(%d), the map must have only/at least 1 player!\n", error--);
	return (error);
}
