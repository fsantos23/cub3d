/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:24:03 by fsantos2          #+#    #+#             */
/*   Updated: 2023/04/19 08:34:49 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_counter(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		i++;
	}
	return (count);
}

char	*strings(char const *s, size_t start, size_t end)
{
	char	*str;

	str = (char *)malloc(end - start + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, end - start);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;
	size_t	a;
	size_t	index;

	strs = (char **)malloc((word_counter(s, c) + 1) * sizeof(char *));
	i = 0;
	a = 0;
	if (!s || !strs)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		index = i;
		while (s[i] != c && s[i])
			i++;
		strs[a] = strings(s, index, i + 1);
		a++;
	}
	strs[a] = 0;
	return (strs);
}

/* int main()
{
    char str[] = "Hello,   how    are  you  ?";
    char **temp;

    temp = ft_split(str, ' ');
    printf("%s", temp[1]);
} */