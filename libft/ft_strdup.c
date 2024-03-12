/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:43:42 by hlindeza          #+#    #+#             */
/*   Updated: 2023/04/12 11:43:44 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		i;

	i = -1;
	cpy = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (cpy == NULL)
		return (0);
	while (src[++i])
		cpy[i] = src[i];
	cpy[i] = '\0';
	return (cpy);
}
