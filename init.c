/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:57:34 by oufisaou          #+#    #+#             */
/*   Updated: 2022/12/20 15:59:08 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


void init(t_all *cub, t_player *mario)
{
    cub->mlx = NULL;
    cub->mlx_win = NULL;
    cub->img = NULL;
    cub->addr = NULL;
    cub->bits_per_pixel = 0;
    cub->line_length = 0;
    cub->endian = 0;
    cub->x = 0;
    cub->y = 0;
    cub->map_h = 7 * TTL;
    cub->map_w = 10 * TTL;
    mario->x = 0;
    mario->y = 0;
    cub->player = NULL;
}


void launch_mlx(t_all *cub, t_player *mario)
{
    // (void)mario;
    cub->mlx = mlx_init();
    if (cub->mlx == NULL)
		error("mlx_init failed\n");
	cub->mlx_win = mlx_new_window(cub->mlx, 1920, 1080, "Cub3D");
    if (cub->mlx_win == NULL)
		error("mlx_new_window failed\n");
	cub->img = mlx_new_image(cub->mlx, cub->map_w, cub->map_h);
	cub->addr = mlx_get_data_addr(cub->img, &cub->bits_per_pixel, &cub->line_length,
								&cub->endian);
    draw_minimap(cub);
    move_player(cub, mario);
    hook_player(cub);
    mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img, 0, 0);
	mlx_loop(cub->mlx);
}


void	error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

// int	exit_program(t_all *cub)
// {
// 	int	index;

// 	index = 0;
// 	if (cub->mlx_win)
// 		mlx_destroy_window(cub->mlx, cub->mlx_win);
// 	while (index < cub->map_h)
// 	{
// 		free(cub->parse[index]);
// 		index++;
// 	}
// 	free(map->parse);
// 	exit(0);
// }