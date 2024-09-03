/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:50:27 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/03 13:14:15 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	ESC = 65307;
	W = 119;
	A = 97;
	S = 115;
	D = 100;
};

typedef struct s_game 
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	//void	*textures[5];
	//t_map	*map;
}				t_game;

typedef struct s_image 
{
	t_game	win;
	void	*img;
	char	*addr;
	int		height;
	int		width;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_square {
	unsigned short int	x;
	unsigned short int	y;
	unsigned short int	size;
	int					color;
}		t_square;