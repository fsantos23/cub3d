/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:35:16 by hlindeza          #+#    #+#             */
/*   Updated: 2024/03/21 16:31:19 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
# include <mlx.h>
# include <ray.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <math.h>
#include <parser.h>

typedef struct s_cub
{
	void	*initmlx;
	void	*winmlx;

	t_map	*map_info;
}			t_cub;

t_cub		*cub(void);

#endif
