/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:32:04 by hlindeza          #+#    #+#             */
/*   Updated: 2024/03/20 11:51:47 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_istexture_or_color(char *content)
{
	if (!ft_strncmp(content, "EA", 2) || !ft_strncmp(content, "WE", 2)
		|| !ft_strncmp(content, "SO", 2) || !ft_strncmp(content, "NO", 2))
		return (1);
	else if (!ft_strncmp(content, "F", 1) || !ft_strncmp(content, "C", 1))
		return (2);
	return (0);
}

int	ft_ischaracters(char content)
{
	if (content != 'N' && content != 'S' && content != 'E' && content != 'W'
		&& content != '0' && content != '1' && content != ' '
		&& content != '\t')
		return (0);
	return (1);
}

int	ft_isplayer(char content)
{
	if (content == 'N' || content == 'S' || content == 'E' || content == 'W')
		return (1);
	return (0);
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	matriz_size(char **content)
{
	int	i;

	i = 0;
	while (content[i])
		i++;
	return (i);
}
