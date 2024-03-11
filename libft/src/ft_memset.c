/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:23:59 by fsantos2          #+#    #+#             */
/*   Updated: 2023/03/08 13:29:20 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*string;
	size_t			i;

	i = 0;
	string = (unsigned char *)b;
	while (len > 0)
	{
		string[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (b);
}
