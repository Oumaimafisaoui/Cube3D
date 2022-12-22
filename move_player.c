/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:27:59 by oufisaou          #+#    #+#             */
/*   Updated: 2022/12/22 13:46:52 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
int	exit_program(t_all *cub)
{
    //free the map
	// int	index;

	// index = 0;
	if (cub->mlx_win)
		mlx_destroy_window(cub->mlx, cub->mlx_win);
	// while (index < cub->)
	// {
	// 	free(cub->wall[index]);
	// 	index++;
	// }
	// free(cub->walls);
	exit(0);
}

int check_walls1(t_all *cub, int flag)
{
    int	x;
	int	y;
    double angle;

    angle = 0;
    if(flag == 1)
    {
       angle = cub->player.ang - (90 * (M_PI / 180));
       x = (cub->player.x - (cos(angle) * cub->player.speed)) / CUBE;
       y = (cub->player.y - (sin(angle) * cub->player.speed)) / CUBE;

       if(cub->walls[y][x] == '1')
            return (1);
       else
            return (0);
    }
    else if(flag == 0)
    {
        angle = cub->player.ang + (90 * (M_PI / 180));
        x = (cub->player.x - (cos(angle) * cub->player.speed)) / CUBE;
        y =  (cub->player.y - (sin(angle) * cub->player.speed)) / CUBE;
        
        if(cub->walls[y][x] == '1')
                return (1);
        else
                return (0);
    }
    return (1);
}

void event_left_right(t_all *cub, int key)
{
    double angle;

	if (key == RIGHT) 
	{
        if(!check_walls1(cub, 1))
        {
            angle = cub->player.ang - (90 * (M_PI / 180));
            cub->player.x -= (cos(angle) * cub->player.speed);
            cub->player.y -= (sin(angle) * cub->player.speed);
        }
	}
	if (key == LEFT) 
	{
        if(!check_walls1(cub, 0))
        {
            angle = cub->player.ang + (90 * (M_PI / 180));
            cub->player.x -= (cos(angle) * cub->player.speed);
            cub->player.y -= (sin(angle) * cub->player.speed);
        }
    }
}

int check_walls2(t_all *cub, int flag)
{
    int	x;
	int	y;

    if(flag == 1)
    {
       x = (cub->player.x + cos(cub->player.ang) * cub->player.speed) / CUBE;
       y = (cub->player.y + sin(cub->player.ang) *  cub->player.speed) / CUBE;

       if(cub->walls[y][x] == '1')
            return (1);
       else
            return (0);
    }
    else if(flag == 0)
    {
        x = (cub->player.x + cos(cub->player.ang) * (cub->player.speed * -1)) / CUBE;
        y =  (cub->player.y + sin(cub->player.ang) * (cub->player.speed * -1)) / CUBE;
        
        if(cub->walls[y][x] == '1')
                return (1);
        else
                return (0);
    }
    return (1);
}


void event_up_down(t_all *cub, int key)
{
	if (key == UP)
    {
        if(!check_walls2(cub, 1))
        {
            cub->player.x += cos(cub->player.ang) * cub->player.speed;
            cub->player.y += sin(cub->player.ang) *  cub->player.speed;
        }
    }
	if(key == DOWN)
    {
        if(!check_walls1(cub, 0))
        {
            cub->player.x += cos(cub->player.ang) * (cub->player.speed * -1);
            cub->player.y += sin(cub->player.ang) * (cub->player.speed * -1);
        }
    }
}



void rotate_player(int key, t_all *cub)
{
    if(key == 35)
    {
        cub->player.ang -= cub->player.rotation_speed;
    }
    else if (key == 31)
    {
        cub->player.ang += cub->player.rotation_speed;
    }

}
int	mouvements(int key, t_all *cub)
{
    //x is y and y is x
    printf("x: %f | y : %f\n", cub->player.x , cub->player.y);
	if (key == RIGHT || key == LEFT)
		event_left_right(cub, key);
	else if (key == UP || key == DOWN)
		event_up_down(cub, key);
    else
        rotate_player(key, cub);
	// else if (key == 53)
	// 	exit_program(cub);
	// mlx_clear_window(cub->mlx, cub->mlx_win);
    draw_minimap(cub);
    _7aytoti(cub);
    dda(cub);
    mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img, 0, 0);
    return (1);
}
