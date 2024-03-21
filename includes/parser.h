/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:55:13 by fsantos2          #+#    #+#             */
/*   Updated: 2024/03/21 16:27:53 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

typedef struct s_map
{
	char	**map;
	char	**textures;
	char	**colors;

	size_t	height;
	size_t	width;
}			t_map;

/* aux/aux.c */
int			ft_istexture_or_color(char *content);
int			ft_ischaracters(char content);
int			ft_isplayer(char content);
int			matriz_size(char **content);
int			ft_isspace(int c);

/* aux/aux2.c */
void		print_map(char **map);
int			texture_color_size(char **content, int flag);
int			ft_have_only_number(char *content);
char		**split_trim(char *input, char c);
void		print_msg_error(char *msg, int *flag);

/* aux/free.c */
void		free_matriz(char ***mrtz);
void		free_struct_map(t_map *map);

/* parser/init.c */
void		save_stuff(char **content);
void		save_rgb(int *r, int *g, int *b, char **rgb);
int			init_map_struct(char *file);
int			check_num(char *str);

/* parser/parse_texture_colors.c */
int			check_file_extension(char *filename, char *extension);
int			check_characters(char **map);
int			check_textures_color(char **content);
int			check_textures_color_id(char **content);
int			check_rgb_color(char **colors);

/* parser/parse_map.c */
int			ft_check_unclosed(char **map, char c, int i, int j);
int			first_last_line(char *line);
int			mid_line(char **map, int i);
int			check_close_map(char **map);
int			check_multi_player(char **map);

/* parser/parse_texture_colors.c */
int			check_identifier(char **content, int id);
int			multi_identifier(char **content, char *identifier);
int			check_multi_identifier(char **textures, char **color);
int			check_textures_path(char **textures);

/* parser/parser.c */
int			parse_map(char **map);
int			parse_textures_colors(char **content);

/* parser/save_data.c */
void		save_player(char **map);
void		save_map(char **content);
char		**save_file_content(char *file);
void		save_textures(char **content);
void		save_colors(char **content);

#endif