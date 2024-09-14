/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:50:26 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/14 10:52:34 by clagarci         ###   ########.fr       */
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
	game->counter++;
}