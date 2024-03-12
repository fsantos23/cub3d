#include "../inc/so_long.h"

char	init_game(t_game *game)
{
	game->map_height = 0;
	game->map_width = 0;
	game->map = NULL;
	game->nmr_moves = 0;
	game->nmr_collectibles = 0;
	game->nmr_exit = 0;
	game->nmr_player = 0;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Nº de args inválido\n");
		return (0);
	}
	t_game game;

	init_game(&game);
	read_map(&game, argv[1]);
	read_characters(&game);
	check_errors(&game);
	//ft_printf("C:%d\nE:%d\nP:%d\n",game.nmr_collectibles, game.nmr_exit, game.nmr_player);
	return 0;
	
}