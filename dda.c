/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:39:22 by oufisaou          #+#    #+#             */
/*   Updated: 2022/12/21 19:24:39 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void dda(t_all *cub)
{
    double x1;
    double y1;
    double xx1;
    double yy1;
    double xinc;
    double yinc;
    int steps;


    //why pi / 2 looks down : becaue they go in the way of the horloge in game development
    
    x1 = cub->player.x + (sin(cub->player.ang) * VIEW);
    y1 = cub->player.y + (cos(cub->player.ang) * VIEW);

    printf("%f,%f\n", x1, y1);
    xinc = 0;
    yinc = 0;
    steps = 0;
    xx1 = cub->player.x;
    yy1 = cub->player.y;

    if(fabs(x1 - cub->player.x) > fabs(y1 -  cub->player.y))
        steps = fabs(x1 - cub->player.x);
    else
        steps = fabs(y1 - cub->player.y);

    xinc = (x1 - cub->player.x) / steps;
    yinc = (y1 - cub->player.y) / steps;

    for(double i = 0; i < steps; i++)
    {
        my_mlx_pixel_put(cub, yy1, xx1, 0x00FFFFFF);
        xx1 = xx1 + xinc;
        yy1 = yy1 + yinc;
    }
    
}