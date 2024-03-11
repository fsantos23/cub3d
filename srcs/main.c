/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:15:02 by fsantos2          #+#    #+#             */
/*   Updated: 2024/03/07 18:12:39 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int main(int argc, char **argv)
{
    int fd;
    
    if(argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        init_list(gen());
        parse_map(fd);
        map_size();
        //fazer flood fill do mapa para ser se está correto
        close(fd);
        init_game();
        /* free_everything(); */
    }
}
