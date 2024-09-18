/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:50:26 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/18 14:47:23 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_up(t_game *game)
{
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] != 'E')
		game->map.map[game->map.player_pos.y][game->map.player_pos.x] = '0';
	game->map.player_pos.y--;
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] == 'C')
		game->map.collectable--;
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] != 'E')
		game->map.map[game->map.player_pos.y][game->map.player_pos.x] = 'P';
	mlx_destroy_image(game->mlx_ptr, game->player_img);
	game->player_img = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER_UP_PATH, &game->width, &game->height);
	if (!game->player_img)
		ft_error(ERROR_FILE);
	game->counter++;
}
void	move_down(t_game *game)
{
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] != 'E')
		game->map.map[game->map.player_pos.y][game->map.player_pos.x] = '0';
	game->map.player_pos.y++;
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] == 'C')
		game->map.collectable--;
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] != 'E')
		game->map.map[game->map.player_pos.y][game->map.player_pos.x] = 'P';
	mlx_destroy_image(game->mlx_ptr, game->player_img);
	game->player_img = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER_DOWN_PATH, &game->width, &game->height);
	if (!game->player_img)
		ft_error(ERROR_FILE);
	game->counter++;
}

void	move_left(t_game *game)
{
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] != 'E')
		game->map.map[game->map.player_pos.y][game->map.player_pos.x] = '0';
	game->map.player_pos.x--;
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] == 'C')
		game->map.collectable--;
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] != 'E')	
		game->map.map[game->map.player_pos.y][game->map.player_pos.x] = 'P';
	mlx_destroy_image(game->mlx_ptr, game->player_img);
	game->player_img = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER_LEFT_PATH, &game->width, &game->height);
	if (!game->player_img)
		ft_error(ERROR_FILE);
	game->counter++;
}

void	move_right(t_game *game)
{
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] != 'E')
		game->map.map[game->map.player_pos.y][game->map.player_pos.x] = '0';
	game->map.player_pos.x++;
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] == 'C')
		game->map.collectable--;
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] != 'E')	
		game->map.map[game->map.player_pos.y][game->map.player_pos.x] = 'P';
	mlx_destroy_image(game->mlx_ptr, game->player_img);
	game->player_img = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER_RIGHT_PATH, &game->width, &game->height);
	if (!game->player_img)
		ft_error(ERROR_FILE);
	game->counter++;
}
