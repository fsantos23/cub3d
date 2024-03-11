/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:02:40 by fsantos2          #+#    #+#             */
/*   Updated: 2023/04/18 17:39:02 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int i)
{
	write(1, &i, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static int	string_writer(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += string_writer(n / 10);
	}
	count += write(1, &"0123456789"[n % 10], 1);
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		count += write(1, "-", 1);
		n *= -1;
	}
	count += string_writer(n);
	return (count);
}

int	ft_putnbru(unsigned int i)
{
	int	count;

	count = 0;
	count += string_writer(i);
	return (count);
}
