/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:50:26 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/16 12:50:40 by clagarci         ###   ########.fr       */
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
	free(game->textures[2]);
	game->textures[2] = mlx_xpm_file_to_image(game->mlx_ptr, "./possible_sprites/50x50/player_up_50.xpm", &game->width, &game->height);
	if (!game->textures[2])
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
	free(game->textures[2]);
	game->textures[2] = mlx_xpm_file_to_image(game->mlx_ptr, "./possible_sprites/50x50/player_33x50.xpm", &game->width, &game->height);
	if (!game->textures[2])
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
	free(game->textures[2]);
	game->textures[2] = mlx_xpm_file_to_image(game->mlx_ptr, "./possible_sprites/50x50/player_left_50.xpm", &game->width, &game->height);
	if (!game->textures[2])
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
	free(game->textures[2]);
	game->textures[2] = mlx_xpm_file_to_image(game->mlx_ptr, "./possible_sprites/50x50/player_right_50.xpm", &game->width, &game->height);
	if (!game->textures[2])
		ft_error(ERROR_FILE);
	game->counter++;
}
