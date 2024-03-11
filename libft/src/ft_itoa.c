/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:21:19 by fsantos2          #+#    #+#             */
/*   Updated: 2023/03/15 10:59:56 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_length(long long n, char *str)
{
	if (n >= 10)
		str = ft_length(n / 10, str);
	*str++ = (n % 10) + '0';
	*str = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	char	str[15];

	if (n < 0)
	{
		str[0] = '-';
		ft_length((long long)n * -1, &str[1]);
	}
	else
		ft_length(n, str);
	return (ft_substr(str, 0, (ft_strlen(str))));
}

/* #include <stdio.h>

int	main(void)
{
    long int i;

    i = -125474;
    printf("%s", ft_itoa(i));
} */