/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:50:26 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/21 20:00:59 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	move_up(t_game *game, int *update_path)
{
	int	h;
	int	w;

	h = game->height;
	w = game->width;
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] != 'E')
		game->map.map[game->map.player_pos.y][game->map.player_pos.x] = '0';
	game->map.player_pos.y--;
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] == 'C')
	{
		*update_path = 1;
		game->map.object--;
	}
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] != 'E')
		game->map.map[game->map.player_pos.y][game->map.player_pos.x] = 'P';
	mlx_destroy_image(game->mlx, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx, PLAYER_UP_PATH, &w, &h);
	if (!game->player)
		ft_error(ERROR_FILE);
	game->counter++;
}

void	move_down(t_game *game, int *update_path)
{
	int	h;
	int	w;

	h = game->height;
	w = game->width;
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] != 'E')
		game->map.map[game->map.player_pos.y][game->map.player_pos.x] = '0';
	game->map.player_pos.y++;
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] == 'C')
	{
		*update_path = 1;
		game->map.object--;
	}
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] != 'E')
		game->map.map[game->map.player_pos.y][game->map.player_pos.x] = 'P';
	mlx_destroy_image(game->mlx, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx, PLAYER_DOWN_PATH, &w, &h);
	if (!game->player)
		ft_error(ERROR_FILE);
	game->counter++;
}

void	move_left(t_game *game, int *update_path)
{
	int	h;
	int	w;

	h = game->height;
	w = game->width;
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] != 'E')
		game->map.map[game->map.player_pos.y][game->map.player_pos.x] = '0';
	game->map.player_pos.x--;
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] == 'C')
	{
		*update_path = 1;
		game->map.object--;
	}
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] != 'E')
		game->map.map[game->map.player_pos.y][game->map.player_pos.x] = 'P';
	mlx_destroy_image(game->mlx, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx, PLAYER_LEFT_PATH, &w, &h);
	if (!game->player)
		ft_error(ERROR_FILE);
	game->counter++;
}

void	move_right(t_game *game, int *update_path)
{
	int	h;
	int	w;

	h = game->height;
	w = game->width;
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] != 'E')
		game->map.map[game->map.player_pos.y][game->map.player_pos.x] = '0';
	game->map.player_pos.x++;
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] == 'C')
	{
		*update_path = 1;
		game->map.object--;
	}
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] != 'E')
		game->map.map[game->map.player_pos.y][game->map.player_pos.x] = 'P';
	mlx_destroy_image(game->mlx, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx, PLAYER_RIGHT_PATH, &w, &h);
	if (!game->player)
		ft_error(ERROR_FILE);
	game->counter++;
}
