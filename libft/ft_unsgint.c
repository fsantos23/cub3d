/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsgint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrique <henrique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:53:01 by hlindeza          #+#    #+#             */
/*   Updated: 2023/05/15 22:27:10 by henrique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_unsgint(unsigned int nbr, long int *chr_total)
{
	if (nbr > 9)
	{
		ft_unsgint(nbr / 10, chr_total);
		ft_unsgint(nbr % 10, chr_total);
	}
	else
		ft_putchar(nbr + '0', chr_total);
}
