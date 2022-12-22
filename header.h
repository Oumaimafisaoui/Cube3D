/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:18:49 by oufisaou          #+#    #+#             */
/*   Updated: 2022/12/22 15:21:38 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <math.h>
#include <stdio.h>
#define CUBE  60
#define VIEW  300

#define UP  126
#define DOWN 125
#define RIGHT 124
#define LEFT 123
// char walls[7][10] = {
//     {'1','1','1','1','1','1','1','1','1','1'}, 
//     {'1','0','0','0','0','0','0','0','0','1'}, 
//     {'1','0','0','0','0','N','0','0','0','1'}, 
//     {'1','0','0','0','0','0','0','0','0','1'}, 
//     {'1','0','0','0','0','0','0','0','0','1'}, 
//     {'1','0','0','0','0','0','0','0','0','1'}, 
//     {'1','1','1','1','1','1','1','1','1','1'},   
// };

typedef struct s_player
{
    double x;
    double y;
    double ang;
    double speed;
    double turn_direction;
    double walk_direction;
    double rotation_speed;
    
}t_player;

typedef struct s_cub
{
    void *mlx;
    void *mlx_win;
    void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    int map_w;
    int map_h;
    t_player player;
    char walls[7][10];
} t_all;

//all walls should be removed and added to a struct

/* Cub3d */


void init(t_all *cub);
void	error(char *str);
void launch_mlx(t_all *cub);
void draw_minimap(t_all *cub);
void	my_mlx_pixel_put(t_all *cub, int x, int y, int color);
void put_player(t_all *cub);
int	mouvements(int key, t_all *cub);
void dda(t_all *cub);
void set_direction(t_all *cub);
int	exit_program(t_all *cub);
void event_left_right(t_all *cub, int key);
int check_walls2(t_all *cub, int flag);
int check_walls1(t_all *cub, int flag);

void	my_mlx_pixel_put2(t_all *cub, int x, int y, int color);


/*Cub3d outils*/
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

void _7aytoti(t_all *cub);
#endif