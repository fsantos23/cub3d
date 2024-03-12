/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:44:27 by hlindeza          #+#    #+#             */
/*   Updated: 2023/04/12 11:44:30 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*newstr;

	if (!s || !*f)
		return (NULL);
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!newstr)
		return (NULL);
	i = -1;
	while (s[++i])
		newstr[i] = f(i, s[i]);
	newstr[i] = '\0';
	return (newstr);
}
