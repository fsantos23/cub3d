#include <cub3d.h>

void put_pixel(int x, int y, int color)
{
	char	*dst;

    dst = ray()->img.addr + (y * ray()->img.line_length + x * (ray()->img.bpp/ 8));
	*(unsigned int *)dst = color;
}

unsigned long rgb_to_hex(int r, int g, int b)
{
    return (r << 16 | g << 8 | b);
}

void draw_walls(int square_size, int x, int y)
{
    
    for(int i = 0; i < square_size; i++)
    {
        for(int j = 0; j < square_size; j++)
            put_pixel(x * square_size + i, y * square_size + j, rgb_to_hex(255, 255, 255)); // Cor do interior
    }   
}

void draw_floor(int square_size, int x, int y)
{
    for(int i = 0; i < square_size; i++)
    {
        for(int j = 0; j < square_size; j++)
            put_pixel(x * square_size + i, y * square_size + j, rgb_to_hex(0, 0, 0)); // Cor do interior
    }
}

double direction_player(char dir)
{
    if(dir == 'S')
        return P2;
    if(dir == 'E')
        return 0;
    if(dir == 'W')
        return PI;
    if(dir == 'N')
        return P3;
    return -1;
}

void draw_map(int check)
{
    int y;
    int x;

    y = 0;
    while(cub()->map_info->map[y])
    {
        x = 0;
        while(cub()->map_info->map[y][x])
        {
            if(cub()->map_info->map[y][x] == '1')
                draw_walls(BLOCK_SIZE, x, y);
            else
                draw_floor(BLOCK_SIZE, x, y);
            if(ft_isplayer(cub()->map_info->map[y][x]) && check == 1)
            {
                ray()->player.posx = x * BLOCK_SIZE;
                ray()->player.posy = y * BLOCK_SIZE;
                ray()->player.pa = direction_player(cub()->map_info->map[y][x]);
                ray()->player.pdX = cos(ray()->player.pa);
                ray()->player.pdY = sin(ray()->player.pa);
            }
            x++;
        }
        y++;
    }
}


void draw_line(int x0, int y0, int x1, int y1, int color) 
{
    double dx = x1 - x0;
    double dy = y1 - y0;
    int pixels = sqrt((dx * dx) + (dy * dy));
    double pixel_x = x0;
    double pixel_y = y0;

    dx /= pixels;
    dy /= pixels; 
    while (pixels)
    {
        put_pixel(pixel_x, pixel_y, color);
        pixel_x += dx;
        pixel_y += dy;
        --pixels;
    }
}

void view_line(int player_size, int player_x, int player_y)
{
    double line_length = player_size;
    int line_x0 = player_x + player_size / 2;
    int line_y0 = player_y + player_size / 2;
    int line_x1 = line_x0 + ray()->player.pdX * line_length;
    double line_y1 = line_y0 + ray()->player.pdY * line_length;
    draw_line(line_x0, line_y0, line_x1, line_y1, rgb_to_hex(255, 255, 0));
}


void draw_player(int player_size, int player_x, int player_y)
{
    for(int i = 0; i < player_size; i++)
    {
        for(int j = 0; j < player_size; j++)
            put_pixel(player_x + i, player_y + j, rgb_to_hex(255, 255, 0)); // Cor amarela
    }
    draw_rays(player_x + player_size / 2, player_y + player_size / 2);
}

int check_pos(double pdX, double pdY) 
{
    double tempx;
    double tempy;

    tempx = (ray()->player.posx + pdX + (BLOCK_SIZE / 6)) / BLOCK_SIZE;
    tempy = (ray()->player.posy + pdY + (BLOCK_SIZE / 6)) / BLOCK_SIZE;
    if((int)tempx < cub()->map_info->width && (int)tempy < cub()->map_info->height && cub()->map_info->map[(int)tempy][(int)tempx] == '1')
        return 0;
    return 1;
}

double get_fps(void)
{
    double frame_time;
    double current;

    current = get_time();
    frame_time = (ray()->init_time - current) / 1000.0;
    ray()->init_time = get_time();
    return frame_time;
}

void change_pos(double pdX, double pdY, char letter)
{
    if (letter == 'W')
    {
        if(!check_pos(pdX, pdY))
            return ;
            printf("HEER\n");
        ray()->player.posx += pdX;
        ray()->player.posy += pdY;
    }
    if (letter == 'S')
    {
        if(!check_pos(-pdX, -pdY))
            return ;
        ray()->player.posx -= pdX;
        ray()->player.posy -= pdY;
    }
    return ;
}

void look_sideways(double pa, char letter)
{
    ray()->player.pa += pa;
    if(ray()->player.pa < 0 && letter == 'L')
        ray()->player.pa += 2 * PI;
    if(ray()->player.pa > 2 * PI && letter == 'R')
        ray()->player.pa -= 2 * PI;
    ray()->player.pdX = cos(ray()->player.pa) * 0.2;
    ray()->player.pdY = sin(ray()->player.pa) * 0.2;
}

void move_sideways(char letter)
{
    double pa;
    double pd_x;
    double pd_y;

    if (letter == 'A')
        pa = ray()->player.pa - P2;
    if (letter == 'D')
        pa = ray()->player.pa + P2;
    pd_x = cos(pa);
    pd_y = sin(pa);
    if (!check_pos(pd_x, pd_y))
        return ;
    ray()->player.posx += pd_x;
    ray()->player.posy += pd_y;
}