/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:01:05 by fsantos2          #+#    #+#             */
/*   Updated: 2023/04/19 13:09:20 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lenptr(unsigned long long i)
{
	int	count;

	count = 0;
	while (i > 0)
	{
		count++;
		i /= 16;
	}
	return (count);
}

static void	ft_putptr(unsigned long long i)
{
	if (i >= 16)
	{
		ft_putptr(i / 16);
		ft_putptr(i % 16);
	}
	else
	{
		if (i <= 9)
			ft_putchar(i + '0');
		else
			ft_putchar((i - 10) + 'a');
	}
}

int	ft_printptr(unsigned long long i)
{
	int	count;

	count = 0;
	if (i == 0)
		count += write(1, "(nil)", 5);
	else
	{
		count += write(1, "0x", 2);
		ft_putptr(i);
		count += ft_lenptr(i);
	}
	return (count);
}
