#include "../inc/ray.h"

t_ray	*ray(void)
{
	static t_ray	ray;
	return (&ray);
}

int key_press(int keycode, void *param)
{
    if (keycode == 97)
        move_player(-5, 0);
    else if (keycode == 100)
        move_player(5, 0);
    else if (keycode == 119)
        move_player(0, -5);
    else if (keycode == 115)
        move_player(0, 5);
    else if (keycode == 65307)
        quit_game();
    return 0;
}
void	init(void)
{   
    ray()->player.x = 300;
    ray()->player.y = 300;
	ray()->img.ptr = mlx_new_image(ray()->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	ray()->img.addr = mlx_get_data_addr(ray()->img.ptr, &ray()->img.bpp,
			&ray()->img.line_length, &ray()->img.endian);
	draw_map();
    draw_player(16, ray()->player.x, ray()->player.y);
	mlx_put_image_to_window(ray()->mlx, ray()->mlx_win, ray()->img.ptr, 0, 0);
}
int	main(void)
{
	ray()->mlx = mlx_init();
	ray()->mlx_win = mlx_new_window(ray()->mlx, (SCREEN_WIDTH), (SCREEN_HEIGHT),"Raycasting");
	init();
    mlx_key_hook(ray()->mlx_win, &key_press, ray());
	mlx_hook(ray()->mlx_win, 17, 0, &quit_game, NULL);
	mlx_loop(ray()->mlx);
	return (0);
}
