/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:27:59 by oufisaou          #+#    #+#             */
/*   Updated: 2022/12/20 16:02:44 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// this file is empty because the map should be added to the structure adn whenever it s put somewhere it gives an error


int	mouvements(int key, t_all *cub)
{
	int	event;

	if (key == 13 || key == 1)
		event = event_up_down(cub, key);
	else if (key == 2 || key == 0)
		event = event_left_right(cub, key);
	else if (key == 53)
		exit_program(cub);
	//mlx_clear_window(cub->mlx, cub->mlx_win);
	//add_texture(map);
	return (1);
}

void hook_player(t_all* cub)
{
    mlx_key_hook(cub->mlx_win, mouvements, &cub);
}