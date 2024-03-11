/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:41:26 by fsantos2          #+#    #+#             */
/*   Updated: 2023/10/02 16:57:10 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*str;
	static char	buf[BUFFER_SIZE + 1];

	str = NULL;
	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (!buf[0])
		buf[read(fd, buf, BUFFER_SIZE)] = 0;
	while (buf[0])
	{
		str = gnl_ft_strjoin(str, buf);
		if (!str)
			return (NULL);
		if (newline_checker(buf) == 1)
			break ;
		if (read(fd, buf, 0) < 0)
		{
			free(str);
			return (NULL);
		}
		buf[read(fd, buf, BUFFER_SIZE)] = 0;
	}
	return (str);
}

/* int	main(void)
{
	char *line;
	int fd1;
	fd1 = open("text.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("T1:%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("T1:%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("T1:%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("T1:%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("T1:%s", line);
	free(line);
} */