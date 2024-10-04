/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:43:13 by clagarci          #+#    #+#             */
/*   Updated: 2024/10/04 12:04:56 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
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
# define OBJECT_PATH "./textures/collectable.xpm"
# define ENEMY_PATH "./textures/enemy.xpm"
# define GHOST_PATH "./textures/ghost.xpm"

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
	ERROR_EMPTY_LINE = 4,
	ERROR_MAP_SIZE = 5,
	ERROR_MAP_WALLS = 6,
	ERROR_MAP_CHARACTERS = 7,
	ERROR_MAP_OBJECT = 8,
	ERROR_MAP_PLAYER = 9,
	ERROR_MAP_EXIT = 10,
	ERROR_MAP_PATH = 11,
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
	char		**enemy_map;
	int			object;
	int			exit;
	int			player;
	int			enemy_space;
	t_vector	player_pos;
	t_vector	exit_pos;
	t_vector	enemy_pos;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			height;
	int			width;
	void		*player;
	void		*exit;
	void		*object;
	void		*wall;
	void		*floor;
	void		*enemy;
	void		*ghost;
	t_map		map;
	int			counter;
}				t_game;

t_map	parse_map(char *path);

void	print_map(t_map map);

void	check_path(t_map map);

void	assign_textures(t_game *game);

void	render_map(t_game game);

t_map	create_copy(t_map map);

void	render_frame(t_game game, t_vector previous_pos);

void	player_on_exit(t_game game, int rows, int cols);

void	move_up(t_game *game, int *update_path);

void	move_down(t_game *game, int *update_path);

void	move_left(t_game *game, int *update_path);

void	move_right(t_game *game, int *update_path);

int		move_player(int keycode, t_game *game);

void	flood_fill(t_map *map, int x, int y, int enemy);

void	*free_map(char **map, int num);

void	init_map(t_map *map);

void	ft_error(int error_code);

int		exit_game(t_game *game);

void	custom_msg(t_game game, int player_on_exit);

void	print_count(t_game game);

void	print_msg(t_game game, int x, int y, char *str);

void	print_img(t_game game, void *img, int width, int height);

char	**duplicate_map(t_map map);

int		space_available(t_map map);

void	render_enemy(t_game *game);

void	path_enemy(t_map *map);

void	move_enemy(t_game *game, int *update_path, int space_available);

int		on_enemy(t_vector player_pos, t_vector enemy_pos);

void	enemy_attack(t_game *game);

void	enemy_on_exit(t_game game, int r, int c);
#endif