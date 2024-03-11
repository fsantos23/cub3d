/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:15:10 by fsantos2          #+#    #+#             */
/*   Updated: 2024/03/07 17:44:18 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int iswhitespace(char *input)
{
    int i;

    i = 0;
    while(input[i])
    {
        if(input[i] != ' ' && input[i] != '\n')
            return 1;
        i++;
    }
    return 0;
}

void map_size(void)
{
    int i;
    int j;
    
    i = 0;
    while(gen()->map[i])
    {
        j = 0;
        while(gen()->map[i][j])
            j++;
        i++;
    }
    gen()->x = j - 1;
    gen()->y = i;
}