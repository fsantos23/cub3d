/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:00:02 by hlindeza          #+#    #+#             */
/*   Updated: 2024/03/21 16:07:45 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_cub	*cub(void)
{
	static t_cub   cub;

	return (&cub);
}

int	main(int argc, char **argv)
{

	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		return (0);
	}
	if(!init_map_struct(argv[1]))
		create_player();
	free_struct_map(cub()->map_info);
	return (0);
}
