/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:18:37 by oufisaou          #+#    #+#             */
/*   Updated: 2022/12/20 12:43:54 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main()
{
    t_all cub;
    init(&cub);
    launch_mlx(&cub);
	draw_minimap(&cub);
	// mlx_loop(cub.mlx);
}