#include "../inc/ray.h"

void	put_pixel(int x, int y, int color)
{
	char	*dst;

	dst = ray()->img.addr + (y * ray()->img.line_length + x * (ray()->img.bpp/ 8));
	*(unsigned int *)dst = color;
}

void init_map(void)
{
    int temp_map[] = {
        1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 1, 1, 1, 1, 0, 1,
        1, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 1, 0, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 1, 1, 0, 1, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1
    };
    ray()->map = (int *)malloc(sizeof(int) * ROWS * COLS);
    for(int i = 0; i < ROWS * COLS; i++)
        ray()->map[i] = temp_map[i];
}
void draw_line(int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        put_pixel(x0, y0, rgb_to_hex(0, 255, 255, 0)); // Cor amarela

        if (x0 == x1 && y0 == y1)
            break;

        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void draw_view_line(int player_x, int player_y, float player_angle)
{
    int line_length = 100; // Ajuste conforme necessário
    int end_x = player_x + line_length * cos(player_angle);
    int end_y = player_y + line_length * sin(player_angle);
    draw_line(player_x, player_y, end_x, end_y); // Supondo que você tenha uma função para desenhar uma linha
}
int	quit_game(void)
{
	mlx_destroy_window(ray()->mlx, ray()->mlx_win);
	exit(0);
	return (0);
}

unsigned long rgb_to_hex(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

void draw_walls(int square_size, int x, int y)
{
    
    for(int i = 0; i < square_size; i++)
    {
        for(int j = 0; j < square_size; j++)
            put_pixel(x * square_size + i, y * square_size + j, rgb_to_hex(255, 255, 255, 255)); // Cor do interior
    }   
}

void draw_floor(int square_size, int x, int y)
{
    for(int i = 0; i < square_size; i++)
    {
        for(int j = 0; j < square_size; j++)
            put_pixel(x * square_size + i, y * square_size + j, rgb_to_hex(255,0, 0, 0)); // Cor do interior
    }
}

void draw_map(void)
{

    for(int x = 0; x < ROWS; x++)
    {
        for(int y = 0; y < COLS; y++)
        {
            printf("value: %d\n", y*ROWS+x);
           /* if(ray()->map[y*ROWS+x] == 1)
                draw_walls(BLOCK_SIZE, x, y);
            else
                draw_floor(BLOCK_SIZE, x, y);*/
        }
    }
}

void draw_player(int player_size, int player_x, int player_y)
{
    for(int i = 0; i < player_size; i++)
    {
        for(int j = 0; j < player_size; j++)
            put_pixel(player_x + i, player_y + j, rgb_to_hex(0, 255, 255, 0)); // Cor amarela
    }
}

void move_player(float dx, float dy)
{
    // Calcule a nova posição do jogador
    float new_player_x = ray()->player.x + dx;
    float new_player_y = ray()->player.y + dy;

}