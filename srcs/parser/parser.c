/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:39:26 by hlindeza          #+#    #+#             */
/*   Updated: 2024/03/20 13:17:22 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	parse_map(char **map)
{
	int	rt;

	rt = 0;
	if (check_characters(map))
		print_msg_error("Error, Invalid characters", &rt);
	else if (check_close_map(map))
		print_msg_error("Error, Map not closed", &rt);
	else if (check_multi_player(map) == -1)
		print_msg_error("Error, no players", &rt);
	else if (check_multi_player(map))
		print_msg_error("Error, Multiple players", &rt);
	return (rt);
}

int	parse_textures_colors(char **content)
{
	int	rt;

	rt = 0;
	if (check_textures_color_id(content))
		print_msg_error("Error, Invalid textures or colors", &rt);
	else if (check_multi_identifier(cub()->map_info->textures,
			cub()->map_info->colors))
		print_msg_error("Error, Multi texture or color identifier", &rt);
	else if (matriz_size(cub()->map_info->textures) != 4
		|| matriz_size(cub()->map_info->colors) != 2)
		print_msg_error("Error, Invalid number of textures or colors", &rt);
	else if (check_rgb_color(cub()->map_info->colors))
		print_msg_error("Error, Invalid RGB color", &rt);
	else if (check_textures_path(cub()->map_info->textures))
		print_msg_error("Error, Invalid texture path", &rt);
	return (rt);
}
