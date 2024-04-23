/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:51:31 by hlindeza          #+#    #+#             */
/*   Updated: 2024/03/20 11:51:44 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	print_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		printf("%s\n", map[i]);
}

int	ft_have_only_number(char *content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		if (!ft_isdigit(content[i]) && !ft_isspace(content[i]))
			return (0);
		i++;
	}
	return (1);
}

int	texture_color_size(char **content, int flag)
{
	char	**line;
	int		i;
	int		size;

	size = 0;
	line = NULL;
	i = -1;
	while (content[++i])
	{
		if (ft_have_only_number(content[i]))
			break ;
		line = ft_split(content[i], ' ');
		if (flag && ft_strlen(line[0]) == 2)
			size++;
		else if (!flag && ft_strlen(line[0]) == 1)
			size++;
		free_matriz(&line);
	}
	return (size);
}

char	**split_trim(char *input, char c)
{
	char	**content;
	int		i;
	char	*tmp;

	i = -1;
	content = ft_split(input, c);
	while (content[++i])
	{
		tmp = ft_strtrim(content[i], " \t");
		free(content[i]);
		content[i] = tmp;
	}
	return (content);
}

void	print_msg_error(char *msg, int *flag)
{
	printf("%s\n", msg);
	*flag = 1;
}
