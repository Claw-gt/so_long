/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:50:27 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/18 16:21:30 by clagarci         ###   ########.fr       */
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
# define EXIT_MSG "STAY DETERMINED!"
# define TILE_SIZE 50
# define WHITE 0xffffff
# define ON_DESTROY 17
# define FLOOR_PATH "./textures/floor.xpm"
# define WALL_PATH "./textures/wall.xpm"
# define PLAYER_DOWN_PATH "./textures/player_down.xpm"
# define PLAYER_UP_PATH "./textures/player_up.xpm"
# define PLAYER_LEFT_PATH "./textures/player_left.xpm"
# define PLAYER_RIGHT_PATH "./textures/player_right.xpm"
# define EXIT_PATH "./textures/exit.xpm"
# define COLLECTABLE_PATH "./textures/collectable.xpm"

enum
{
	ESC = 65307,
	W = 119,
	A = 97,
	S = 115,
	D = 100,
};

enum
{
	ERROR_ARGS = 1,
	ERROR_EXTENSION = 2,
	ERROR_FILE = 3,
	ERROR_MAP_SIZE = 4,
	ERROR_MAP_WALLS = 5,
	ERROR_MAP_CHARACTERS = 6,
	ERROR_MAP_COLLECTABLE = 7,
	ERROR_MAP_PLAYER = 8,
	ERROR_MAP_EXIT = 9,
	ERROR_MAP_PATH = 10,
};

typedef struct s_vector
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
	void		*mlx;
	void		*win;
	int			height;
	int			width;
	void		*player;
	void		*exit;
	void		*collectable;
	void		*wall;
	void		*floor;
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

typedef struct s_square
{
	unsigned short int	x;
	unsigned short int	y;
	unsigned short int	size;
	int					color;
}		t_square;

t_map	parse_map(char *path);

void	print_map(t_map map);

void	check_path(t_map map);

void	assign_textures(t_game *game);

void	render_map(t_game game);

void	render_frame(t_game game, t_vector previous_pos);

void	player_on_exit(t_game game, int rows, int cols);

void	move_up(t_game *game);

void	move_down(t_game *game);

void	move_left(t_game *game);

void	move_right(t_game *game);

int		move_player(int keycode, t_game *game);

void	*free_map(char **map, int num);

void	ft_error(int error_code);

int		exit_game(t_game *game);

void    print_msg(t_game game, int x, int y, int color, char *str);

void	print_img(t_game game, void *img, int width, int height);
#endif