/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:15:06 by fsantos2          #+#    #+#             */
/*   Updated: 2024/03/07 18:14:54 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void print_sprites(void)
{
    printf("%s\n", gen()->color->no);
    printf("%s\n", gen()->color->so);
    printf("%s\n", gen()->color->we);
    printf("%s\n", gen()->color->ea);
    printf("%s\n", gen()->color->f);
    printf("%s\n", gen()->color->c);
}

int check_str(char *str)
{
    char **type;

    type = ft_split(str, ' ');
    if(!check_type(type))
        return 0;
    return 1;
}

void map_checker(char *str, int *i)
{
    if(!iswhitespace(str))
        return ;
    gen()->map[*i] = ft_calloc(ft_strlen(str) + 1, sizeof(char));
    gen()->map[*i] = str;
    (*i)++;
}

void parse_map(int fd)
{
    char *str;
    int i = 0;

    while(1)
    {
        str = get_next_line(fd);
        if(!str)
            break ;
        if(!check_str(str))
            map_checker(str, &i);
        free(str);
    }
}