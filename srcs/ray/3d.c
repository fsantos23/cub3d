/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantos2 <fsantos2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:14:44 by fsantos2          #+#    #+#             */
/*   Updated: 2024/03/21 16:49:41 by fsantos2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

double dist(double ax, double ay, double bx, double by, double ang)
{
    return(sqrt((bx-ax) *(bx - ax) + (by - ay) * (by - ay)));
}

void draw_rectangle(int x1, int y1, int x2, int y2, int color)
{
    for (int x = x1; x <= x2; x++) {
        for (int y = y1; y <= y2; y++)
            put_pixel(x, y, color);
    }
}

void draw_wall(float line_h, float line0, int r, int color)
{
    draw_rectangle((r * 10 + SCREEN_WIDTH) + 64 * cub()->map_info->width, line0, ((r * 10 + SCREEN_WIDTH) + 64 * cub()->map_info->width) + 10, line_h + line0, color);
}

void draw_rays(double px, double py)
{
    int r;
    int mx;
    int my;
    int mp;
    int dof;

    double rx;
    double ry;
    double ra;
    double xo;
    double yo;
    double dist_t;
    int color;

    ra = ray()->player.pa - DR * 30;
    if(ra < 0)
        ra += 2 * PI;
    if(ra > 2 * PI)
        ra -= 2* PI;
    r = 0;
    while(r < 60)
    {
        //----- Horizontal Line -----//
        dof = 0;
        double dis_h = 1000000, hx = px , hy = py;
        double a_tan = -1 / tan(ra);
        if(ra > PI)
        {
            ry = (((int)py >> 6) << 6) - 0.0001;
            rx = (py - ry) * a_tan + px;
            yo = -64;
            xo = -yo * a_tan;
        }
        if(ra < PI)
        {
            ry = (((int)py >> 6) << 6) + 64;
            rx = (py - ry) * a_tan + px;
            yo = 64;
            xo = -yo * a_tan;
        }
        if(ra == 0 || ra == PI)
        {
            rx = px;
            ry = py;
            dof = 8;
        }
        while(dof < 8)
        {
            mx = (int)(rx) >> 6;
            my = (int)(ry) >> 6;
            mp = my * cub()->map_info->width + mx; // alterar 8 para ray()->map_x
            if(mx < cub()->map_info->width && my < cub()->map_info->height && mp > 0 && mp < (cub()->map_info->width * cub()->map_info->height) && cub()->map_info->map[my][mx] == '1')
            {
                hx = rx;
                hy = ry;
                dis_h = dist(px, py, hx, hy, ra);
                dof = 8;
            }
            else
            {
                rx += xo;
                ry += yo;
                dof += 1;
            }
        }
        //----- Vertical Line -----//
        dof = 0;
        double dis_v = 10000000, vx = px , vy = py;
        double n_tan = -tan(ra);
        if(ra > P2 && ra < P3)
        {
            rx = (((int)px >> 6) << 6) - 0.0001;
            ry = (px - rx) * n_tan + py;
            xo = -64;
            yo = -xo * n_tan;
        }
        if(ra < P2 || ra > P3)
        {
            rx = (((int)px>>6)<<6) + 64;
            ry = (px - rx) * n_tan + py;
            xo = 64;
            yo = -xo * n_tan;
        }
        if(ra == 0 || ra == PI)
        {
            rx = px;
            ry = py;
            dof = 8;
        }
        while(dof < 8)
        {
            mx = (int)(rx) >> 6;
            my = (int)(ry) >> 6;
            mp = my * cub()->map_info->height + mx; // alterar 7 para ray()->map_x
             if(mx < cub()->map_info->width && my < cub()->map_info->height && mp > 0 && mp < (cub()->map_info->width * cub()->map_info->height) && cub()->map_info->map[my][mx] == '1')
            {
                vx = rx;
                vy = ry;
                dis_v = dist(px, py, vx, vy, ra);
                dof = 8;
            }
            else
            {
                rx += xo;
                ry += yo;
                dof += 1;
            }
        }
        if(dis_v < dis_h)
        {
            rx = vx;
            ry = vy;
            dist_t = dis_v;
            color = rgb_to_hex(0, 200, 0);
        }
        if(dis_v > dis_h)
        {
            rx = hx;
            ry = hy;
            dist_t = dis_h;
            color = rgb_to_hex(0, 240, 0);
        }
        draw_line(px, py, rx, ry, rgb_to_hex(0, 250, 0));
        //---------draw line-------//
        float ca = ray()->player.pa - ra;
        if(ca < 0)
            ca += 2 * PI;
        if(ca > 2 * PI)
            ca -= 2* PI;
        dist_t = dist_t * cos(ca);
        float line_h = (SCREEN_HEIGHT * BLOCK_SIZE) / dist_t;
        if(line_h > SCREEN_HEIGHT)
            line_h = SCREEN_HEIGHT;
        float line0 = (SCREEN_HEIGHT / 2) - line_h / 2;
        draw_wall(line_h, line0, r, color);
        r++;
        ra += DR;
        if(ra < 0)
            ra += 2 * PI;
        if(ra > 2 * PI)
            ra -= 2* PI;
    }
}
