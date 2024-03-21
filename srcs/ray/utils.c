/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:14:51 by fsantos2          #+#    #+#             */
/*   Updated: 2024/03/18 13:15:03 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

__uint64_t	get_time(void)
{
	struct timeval	mili;

	gettimeofday(&mili, NULL);
	return (mili.tv_sec * 1000 + mili.tv_usec / 1000);
}