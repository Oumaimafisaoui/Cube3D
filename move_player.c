/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:27:59 by oufisaou          #+#    #+#             */
/*   Updated: 2022/12/20 16:11:51 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// // this file is empty because the map should be added to the structure adn whenever it s put somewhere it gives an error
// int	do_moves2(t_all *cub, int index1, int index2)
// {
// 	if (cub->parse[index1][index2] == 'E')
// 	{
// 		if (cub->collectable != 0)
// 			return (0);
// 		annouce_win(cub);
// 		exit_program(cub);
// 	}
// 	else if (cub->parse[index1][index2] == 'N')
// 	{
// 		annouce_win(cub);
// 		exit_program(cub);
// 	}
// 	else if (cub->parse[index1][index2] == '1')
// 		return (0);
// 	return (1);
// }

// int	do_moves(t_all *cub, int index1, int index2)
// {
// 	if (cub->parse[index1][index2] == '0')
// 	{
// 		cub->parse[index1][index2] = 'P';
// 		cub->player_y = index1;
// 		cub->player_x = index2;
// 	}
// 	// else if (map->parse[index1][index2] == 'C')
// 	// {
// 	// 	map->parse[index1][index2] = 'P';
// 	// 	map->player_y = index1;
// 	// 	map->player_x = index2;
// 	// 	map->collectable--;
// 	// 	annouce_win(map);
// 	// }
// 	return (1);
// }

// int	event_up_down(t_all *cub, int key)
// {
// 	int	index1;
// 	int	index2;

// 	index1 = cub->player->y;
// 	index2 = cub->player->x;
// 	if (key == 13)
// 	{
// 		index1 = index1 - 1;
// 		if (!do_moves(cub, index1, index2) || !do_moves2(cub, index1, index2))
// 			return (0);
// 		cub->parse[index1 + 1][index2] = '0';
// 	}
// 	if (key == 1)
// 	{
// 		index1 = index1 + 1;
// 		if (!do_moves(cub, index1, index2) || !do_moves2(cub, index1, index2))
// 			return (0);
// 		cub->parse[index1 - 1][index2] = '0';
// 	}
// 	return (1);
// }

// int	mouvements(int key, t_all *cub)
// {
// 	int	event;

// 	if (key == 13 || key == 1)
// 		event = event_up_down(cub, key);
// 	// else if (key == 2 || key == 0)
// 	// 	event = event_left_right(cub, key);
// 	// else if (key == 53)
// 	// 	exit_program(cub);
// 	//mlx_clear_window(cub->mlx, cub->mlx_win);
// 	//add_texture(cub);
// 	return (1);
// }

// void hook_player(t_all* cub)
// {
//     mlx_key_hook(cub->mlx_win, mouvements, &cub);
// }