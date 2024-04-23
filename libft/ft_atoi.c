/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:32:53 by hlindeza          #+#    #+#             */
/*   Updated: 2023/04/12 11:32:55 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_space_sign(const char *str, int *index)
{
	int	i;
	int	signal;

	signal = 0;
	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] != '\0' && (str[i] == '-'))
	{
		signal++;
		i++;
	}
	else if (str[i] != '\0' && (str[i] == '+'))
		i++;
	*index = i;
	return (signal);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	multi;
	int	num;

	num = 0;
	multi = 1;
	if (ft_space_sign(str, &i) % 2 == 1)
		multi = -1;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	num *= multi;
	return (num);
}
