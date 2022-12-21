/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:58:11 by oufisaou          #+#    #+#             */
/*   Updated: 2022/12/21 18:03:26 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

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
	while(i < cub->map_h / CUBE) // i will itterate on 7 height
    {
        j = 0;
        while(j < cub->map_w / CUBE) // j will itterate on 10 width
        {
           
            x = i * CUBE; // x will be the height of the square
            if (cub->walls[i][j] == '1')
            {
                while(x < (i * CUBE) + CUBE) //while the height is less than the end of the square
                {
                     y = j * CUBE;
                     while (y < (j * CUBE) + CUBE)
                     {
                        if (x % CUBE == 0 || y % CUBE == 0) //put black line
                            my_mlx_pixel_put(cub, y, x, 0x00000000);
                        else
                            my_mlx_pixel_put(cub, y, x, 0x00FFFF00);
                        y++;
                     }
                     x++;
                }
            }
            else if(cub->walls[i][j] == '0')
            {
                while(x < (i * CUBE) + CUBE) 
                {
                     y = j * CUBE;
                     while (y < (j * CUBE) + CUBE)
                     {
                        if (x % CUBE == 0 || y % CUBE == 0)
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
                while(x < (i * CUBE) + CUBE) 
                {
                     y = j * CUBE;
                     while (y < (j * CUBE) + CUBE)
                     {
                        if (x % CUBE == 0 || y % CUBE == 0)
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

void put_player(t_all *cub, t_player *mario)
{
    int i = 0;
    int j = 0;

    double h;
    double angle;
    double xp;
    double yp;

   while(i < cub->map_h / CUBE)
    {
        j = 0;
        while(j < cub->map_w / CUBE)
        {
            if (cub->walls[i][j] == 'N' || cub->walls[i][j] == 'S' || cub->walls[i][j] == 'W' || cub->walls[i][j] == 'E') //it can be other directions
            {
                    mario->x = (i * CUBE) + CUBE / 2;
                    mario->y = (j * CUBE) + CUBE / 2;
                    printf("%f|%f\n", mario->x, mario->y);
                    my_mlx_pixel_put(cub, mario->y, mario->x, 0x00FFFFFF);
                    //x = cos(o) * h + xs
                    //y = sin(o) * h + ys
                    h = 1;
                    while(h < 5) // this h increments
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



