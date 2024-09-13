/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:50:27 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/13 18:11:35 by clagarci         ###   ########.fr       */
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
# define FLOOR_PATH "./possible_sprites/floor.xpm"
# define WALL_PATH "./possible_sprites/wall.xpm"
# define PLAYER_PATH "./possible_sprites/Player_img/player_down_transparent.xpm"
# define EXIT_PATH "./possible_sprites/exit.xpm"
# define COLLECTABLE_PATH "./possible_sprites/collectable.xpm"

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

enum {
	ERROR_ARGS = 1,
	ERROR_FILE = 2,
	ERROR_MAP_SIZE = 3,
	ERROR_MAP_WALLS = 4,
	ERROR_MAP_CHARACTERS = 5,
	ERROR_MAP_COLLECTABLE = 6,
	ERROR_MAP_PLAYER = 7,
	ERROR_MAP_EXIT = 8,
	ERROR_MAP_PATH = 9,
};

typedef	struct s_vector
{
	int		x;
	int		y;
}			t_vector;

typedef struct s_map 
{
	t_vector	size;
	char		**map;
	int			collectable;
	int			exit;
	int			player;
	t_vector	player_pos;
	t_vector	exit_pos;
}				t_map;

typedef struct s_game 
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			height;
	int			width;
	void		*textures[5];
	//void		*player_img;
	//void		*exit_img;
	//void		*collectable_img;
	//void		*wall_img;
	//void		*floor_img;
	t_map		map;
	int			counter;
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

//char	*get_next_line(int fd);

t_map	parse_map(char *path);

void	print_map(t_map map);

void	check_path(t_map map);

void	assign_textures(t_game *game);

void    render_map(t_game game);

void	player_on_exit(t_game game, int rows, int cols);

void	move_up(t_game *game);

void	move_down(t_game *game);

void	move_left(t_game *game);

void	move_right(t_game *game);

int    	move_player(int keycode, t_game *game);

void	*free_map(char **map, int num);

void    ft_error(int error_code);

int		exit_game(t_game *game);
#endif