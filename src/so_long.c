/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:50:42 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/19 12:59:47 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	exit_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->object);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_map(game->map.map, game->map.size.y);
	free(game->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

void	custom_msg(t_game game, int player_on_exit)
{
	int	center_col;
	int	first_row;

	first_row = TILE_SIZE / 2;
	center_col = game.map.size.x / 2 * TILE_SIZE;
	if (player_on_exit == 1)
		print_msg(game, center_col, first_row, EXIT_MSG);
	else
	{
		print_img(game, game.wall, game.map.size.x / 2 * TILE_SIZE, 0);
		print_img(game, game.wall, (game.map.size.x / 2 + 1) * TILE_SIZE, 0);
	}
}

void	player_on_exit(t_game game, int r, int c)
{
	int	width;
	int	height;

	width = c * TILE_SIZE;
	height = r * TILE_SIZE;
	print_img(game, game.exit, width, height);
	print_img(game, game.player, width, height);
	custom_msg(game, 1);
	if (game.map.object == 0)
	{
		ft_printf("You WON!\n");
		exit_game(&game);
	}
	else
	{
		if (game.map.object == 1)
			ft_printf("You need to collect one last heart!\n");
		else
			ft_printf("%d hearts remaining!\n", game.map.object);
	}
}

void	print_count(t_game game)
{
	char	*count_string;

	count_string = ft_itoa(game.counter);
	ft_printf("Moves: %s\n", count_string);
	print_msg(game, 10, 20, "Moves:");
	print_img(game, game.wall, TILE_SIZE, 0);
	print_msg(game, 50, 20, count_string);
	free(count_string);
}

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

	size = game->map.size;
	previous_pos = game->map.player_pos;
	if (keycode == ESC)
		exit_game(game);
	if (previous_pos.x < size.x && previous_pos.y < size.y)
	{
		if (keycode == W && on_wall(*game, "up") == 0)
			move_up(game);
		else if (keycode == A && on_wall(*game, "left") == 0)
			move_left(game);
		else if (keycode == S && on_wall(*game, "down") == 0)
			move_down(game);
		else if (keycode == D && on_wall(*game, "right") == 0)
			move_right(game);
		custom_msg(*game, 0);
		print_count(*game);
		render_frame(*game, previous_pos);
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

void	leaks(void)
{
	system("leaks -qso_long");
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	map;

	atexit(leaks);
	check_args(argc, argv);
	map = parse_map(argv[1]);
	game = new_game("undertale", map);
	if (!game.mlx || !game.win)
		return (1);
	render_map(game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, ON_DESTROY, 1L << 0, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
