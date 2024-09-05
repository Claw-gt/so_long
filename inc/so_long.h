/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:50:27 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/05 14:46:07 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# define CHARACTER = "./textures/Grass_01.xpm"
# define FLOOR = "./textures/Grass_01.xpm"
# define WALL = ""
# define PLAYER = ""
# define EXIT = ""

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
	ESC = 65307,
	W = 119,
	A = 97,
	S = 115,
	D = 100,
};

typedef	struct s_vector
{
	int		x;
	int		y;
}			t_vector;

typedef struct s_map 
{
	
}				t_map;

typedef struct s_game 
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			height;
	int			width;
	// t_image		character;
	t_vector	character_pos;
	//void	*textures[5];
	//t_map	*map;
}				t_game;

typedef struct s_image 
{
	t_game	window;
	void	*img_ptr;
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

char	*get_next_line(int fd);
#endif