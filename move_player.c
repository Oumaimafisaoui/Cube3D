/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:27:59 by oufisaou          #+#    #+#             */
/*   Updated: 2022/12/21 20:00:06 by oufisaou         ###   ########.fr       */
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

void event_up_down(t_all *cub, int key)
{
	int	x;
	int	y;
    int move;

    printf("%f ::: %f\n", cub->player.x, cub->player.y);
	y = cub->player.y;
	x = cub->player.x;
	if (key == 13) //UP
	{
		cub->player.walk_direction = 1;
        move = cub->player.walk_direction * cub->player.speed;
        cub->player.x += cos(cub->player.ang) * move;
        cub->player.y += sin(cub->player.ang) * move;
	}
	if (key == 1)
	{
		cub->player.walk_direction = -1;
        move = cub->player.walk_direction * cub->player.speed;
        cub->player.x += cos(cub->player.ang) * move;
        cub->player.y += sin(cub->player.ang) * move;
	}
}

int	mouvements(int key, t_all *cub)
{
	if (key == 13 || key == 1)
		event_up_down(cub, key);
	// else if (key == 2 || key == 0)
	// 	event = event_left_right(cub, key);
	// else if (key == 53)
	// 	exit_program(cub);
	// mlx_clear_window(cub->mlx, cub->mlx_win);
    draw_minimap(cub);
    // put_player(cub);
    _7aytoti(cub);
    // set_direction(cub);
    dda(cub);
    mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img, 0, 0);
    return (1);
}
