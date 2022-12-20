/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:27:59 by oufisaou          #+#    #+#             */
/*   Updated: 2022/12/20 21:09:02 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// int	event_up_down(t_all *cub, int key)
// {
// 	int	index1;
// 	int	index2;

// 	index1 = cub->player->y;
// 	index2 = cub->player->x;
// 	if (key == 13)
// 	{
// 		index1 = index1 - 1;
// 		cub->parse[index1 + 1][index2] = '0';
// 	}
// 	if (key == 1)
// 	{
// 		index1 = index1 + 1;
// 		cub->parse[index1 - 1][index2] = '0';
// 	}
// 	return (1);
// }

int	mouvements(int key, t_all *cub)
{
	int	event;

	if (key == 13 || key == 1)
		event = event_up_down(cub, key);
	// else if (key == 2 || key == 0)
	// 	event = event_left_right(cub, key);
	// else if (key == 53)
	// 	exit_program(cub);
	//mlx_clear_window(cub->mlx, cub->mlx_win);
	//add_texture(cub);
	return (1);
}

void hook_player(t_all* cub)
{
    mlx_key_hook(cub->mlx_win, mouvements, &cub);
}