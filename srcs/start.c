/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:46:43 by fsantos2          #+#    #+#             */
/*   Updated: 2024/03/07 18:13:46 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void xpm_to_file(void)
{
    gen()->img.wall = mlx_xpm_file_to_image(gen()->w->ptr, "../sprites/wall.xpm", &gen()->img.h, &gen()->img.w);
}

void map_coor(void)
{
    int i;
    int j;

    i = 0;
    while(gen()->map[i])
    {
        j = 0;
        while(gen()->map[i][j])
        {
            if(gen()->map[i][j] == '1')
                mlx_put_image_to_window(gen()->w->ptr, gen()->w->win, gen()->img.wall, SIZE * j, SIZE * i);
            /* else if(gen()->map[i][j] == 'S')
            {
                gen()->pl->p = mlx_new_image(gen()->w->ptr, 10, 10);
                mlx_put_image_to_window(gen()->w->ptr, gen()->w->win, gen()->pl->p, SIZE * j, SIZE * i);
            } */
            j++;
        }
        i++;
    }
}

void init_game()
{
    gen()->w->ptr = mlx_init();
    gen()->w->win = mlx_new_window(gen()->w->ptr, 1024, 512, "cub3d");
    xpm_to_file();
    map_coor();
    mlx_loop(gen()->w->ptr);
    mlx_destroy_window(gen()->w->ptr, gen()->w->win);
    mlx_destroy_display(gen()->w->ptr);
}