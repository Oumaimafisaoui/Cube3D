/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:57:34 by oufisaou          #+#    #+#             */
/*   Updated: 2022/12/20 13:31:06 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char walls[7][10] = 
    {
        {'1','1','1','1','1','1','1','1','1','1'}, 
        {'1','0','0','0','0','0','0','0','0','1'}, 
        {'1','0','0','0','0','0','0','0','0','1'}, 
        {'1','0','0','0','0','0','0','0','0','1'}, 
        {'1','0','0','0','0','0','0','0','P','1'}, 
        {'1','0','0','0','0','0','0','0','0','1'}, 
        {'1','1','1','1','1','1','1','1','1','1'},   
    };

void init(t_all *cub)
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
    cub->map_h = 7 * 32;
    cub->map_w = 10 * 32;
}

void	my_mlx_pixel_put(t_all *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->addr + (y * cub->line_length + x * (cub->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void launch_mlx(t_all *cub)
{
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;

    cub->mlx = mlx_init();
    if (cub->mlx == NULL)
		error("mlx_init failed\n");
	cub->mlx_win = mlx_new_window(cub->mlx, 1920, 1080, "Cub3D");
    if (cub->mlx_win == NULL)
		error("mlx_new_window failed\n");
	cub->img = mlx_new_image(cub->mlx, cub->map_w, cub->map_h);
	cub->addr = mlx_get_data_addr(cub->img, &cub->bits_per_pixel, &cub->line_length,
								&cub->endian);

    while(i < 7)
    {
        j = 0;
        while(j < 10)
        {
            x = i * 32;
            if (walls[i][j] == '1')
            {
                while(x < (i * 32) + 32) 
                {
                     y = j * 32;
                     while (y < (j * 32) + 32)
                     {
                        if (x % 32 == 0 || y % 32 == 0)
                            my_mlx_pixel_put(cub, y, x, 0x00000000);
                        else
                            my_mlx_pixel_put(cub, y, x, 0x00FFFF00);
                        y++;
                     }
                     x++;
                }
            }
            else if(walls[i][j] == '0')
            {
                while(x < (i * 32) + 32) 
                {
                     y = j * 32;
                     while (y < (j * 32) + 32)
                     {
                        if (x % 32 == 0 || y % 32 == 0)
                            my_mlx_pixel_put(cub, y, x, 0x00000000);
                        else
                            my_mlx_pixel_put(cub, y, x,0x00FF00CC);
                        y++;
                     }
                     x++;
                }
            }
            else
            {
                 while(x < (i * 32) + 32) 
                {
                     y = j * 32;
                     while (y < (j * 32) + 32)
                     {
                        if (x % 32 == 0 || y % 32 == 0)
                            my_mlx_pixel_put(cub, y, x, 0x00000000);
                        else
                            my_mlx_pixel_put(cub, y, x,0x0033FF00);
                        y++;
                     }
                     x++;
                }
            }
            j++;
        }
        i++;
    }

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