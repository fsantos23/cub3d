#include <cub3d.h>

t_ray	*ray(void)
{
	static t_ray	ray;
	return (&ray);
}

void	move_player(void)
{
	if (ray()->move.look_left == true)
        look_sideways(-0.05, 'L');
    if (ray()->move.look_right == true)
        look_sideways(0.05, 'R');
    if (ray()->move.up == true)
        change_pos(ray()->player.pdX, ray()->player.pdY, 'W');
    if (ray()->move.down == true)
        change_pos(ray()->player.pdX, ray()->player.pdY, 'S');
    if(ray()->move.left == true)
        move_sideways('A');
    if(ray()->move.right == true)
        move_sideways('D');
}

int run_game(void)
{
    move_player();
    ft_memset(ray()->img.addr, 0, (SCREEN_HEIGHT  * SCREEN_WIDTH * ray()->img.bpp) / 8);
    draw_player(BLOCK_SIZE / 4, ray()->player.posx, ray()->player.posy);
    draw_map(0);
	mlx_put_image_to_window(ray()->mlx, ray()->mlx_win, ray()->img.ptr, 0, 0);
	return (0);
}

int	key_press(int keycode)
{
    if (keycode == LEFT)
        ray()->move.look_left = true;
    if (keycode == RIGHT)
        ray()->move.look_right = true;
    if (keycode == W)
        ray()->move.up = true;
    if (keycode == S)
        ray()->move.down = true;
    if (keycode == A)
        ray()->move.left = true;
    if (keycode == D)
        ray()->move.right = true;
    exit_game(keycode);
	return (0);
}
int key_release(int keycode)
{
    if (keycode == LEFT)
        ray()->move.look_left = false;
    if (keycode == RIGHT)
        ray()->move.look_right = false;
    if (keycode == W)
        ray()->move.up = false;
    if (keycode == S)
        ray()->move.down = false;
    if (keycode == A)
        ray()->move.left = false;
    if (keycode == D)
        ray()->move.right = false;
	return (0);
}

void	init(void)
{
    ray()->init_time = get_time();
	ray()->img.ptr = mlx_new_image(ray()->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	ray()->img.addr = mlx_get_data_addr(ray()->img.ptr, &ray()->img.bpp,
			&ray()->img.line_length, &ray()->img.endian);
	draw_map(1);
    draw_player(BLOCK_SIZE / 4, ray()->player.posx, ray()->player.posy);
	mlx_put_image_to_window(ray()->mlx, ray()->mlx_win, ray()->img.ptr, 0, 0);
}

void define(void)
{
	ray()->move.down = false;
	ray()->move.up = false;
	ray()->move.left = false;
	ray()->move.right = false;
	ray()->move.look_left = false;
	ray()->move.look_right = false;
}

void create_player(void)
{
	define();
    printf("width : %zu, height : %zu\n", cub()->map_info->width, cub()->map_info->height);
	ray()->mlx = mlx_init();
	ray()->mlx_win = mlx_new_window(ray()->mlx, (SCREEN_WIDTH), (SCREEN_HEIGHT), "cub3d");
	init();
    mlx_hook(ray()->mlx_win, 02, 1L << 0, key_press, NULL);
    mlx_hook(ray()->mlx_win, 03, 1L << 1, key_release, NULL);
	mlx_hook(ray()->mlx_win, 17, 0, &quit_game, NULL);
	mlx_loop_hook(ray()->mlx, &run_game, NULL);
    mlx_loop(ray()->mlx);
}
