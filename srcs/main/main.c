/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:00:02 by hlindeza          #+#    #+#             */
/*   Updated: 2024/03/12 15:59:04 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_cub	*cub(void)
{
	static t_cub   cub;

	return (&cub);
}
int	main(int argc, char **argv)
{
	

	/*if (argc == 2)
		parser(argv[1]);
	else
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);*/
	parser(argv[1]);
	//print_map(cub()->map_info->textures);
	char **split = ft_split(cub()->map_info->map[12], ' ');
	print_map(split);

	return (0);
}
