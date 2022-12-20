/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:58:11 by oufisaou          #+#    #+#             */
/*   Updated: 2022/12/20 16:02:10 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

char walls[7][10] = 
    {
        {'1','1','1','1','1','1','1','1','1','1'}, 
        {'1','0','0','0','0','0','0','0','0','1'}, 
        {'1','0','0','0','0','N','0','0','0','1'}, 
        {'1','0','0','0','0','0','0','0','0','1'}, 
        {'1','0','0','0','0','0','0','0','0','1'}, 
        {'1','0','0','0','0','0','0','0','0','1'}, 
        {'1','1','1','1','1','1','1','1','1','1'},   
    };


void	my_mlx_pixel_put(t_all *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->addr + (y * cub->line_length + x * (cub->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_minimap(t_all *cub)
{
	int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
	
	while(i < cub->map_h / TTL)
    {
        j = 0;
        while(j < cub->map_w / TTL)
        {
           
            x = i * TTL;
            if (walls[i][j] == '1')
            {
                //    fill_wall(cub, i, j, walls);
                while(x < (i * TTL) + TTL) 
                {
                     y = j * TTL;
                     while (y < (j * TTL) + TTL)
                     {
                        if (x % TTL == 0 || y % TTL == 0)
                            my_mlx_pixel_put(cub, y, x, 0x00000000);
                        else
                            my_mlx_pixel_put(cub, y, x, 0x00FFFF00);
                        y++;
                     }
                     x++;
                }
            }
            else if(walls[i][j] == '0')
            {
                while(x < (i * TTL) + TTL) 
                {
                     y = j * TTL;
                     while (y < (j * TTL) + TTL)
                     {
                        if (x % TTL == 0 || y % TTL == 0)
                            my_mlx_pixel_put(cub, y, x, 0x00000000);
                        else
                            my_mlx_pixel_put(cub, y, x,0x009966FF);
                        y++;
                     }
                     x++;
                }
            }
            else
            {
                while(x < (i * TTL) + TTL) 
                {
                     y = j * TTL;
                     while (y < (j * TTL) + TTL)
                     {
                        if (x % TTL == 0 || y % TTL == 0)
                            my_mlx_pixel_put(cub, y, x, 0x00000000);
                        else
                            my_mlx_pixel_put(cub, y, x,0x00FF3333);
                        y++;
                     }
                     x++;
                }
            }
            j++;
        }
        i++;
    }
}

void move_player(t_all *cub, t_player *mario)
{
    int i = 0;
    int j = 0;
    int h;
    int angle;
    int xp;
    int yp;

   while(i < cub->map_h / TTL)
    {
        j = 0;
        while(j < cub->map_w / TTL)
        {
            if (walls[i][j] == 'N' || walls[i][j] == 'S' || walls[i][j] == 'W' || walls[i][j] == 'E') //it can be other directions
            {
                    mario->x = (i * TTL) + TTL / 2;
                    mario->y = (j * TTL) + TTL / 2;
                    printf("%d|%d\n", mario->x, mario->y);
                    my_mlx_pixel_put(cub, mario->y, mario->x, 0x00FFFFFF);

                    //x = cos(o) * h + xs
                    //y = sin(o) * h + ys
                    h = 1;
                    while(h < 6)
                    {
                        angle = 0;
                        while(angle < 360)
                        {
                            xp = cos(angle) * h + mario->x;
                            yp = sin(angle) * h + mario->y;
                              my_mlx_pixel_put(cub, yp, xp, 0x00FFFFFF);
                            angle++;
                        }
                        h++;
                    }
            }
 
            j++;
        }
        i++;
    }
    cub->player = mario; //because I need it in mouvemnets

}



