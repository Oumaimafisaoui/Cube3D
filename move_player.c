/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:27:59 by oufisaou          #+#    #+#             */
/*   Updated: 2022/12/21 21:08:42 by oufisaou         ###   ########.fr       */
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

void event_left_right(t_all *cub, int key)
{
	int	x;
	int	y;
    int move;

    // printf("%f ::: %f\n", cub->player.x, cub->player.y);
	y = cub->player.y;
	x = cub->player.x;
	if (key == RIGHT) 
	{
		cub->player.walk_direction = 1;
        move = cub->player.walk_direction * cub->player.speed;
        cub->player.x += cos(cub->player.ang) * move;
        cub->player.y += sin(cub->player.ang) * move;
	}
	if (key == LEFT) 
	{
		cub->player.walk_direction = -1;
        move = cub->player.walk_direction * cub->player.speed;
        cub->player.x += sin(cub->player.ang) * move;
        cub->player.y += cos(cub->player.ang) * move;
	}
}

void event_up_down(t_all *cub, int key)
{
	int	x;
	int	y;
    int move;

    // printf("%f ::: %f\n", cub->player.x, cub->player.y);
	y = cub->player.y;
	x = cub->player.x;

	if (key == UP) 
	{
		cub->player.walk_direction = 1;
        move = cub->player.walk_direction * cub->player.speed;
        cub->player.x += sin(cub->player.ang) * move;
        cub->player.y += cos(cub->player.ang) * move;
	}
	if (key == DOWN) 
	{
		cub->player.walk_direction = -1;
        move = cub->player.walk_direction * cub->player.speed;
        cub->player.x += sin(cub->player.ang) * move;
        cub->player.y += cos(cub->player.ang) * move;
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
    printf("%d\n", key);
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
