/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:12:13 by fsantos2          #+#    #+#             */
/*   Updated: 2024/04/16 13:04:45 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	quit_game(void)
{
	mlx_destroy_window(ray()->mlx, ray()->mlx_win);
	exit(0);
	return (0);
}

int exit_game(int keycode)
{
    if (keycode == QUIT)
        quit_game();
    return (0);
}