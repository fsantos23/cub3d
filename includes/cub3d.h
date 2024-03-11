#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <mlx.h>
#include <libft.h>
# include <X11/X.h>

#define PI 3.14159265359
#define SIZE 100

typedef struct s_colors{
    char *no;
    char *so;
    char *we;
    char *ea;
    char *f;
    char *c;
} t_colors;

typedef struct s_player{
    void *p;
    float x;
    float y;
    char ort;
} t_player;

typedef struct s_win {
    void *ptr;
    void *win;
} t_win;

typedef struct s_img{
    void *wall;
    void *floor;
    int h;
    int w;
} t_img;

typedef struct s_gen{
    char **map;
    int x;
    int y;

    t_win *w;
    t_player *pl;
    t_colors *color;
    t_img img;
} t_gen;

//--------------- main struct --------------------//

t_gen *gen(void);
void init_list(t_gen *general);

//--------------- main struct --------------------//

void parse_map(int fd);
int check_type(char **type);

//--------------- utils --------------------//

int iswhitespace(char *input);
void	free_array(char **str);
void free_everything(void);

//----------------- main code -------------------//

void init_game(void);
void map_size(void);

#endif