/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:35:16 by hlindeza          #+#    #+#             */
/*   Updated: 2024/03/12 15:36:32 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**map;
	char	**textures;
}			t_map;

typedef struct s_data
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		x;
	int		y;
	int		endian;
}			t_data;

typedef struct s_cub
{
	void	*initmlx;
	void	*winmlx;
	
	t_map	*map_info;
}			t_cub;

t_cub		*cub(void);

void		print_map(char **map);
char		**save_map(char **content);
char		**save_textures(char **content);
int			map_size(char **map);
void		free_matriz(char ***mrtz);
int			check_texture_and_color(char *content);

void		parser(char *filename);
int			check_file_extension(char *filename, char *extension);
char		**save_file_content(char *file);

#endif
