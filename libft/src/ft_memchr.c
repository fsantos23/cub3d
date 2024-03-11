/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:23:40 by fsantos2          #+#    #+#             */
/*   Updated: 2023/03/08 13:27:08 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*character;
	size_t			i;

	i = 0;
	character = (unsigned char *)s;
	while (n > 0)
	{
		if (*(unsigned char *)(character + i) == (unsigned char)c)
			return (character + i);
		n--;
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>

int	main(void)
{
    char str[] = "banana";
    char *return1;
    char chr;
    chr = 'n';
    return1  = ft_memchr(str,chr,20);

    printf("%s", return1);
}*/