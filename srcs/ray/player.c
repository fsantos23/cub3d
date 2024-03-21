#include <cub3d.h>

t_ray	*ray(void)
{
	static t_ray	ray;
	return (&ray);
}

int key_press_down(int keycode, void *param)
{
    (void)param;
    if (keycode == LEFT)
        look_sideways(-0.1, 'L');
    else if (keycode == RIGHT)
        look_sideways(0.1, 'R');
    else if (keycode == W)
    {
        if(!move_player(ray()->player.pdX, ray()->player.pdY))
            return 0;
    }
    else if (keycode == S)
    {
        if(!move_player(-ray()->player.pdX, -ray()->player.pdY))
            return 0;
    }
    else if(keycode == A)
        move_sideways('A');
    else if(keycode == D)
        move_sideways('D');
    else if (keycode == QUIT)
    {
        quit_game();
    }
    ft_memset(ray()->img.addr, 0, (SCREEN_HEIGHT  * SCREEN_WIDTH * ray()->img.bpp) / 8);
    draw_map(0);
    draw_player(BLOCK_SIZE / 4, ray()->player.posx, ray()->player.posy);
	mlx_put_image_to_window(ray()->mlx, ray()->mlx_win, ray()->img.ptr, 0, 0);
}

/* void check_key(int keycode, bool value)
{
    if (keycode == LEFT)
        ray()->move.look_left = value;
    else if (keycode == RIGHT)
        ray()->move.look_right = value;
    else if (keycode == W)
        ray()->move.up = value;
    else if (keycode == S)
        ray()->move.up = value;
    else if (keycode == A)
        ray()->move.left = value;
    else if (keycode == D)
        ray()->move.right = value;
    
}

void bool_key(int keycode)
{
    while (1) {
        if (!ray()->move.look_left && !ray()->move.look_right && !ray()->move.up && \
            !ray()->move.down && !ray()->move.left && !ray()->move.right) {
            break ;
        }
        if (ray()->move.look_left)
            key_press_down(LEFT);
        if (ray()->move.look_right)
            key_press_down(RIGHT);
        if (ray()->move.up)
            key_press_down(W);
        if (ray()->move.down)
            key_press_down(S);
        if (ray()->move.left)
            key_press_down(A);
        if (ray()->move.right)
            key_press_down(D);
    }
} */

/* int key_press(int keycode, int up_down)
{
    printf("%d\n", up_down);
    if(up_down == 2)
    {
        check_key(keycode, true);
        bool_key(keycode);
    }
    else if(up_down == 3)
        check_key(keycode, false);
} */

void	init(void)
{
    ray()->init_time = get_time();
	ray()->img.ptr = mlx_new_image(ray()->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	ray()->img.addr = mlx_get_data_addr(ray()->img.ptr, &ray()->img.bpp,
			&ray()->img.line_length, &ray()->img.endian);
	draw_map(1);
    draw_player(BLOCK_SIZE / 6, ray()->player.posx, ray()->player.posy);
	mlx_put_image_to_window(ray()->mlx, ray()->mlx_win, ray()->img.ptr, 0, 0);
}

void create_player(void)
{
	ray()->mlx = mlx_init();
	ray()->mlx_win = mlx_new_window(ray()->mlx, (SCREEN_WIDTH), (SCREEN_HEIGHT), "cub3d");
	init();
    mlx_hook(ray()->mlx_win, 02, 1L << 0, &key_press_down, ray());
    /* mlx_hook(ray()->mlx_win, 03, 1L << 1, &key_press, (void *)03); */
	mlx_hook(ray()->mlx_win, 17, 0, &quit_game, NULL);
	mlx_loop(ray()->mlx);
}
