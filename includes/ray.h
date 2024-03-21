#ifndef RAY_H
# define RAY_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>

# define SCREEN_HEIGHT 640
# define SCREEN_WIDTH 1500


# define QUIT 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

# define PI 3.14159265359
# define P2 PI/2
# define P3 3*PI/2
# define DR 0.0174532925

# define ROWS 8
# define COLS 8
# define BLOCK_SIZE 64

typedef struct s_coords
{
    double posx;
    double posy;
	double pdX;
	double pdY;
	double pa;
	char	pDir;
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

typedef struct s_move
{
	bool left;
	bool right;
	bool up;
	bool down;
	bool look_right;
	bool look_left;
} t_move;

typedef struct s_ray
{
	void	*mlx;
	void	*mlx_win;
    int 	map_x;
	int		map_y;
	double	init_time;
	t_data	img;
    t_coords player;
}			t_ray;

t_ray		*ray(void);

void create_player(void);
int			quit_game(void);
void cleput_pixel(int x, int y, int color);
unsigned long rgb_to_hex(int r, int g, int b);
void draw_map(int check);
void draw_player(int player_size, int player_x, int player_y);
void look_sideways(double pa, char letter);
int move_player(double pdX, double pdY);
void draw_view_line(double player_angle);
void draw_line(int x0, int y0, int x1, int y1, int color);
void draw_floor(int square_size, int x, int y);
void draw_rays(double px, double py);
void other(double player_x, double player_y);
void move_sideways(char letter);
void draw_peripheral(int player_size);
void clear_screen(void *mlx_ptr, void *win_ptr);
void put_pixel(int x, int y, int color);
__uint64_t	get_time(void);
double get_fps(void);

#endif