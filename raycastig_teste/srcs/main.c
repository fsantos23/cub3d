
#include "../inc/ray.h"


#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24
#define moveSpeed 0.1
#define rotateSpeed 0.05

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

typedef struct s_vars {
    void *mlx;
    void *win;
}              t_vars;

double posX = 22, posY = 12;  //x and y start position
double dirX = -1, dirY = 0; //initial direction vector
double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

void draw_ray_casting(t_vars *vars)
{
    
    for(int x = 0; x < screenWidth; x++)
    {
        //calculate ray position and direction
        double cameraX = 2 * x / (double)screenWidth - 1; //x-coordinate in camera space
        double rayDirX = dirX + planeX * cameraX;
        double rayDirY = dirY + planeY * cameraX;

        //which box of the map we're in
        int mapX = (int)posX;
        int mapY = (int)posY;

        //length of ray from current position to next x or y-side
        double sideDistX;
        double sideDistY;

        //length of ray from one x or y-side to next x or y-side
        double deltaDistX = fabs(1 / rayDirX);
        double deltaDistY = fabs(1 / rayDirY);
        double perpWallDist;

        //what direction to step in x or y-direction (either +1 or -1)
        int stepX = (rayDirX < 0) ? -1 : 1;
        int stepY = (rayDirY < 0) ? -1 : 1;

        int hit = 0; //was there a wall hit?
        int side; //was a NS or a EW wall hit?

        //calculate step and initial sideDist
        if (rayDirX < 0)
        {
            sideDistX = (posX - mapX) * deltaDistX;
        }
        else
        {
            sideDistX = (mapX + 1.0 - posX) * deltaDistX;
        }

        if (rayDirY < 0)
        {
            sideDistY = (posY - mapY) * deltaDistY;
        }
        else
        {
            sideDistY = (mapY + 1.0 - posY) * deltaDistY;
        }

        //perform DDA
        while (!hit)
        {
            //jump to next map square, either in x-direction, or in y-direction
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }

            //Check if ray has hit a wall
            if (worldMap[mapX][mapY] > 0)
                hit = 1;
        }

        //Calculate distance projected on camera direction
        if (side == 0)
            perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
        else
            perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

        //Calculate height of line to draw on screen
        int lineHeight = (int)(screenHeight / perpWallDist);

        //calculate lowest and highest pixel to fill in current stripe
        int drawStart = -lineHeight / 2 + screenHeight / 2;
        if (drawStart < 0)
            drawStart = 0;
        int drawEnd = lineHeight / 2 + screenHeight / 2;
        if (drawEnd >= screenHeight)
            drawEnd = screenHeight - 1;

        //draw the pixels of the stripe as a vertical line
        int color = (side == 1) ? 0xFF0000 : 0xFFFFFF; // red if NS, white if EW
        for (int y = drawStart; y < drawEnd; y++)
            mlx_pixel_put(vars->mlx, vars->win, x, y, color);
    }
}

int key_pressed(int keycode, t_vars *vars)
{
    // Move forward
    if (keycode == 65362)
    {
        mlx_clear_window(vars->mlx, vars->win);
        if (worldMap[(int)(posX + dirX * moveSpeed)][(int)posY] == 0)
            posX += dirX * moveSpeed;
        if (worldMap[(int)posX][(int)(posY + dirY * moveSpeed)] == 0)
            posY += dirY * moveSpeed;
    }
    // Move backward
    else if (keycode == 65364)
    {
        mlx_clear_window(vars->mlx, vars->win);
        if (worldMap[(int)(posX - dirX * moveSpeed)][(int)posY] == 0)
            posX -= dirX * moveSpeed;
        if (worldMap[(int)posX][(int)(posY - dirY * moveSpeed)] == 0)
            posY -= dirY * moveSpeed;
    }
    // Rotate right
    else if (keycode == 65363)
    {
        mlx_clear_window(vars->mlx, vars->win);
        double oldDirX = dirX;
        dirX = dirX * cos(-rotateSpeed) - dirY * sin(-rotateSpeed);
        dirY = oldDirX * sin(-rotateSpeed) + dirY * cos(-rotateSpeed);
        double oldPlaneX = planeX;
        planeX = planeX * cos(-rotateSpeed) - planeY * sin(-rotateSpeed);
        planeY = oldPlaneX * sin(-rotateSpeed) + planeY * cos(-rotateSpeed);
    }
    // Rotate left
    else if (keycode == 65361)
    {
        mlx_clear_window(vars->mlx, vars->win);
        double oldDirX = dirX;
        dirX = dirX * cos(rotateSpeed) - dirY * sin(rotateSpeed);
        dirY = oldDirX * sin(rotateSpeed) + dirY * cos(rotateSpeed);
        double oldPlaneX = planeX;
        planeX = planeX * cos(rotateSpeed) - planeY * sin(rotateSpeed);
        planeY = oldPlaneX * sin(rotateSpeed) + planeY * cos(rotateSpeed);
    }
    return (0);
}

int main(void)
{
    t_vars vars;
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, screenWidth, screenHeight, "Raycaster");
    mlx_hook(vars.win, 2, 1L<<0, key_pressed, &vars);
    mlx_loop_hook(vars.mlx, draw_ray_casting, &vars);
    mlx_loop(vars.mlx);
    return (0);
}

