/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:44:50 by fsantos2          #+#    #+#             */
/*   Updated: 2023/04/18 17:14:17 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putstr(char *str);
int	ft_putchar(int i);
int	ft_putnbr(int n);
int	ft_printhex(unsigned int i, const char variavel);
int	ft_putnbru(unsigned int i);
int	ft_printptr(unsigned long long i);

#endif
