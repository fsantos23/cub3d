/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:42:12 by fsantos2          #+#    #+#             */
/*   Updated: 2023/04/18 17:16:03 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_arg(va_list args, const char string)
{
	int	count;

	count = 0;
	if (string == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (string == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (string == 'i' || string == 'd')
		count += ft_putnbr(va_arg(args, int));
	else if (string == '%')
		count += ft_putchar('%');
	else if (string == 'x' || string == 'X')
		count += ft_printhex(va_arg(args, unsigned int), string);
	else if (string == 'u')
		count += ft_putnbru(va_arg(args, unsigned int));
	else if (string == 'p')
		count += ft_printptr(va_arg(args, unsigned long long));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += put_arg(args, str[i + 1]);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
