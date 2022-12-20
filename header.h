/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:18:49 by oufisaou          #+#    #+#             */
/*   Updated: 2022/12/20 13:27:46 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>

#define PIX_SIZE = 10;
#define  MAP_HEIGHT = 30;
#define MAP_WIDTH = 20;



typedef struct s_cub
{
    void *mlx;
    void *mlx_win;
    void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    int x;
    int y;
    int map_w;
    int map_h;
} t_all;

typedef struct s_player
{
    int x;
    int y; 
}t_player;
/* Cub3d */
void init(t_all *cub);
void	error(char *str);
void launch_mlx(t_all *cub);
void draw_minimap(t_all *cub);
/*Cub3d outils*/

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
#endif