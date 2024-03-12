/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrique <henrique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:25:10 by hlindeza          #+#    #+#             */
/*   Updated: 2023/05/15 22:27:20 by henrique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexa(unsigned int nbr, long int *chr_total, int loworup)
{
	if (nbr >= 16)
		ft_puthexa(nbr / 16, chr_total, loworup);
	if (loworup)
		ft_putchar(HEX_UPPER[nbr % 16], chr_total);
	else
		ft_putchar(HEX_LOWER[nbr % 16], chr_total);
}
