/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:39:22 by oufisaou          #+#    #+#             */
/*   Updated: 2022/12/20 19:14:45 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void dda(t_all *cub, char walls[][10])
{
    (void)walls;
    double x1;
    double y1;
    double xx1 = cub->player->x;
    double yy1 = cub->player->y;

    x1 = cub->x + (cos(cub->player->ang) * VIEW);
    y1 = cub->y + (sin(cub->player->ang) * VIEW);
    int steps= 0;

    double xinc = 0;
    double yinc = 0;

    if(fabs(x1 - cub->player->x) > fabs(y1 -  cub->player->y))
        steps = fabs(x1 - cub->player->x);
    else
        steps = fabs(y1 - cub->player->y);

    xinc = (x1 - cub->player->x) / steps;
    yinc = (y1 - cub->player->y) / steps;

    for(double i = 0; i < steps; i++)
    {
        my_mlx_pixel_put(cub, yy1, xx1, 0x00FFFFFF);
        xx1 = xx1 + xinc;
        yy1 = yy1 + yinc;
    }
}