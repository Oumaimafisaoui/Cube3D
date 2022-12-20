/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:58:11 by oufisaou          #+#    #+#             */
/*   Updated: 2022/12/20 12:00:28 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void draw_minimap(t_all *cub)
{
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img, 0, 0);
}