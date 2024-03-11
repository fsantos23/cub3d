/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:14:42 by fsantos2          #+#    #+#             */
/*   Updated: 2024/03/07 18:03:54 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
        printf("HERERE\n");
		i++;
	}
	free(str);
}

void free_everything(void)
{
    free(gen()->color->c);
    free(gen()->color->we);
    free(gen()->color->no);
    free(gen()->color->so);
    free(gen()->color->ea);
    free(gen()->color->f);
    free(gen()->color);
    free(gen()->map);
}