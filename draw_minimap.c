/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:58:11 by oufisaou          #+#    #+#             */
/*   Updated: 2022/12/20 14:25:17 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
                            my_mlx_pixel_put(cub, y, x,0x00FF00CC);
                        y++;
                     }
                     x++;
                }
            }
            // else if(walls[i][j] == ' ')
            // {
            //     while(x < (i * TTL) + TTL) 
            //     {
            //          y = j * TTL;
            //          while (y < (j * TTL) + TTL)
            //          {
            //             if (x % TTL == 0 || y % TTL == 0)
            //                 my_mlx_pixel_put(cub, y, x, 0x00000000);
            //             else
            //                 my_mlx_pixel_put(cub, y, x,0x0033FF00);
            //             y++;
            //          }
            //          x++;
            //     }
            // }
            // else
            // {
            //        while(x < ((i * TTL) + TTL)) 
            //         {
            //             y = j * TTL;
            //             while (y < ((j * TTL) + TTL))
            //             {
            //                 if (x % TTL == 0 || y % TTL == 0)
            //                     my_mlx_pixel_put(cub, y, x, 0x00000000);
            //                 else
            //                     my_mlx_pixel_put(cub, y, x, 0x000000FF);
            //                 y++;
            //             }
            //             x++;
            //         }
            // }
            j++;
        }
        i++;
    }
}