#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
	char	**map;
	int map_width;  //L
	int map_height; //A

	int		nmr_moves;
	int		nmr_collectibles;
	int		nmr_exit;
	int		nmr_player;

	void	*initmlx;
	void	*winmlx;

}			t_game;

int			check_limits(t_game *game);
int			check_map_size(t_game *game);
int			read_map(t_game *game, char *file);
void		read_characters(t_game *game);
int			check_errors(t_game *game);
#endif
