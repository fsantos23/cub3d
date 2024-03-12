/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrique <henrique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:23:27 by hlindeza          #+#    #+#             */
/*   Updated: 2023/05/20 01:57:51 by henrique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ftgnl_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i + (str[i] == '\n'));
}

char	*ftgnl_strjoin(char *s1, char *s2)
{
	int		size;
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = -1;
	size = ftgnl_strlen(s1) + ftgnl_strlen(s2);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[++j])
	{
		str[i++] = s2[j];
		if (s2[j] == '\n')
			break ;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

void	ft_clean_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
		buffer[i++] = 0;
}

int	ft_check_buffer(char *buffer)
{
	int	flag;
	int	i;
	int	j;

	flag = 0;
	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (flag)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			flag = 1;
		buffer[i++] = '\0';
	}
	return (flag);
}
