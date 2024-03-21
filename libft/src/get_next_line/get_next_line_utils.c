/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:12:24 by fsantos2          #+#    #+#             */
/*   Updated: 2023/10/02 16:51:08 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i + (s[i] == '\n'));
}

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	char	*string;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	string = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!string)
		return (NULL);
	while (s1 && s1[j])
		string[j++] = s1[i++];
	i = 0;
	while (s2[i] && s2[i] != '\n')
		string[j++] = s2[i++];
	if (s2[i] == '\n')
		string[j++] = '\n';
	string[j] = '\0';
	free(s1);
	return (string);
}

int	newline_checker(char *buf)
{
	int	i;
	int	j;
	int	newline;

	i = 0;
	j = 0;
	newline = 0;
	while (buf[i])
	{
		if (newline)
			buf[j++] = buf[i];
		if (buf[i] == '\n')
			newline = 1;
		buf[i++] = '\0';
	}
	return (newline);
}
