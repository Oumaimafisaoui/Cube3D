/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:18:49 by oufisaou          #+#    #+#             */
/*   Updated: 2022/12/20 16:47:06 by oufisaou         ###   ########.fr       */
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

#define TTL  60

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
    int x;
    int y;
    
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
    int x;
    int y;
    int map_w;
    int map_h;
    t_player *player;
    char walls[7][10];
} t_all;

//all walls should be removed and added to a struct

/* Cub3d */
void init(t_all *cub, t_player *mario);
void	error(char *str);
void launch_mlx(t_all *cub, t_player *mario, char walls[][10]);
void draw_minimap(t_all *cub, char walls[][10]);
void	my_mlx_pixel_put(t_all *cub, int x, int y, int color);
void move_player(t_all *cub, t_player *mario, char walls[][10]);
void hook_player(t_all* cub);
int	mouvements(int key, t_all *cub);

/*Cub3d outils*/

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
#endif