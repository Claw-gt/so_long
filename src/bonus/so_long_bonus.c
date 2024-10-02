/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:50:42 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/22 14:11:08 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

int	on_wall(t_game game, char *direction)
{
	int		x;
	int		y;
	char	**map_aux;

	x = game.map.player_pos.x;
	y = game.map.player_pos.y;
	map_aux = game.map.map;
	if (ft_strncmp(direction, "up", 2) == 0)
		y -= 1;
	else if (ft_strncmp(direction, "left", 4) == 0)
		x -= 1;
	else if (ft_strncmp(direction, "down", 2) == 0)
		y += 1;
	else if (ft_strncmp(direction, "right", 2) == 0)
		x += 1;
	if (map_aux[y][x] != '1')
		return (0);
	return (1);
}

int	key_hook(int keycode, t_game *game)
{
	t_vector	previous_pos;
	t_vector	size;
	int			update_path;

	update_path = 0;
	size = game->map.size;
	previous_pos = game->map.player_pos;
	if (keycode == ESC || game->dead == 1)
		exit_game(game);
	if (previous_pos.x < size.x && previous_pos.y < size.y)
	{
		if (keycode == W && on_wall(*game, "up") == 0)
			move_up(game, &update_path);
		else if (keycode == A && on_wall(*game, "left") == 0)
			move_left(game, &update_path);
		else if (keycode == S && on_wall(*game, "down") == 0)
			move_down(game, &update_path);
		else if (keycode == D && on_wall(*game, "right") == 0)
			move_right(game, &update_path);
		custom_msg(*game, 0);
		print_count(*game);
		render_frame(*game, previous_pos);
		move_enemy(game, &update_path, game->map.enemy_space);
	}
	return (0);
}

t_game	new_game(char *str, t_map map)
{
	t_game	game;

	game.height = map.size.y * TILE_SIZE;
	game.width = map.size.x * TILE_SIZE;
	game.map = map;
	game.counter = 0;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width, game.height, str);
	assign_textures(&game);
	return (game);
}

void	check_args(int argc, char **argv)
{
	if (argc != 2)
		ft_error(ERROR_ARGS);
	else
	{
		if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
			ft_error(ERROR_EXTENSION);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	map;

	check_args(argc, argv);
	map = parse_map(argv[1]);
	game = new_game("undertale", map);
	if (!game.mlx || !game.win)
		return (1);
	render_map(game);
	game.map.enemy_space = space_available(game.map);
	if (game.map.enemy_space == 1)
	{
		render_enemy(&game);
		path_enemy(&game.map);
	}
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, ON_DESTROY, 1L << 0, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
