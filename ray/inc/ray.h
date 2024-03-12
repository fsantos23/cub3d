#ifndef RAY_h
# define RAY_h

# include "../libft/libft.h"
# include "../minilibx_linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <math.h>

# define SCREEN_HEIGHT 512
# define SCREEN_WIDTH 1024

# define ROWS 8
# define COLS 8
# define BLOCK_SIZE 64

typedef struct s_coords
{
    int x;
    int y;
    float angle;
    int view_line_end_x;
    int view_line_end_y;

} t_coords;

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

typedef struct s_ray
{
	void	*mlx;
	void	*mlx_win;
    int 	*map;
	t_data	img;
    t_coords player;
}			t_ray;

t_ray		*ray(void);
int			quit_game(void);
void		put_pixel(int x, int y, int color);
unsigned long rgb_to_hex(int t, int r, int g, int b);
void draw_map(void);
void draw_player(int player_size, int player_x, int player_y);
void move_player(float dx, float dy);
void draw_line(int x0, int y0, int x1, int y1);
void draw_view_line(int player_x, int player_y, float player_angle);
#endif