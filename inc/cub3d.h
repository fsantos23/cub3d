/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:35:16 by hlindeza          #+#    #+#             */
/*   Updated: 2024/04/24 11:50:13 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SCREEN_HEIGHT 720
# define SCREEN_WIDTH 1280

# define MOVE_SPEED 0.015
# define ROTATION_SPEED 0.012

typedef struct s_values
{
	double		rayDirX;
	double		rayDirY;

	double		dirX;
	double		dirY;

	double		posX;
	double		posY;

	double		planeX;
	double		planeY;

	double		deltaDistX;
	double		deltaDistY;

	int			stepX;
	int			stepY;

	double		sideDistX;
	double		sideDistY;

	double		WallDist;

	int			mapX;
	int			mapY;

	int			lineLength;

	int			drawStart;
	int			drawEnd;

	int			side;
	int			hit;

}				t_values;

typedef struct s_map
{
	char		**map;
	char		**textures;
	char		**colors;

	int			floor_color;
	int			ceil_color;
	size_t		height;
	size_t		width;

	int			x;
	int			y;
	char		pDir;
}				t_map;

typedef struct s_hooks
{
	int			a;
	int			w;
	int			s;
	int			d;
	int			arr_right;
	int			arr_left;

}				t_hooks;

typedef struct s_data
{
	void		*ptr;
	char		*addr;
	int			bpp;
	int			line_length;
	int			x;
	int			y;
	int			endian;
}				t_data;

typedef struct s_cub
{
	void		*initmlx;
	void		*winmlx;
	t_data		img;
	t_values	v;
	t_map		*map_info;
	t_hooks		hook;
}				t_cub;

/* main/main.c */
t_cub			*cub(void);
void			init_tmap(void);
void			set_player_dir(void);

/* aux/aux.c */
int				ft_istexture_or_color(char *content);
int				ft_ischaracters(char content);
int				ft_isplayer(char content);
int				matriz_size(char **content);
int				ft_isspace(int c);

/* aux/aux2.c */
void			print_map(char **map);
int				texture_color_size(char **content, int flag);
int				ft_have_only_number(char *content);
char			**split_trim(char *input, char c);
void			print_msg_error(char *msg, int *flag);

/* aux/aux3.c */
void			put_pixel(int x, int y, int color);
unsigned long	rgb_to_hex(int r, int g, int b);
void			color_convert_init(void);
void			draw_floor(void);
void			draw_ceiling(void);

/* aux/free.c */
void			free_matriz(char ***mrtz);
void			free_struct_map(t_map *map);

/* hooks/hook.c */
void			hooks(void);
int				key_release(int keycode);
int				key_press(int keycode);
int				quit_game(void);

/* hooks/move_formulas.c */
void			move_w_or_s(char c);
void			move_a_or_d(char c);
void			rotate(char c);

/* parser/init.c */
void			save_stuff(char **content);
void			save_rgb(int *r, int *g, int *b, char **rgb);
int				init_map_struct(char *file);
int				check_num(char *str);

/* parser/parse_texture_colors.c */
int				check_file_extension(char *filename, char *extension);
int				check_characters(char **map);
int				check_textures_color(char **content);
int				check_textures_color_id(char **content);
int				check_rgb_color(char **colors);

/* parser/parse_map.c */
int				ft_check_unclosed(char **map, char c, int i, int j);
int				first_last_line(char *line);
int				mid_line(char **map, int i);
int				check_close_map(char **map);
int				check_multi_player(char **map);

/* parser/parse_texture_colors.c */
int				check_identifier(char **content, int id);
int				multi_identifier(char **content, char *identifier);
int				check_multi_identifier(char **textures, char **color);
int				check_textures_path(char **textures);

/* parser/parser.c */
int				parse_map(char **map);
int				parse_textures_colors(char **content);

/* parser/save_data.c */
void			save_player(char **map);
void			save_map(char **content);
char			**save_file_content(char *file);
void			save_textures(char **content);
void			save_colors(char **content);

/* raycast/raycast_formulas.c */
void			calculate_ray_pos(int x);
void			calculate_initial_sideDist(void);
void			dda_loop(void);
void			wall_height(void);
void			draw_wall_x(int x);

/* raycast/raycast.c */
void			init_graph(void);
#endif
