/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:42:32 by fsantos2          #+#    #+#             */
/*   Updated: 2023/04/18 17:14:28 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lenhex(unsigned int i)
{
	int	count;

	count = 0;
	while (i)
	{
		count++;
		i /= 16;
	}
	return (count);
}

static int	ft_puthex(unsigned int i, const char variavel)
{
	int	count;

	count = 0;
	if (i >= 16)
	{
		ft_puthex(i / 16, variavel);
		ft_puthex(i % 16, variavel);
	}
	else
	{
		if (i <= 9)
			count += ft_putchar(i + '0');
		else
		{
			if (variavel == 'x')
				count += ft_putchar((i - 10) + 'a');
			else if (variavel == 'X')
				count += ft_putchar((i - 10) + 'A');
		}
	}
	return (count);
}

int	ft_printhex(unsigned int i, const char variavel)
{
	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		ft_puthex(i, variavel);
	return (ft_lenhex(i));
}
