/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:14:58 by fsantos2          #+#    #+#             */
/*   Updated: 2024/03/07 17:30:10 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_gen	*gen(void)
{
	static t_gen   gen;

	return (&gen);
}

void init_list(t_gen *gen)
{
    gen->map = ft_calloc(sizeof(char *), 300);
    gen->color = ft_calloc(1, sizeof(t_colors));
}

int check_type(char **type)
{
    if(!ft_strncmp("NO", type[0], ft_strlen(type[0])))
    {
        gen()->color->no = ft_calloc(ft_strlen(type[1]) + 1, sizeof(char));
        gen()->color->no = type[1];
    }
    else if(!ft_strncmp("SO", type[0], ft_strlen(type[0])))
    {
        gen()->color->so = ft_calloc(ft_strlen(type[1]) + 1, sizeof(char));
        gen()->color->so = type[1];
    }
    else if(!ft_strncmp("WE", type[0], ft_strlen(type[0])))
    {
        gen()->color->we = ft_calloc(ft_strlen(type[1]) + 1, sizeof(char));
        gen()->color->we = type[1];
    }
    else if(!ft_strncmp("EA", type[0], ft_strlen(type[0])))
    {
        gen()->color->ea = ft_calloc(ft_strlen(type[1]) + 1, sizeof(char));
        gen()->color->ea = type[1];
    }
    else if(!ft_strncmp("F", type[0], ft_strlen(type[0])))
    {
        gen()->color->f = ft_calloc(ft_strlen(type[1]) + 1, sizeof(char));
        gen()->color->f = type[1];
    }
    else if(!ft_strncmp("C", type[0], ft_strlen(type[0])))
    {
        gen()->color->c = ft_calloc(ft_strlen(type[1]) + 1, sizeof(char));
        gen()->color->c = type[1];
    }
    else
        return 0;
    return 1;
}