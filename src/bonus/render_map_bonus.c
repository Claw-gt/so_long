/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:54:04 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/21 13:54:15 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	assign_textures(t_game *game)
{
	int	h;
	int	w;

	h = game->height;
	w = game->width;
	game->floor = mlx_xpm_file_to_image(game->mlx, FLOOR_PATH, &w, &h);
	game->wall = mlx_xpm_file_to_image(game->mlx, WALL_PATH, &w, &h);
	game->player = mlx_xpm_file_to_image(game->mlx, PLAYER_DOWN_PATH, &w, &h);
	game->exit = mlx_xpm_file_to_image(game->mlx, EXIT_PATH, &w, &h);
	game->object = mlx_xpm_file_to_image(game->mlx, OBJECT_PATH, &w, &h);
	game->enemy = mlx_xpm_file_to_image(game->mlx, ENEMY_PATH, &w, &h);
	if (!game->floor || !game->wall || !game->player || \
	!game->exit || !game->object || !game->enemy)
		ft_error(ERROR_FILE);
}

void	render_frame(t_game game, t_vector previous_pos)
{
	int	width;
	int	height;

	width = previous_pos.x * TILE_SIZE;
	height = previous_pos.y * TILE_SIZE;
	if (game.map.map[previous_pos.y][previous_pos.x] == '0')
		print_img(game, game.floor, width, height);
	else if (game.map.map[previous_pos.y][previous_pos.x] == 'E')
		print_img(game, game.exit, width, height);
	width = game.map.player_pos.x * TILE_SIZE;
	height = game.map.player_pos.y * TILE_SIZE;
	if (game.map.map[game.map.player_pos.y][game.map.player_pos.x] == 'E')
		player_on_exit(game, game.map.player_pos.y, game.map.player_pos.x);
	else
		print_img(game, game.player, width, height);
}

void	render_enemy(t_game *game)
{
	int	rand_col;
	int	rand_row;
	int	up_bound_col;
	int	up_bound_row;
	int	low_bound;

	up_bound_col = game->map.size.x - 2;
	up_bound_row = game->map.size.y - 2;
	low_bound = 1;
	rand_col = 0;
	rand_row = 0;
	ft_printf("Low bound %d Up bound row %d Up bound col %d\n", low_bound, up_bound_row, up_bound_col);
	while (game->map.map[rand_row][rand_col] != '0')
	{
		rand_col = rand() % (up_bound_col - low_bound + 1) + low_bound;
		rand_row = rand() % (up_bound_row - low_bound + 1) + low_bound;
		ft_printf("Rand col: %d Rand row: %d", rand_col, rand_row);
	}
	print_img(*game, game->enemy, rand_col * TILE_SIZE, rand_row * TILE_SIZE);
	game->map.enemy_pos.x = rand_col;
	game->map.enemy_pos.y = rand_row;
	ft_printf("\nEnemy pos: %d %d\n", game->map.enemy_pos.y, game->map.enemy_pos.x);
	move_enemy(game);
	//ft_printf("Range %d Rand col %d\n", up_bound_col - low_bound + 1, rand_col);
}

void	render_floor(t_game game)
{
	int	rows;
	int	cols;

	rows = 0;
	cols = 0;
	while (game.map.map[rows])
	{
		cols = 0;
		while (game.map.map[rows][cols])
		{
			print_img(game, game.floor, cols * TILE_SIZE, rows * TILE_SIZE);
			cols++;
		}
		rows++;
	}
}

void	render_map(t_game game)
{
	int	row;
	int	col;

	row = -1;
	render_floor(game);
	while (++row < game.map.size.y)
	{
		col = -1;
		while (++col < game.map.size.x)
		{
			if (game.map.map[row][col] == '1')
				print_img(game, game.wall, col * TILE_SIZE, row * TILE_SIZE);
			else if (game.map.map[row][col] == 'E')
				print_img(game, game.exit, col * TILE_SIZE, row * TILE_SIZE);
			else if (game.map.map[row][col] == 'P')
				print_img(game, game.player, col * TILE_SIZE, row * TILE_SIZE);
			else if (game.map.map[row][col] == 'C')
				print_img(game, game.object, col * TILE_SIZE, row * TILE_SIZE);
		}
	}
	render_enemy(&game);
}
