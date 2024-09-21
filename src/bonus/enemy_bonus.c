/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:21:32 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/21 14:07:21 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	flood_fill_enemy(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x > (map->size.x - 1) || y > (map->size.y - 1) || \
	map->map[y][x] == '1' || map->map[y][x] == 'F' || map->map[y][x] == 'C')
		return ;
	map->map[y][x] = 'F';
	flood_fill_enemy(map, x + 1, y);
	flood_fill_enemy(map, x - 1, y);
	flood_fill_enemy(map, x, y + 1);
	flood_fill_enemy(map, x, y - 1);
}

t_map	path_enemy(t_map map)
{
	t_map	map_aux;

	map_aux = create_copy(map);
    print_map(map_aux);
	flood_fill_enemy(&map_aux, map_aux.enemy_pos.x, map_aux.enemy_pos.y);
	print_map(map_aux);
	return (map_aux);
}

void	move_enemy(t_game *game)
{
	t_map	path;

	path = path_enemy(game->map);
	while (path.map[game->map.enemy_pos.y][game->map.enemy_pos.x - 1] == 'F')
	{
		//sleep(1);
		print_img(*game, game->enemy, (game->map.enemy_pos.x - 1) * TILE_SIZE, game->map.enemy_pos.y * TILE_SIZE);
		print_img(*game, game->floor, game->map.enemy_pos.x * TILE_SIZE, game->map.enemy_pos.y * TILE_SIZE);
		game->map.enemy_pos.x -= 1;
	}
	while (path.map[game->map.enemy_pos.y][game->map.enemy_pos.x + 1] == 'F')
	{
		//sleep(1);
		print_img(*game, game->enemy, (game->map.enemy_pos.x + 1) * TILE_SIZE, game->map.enemy_pos.y * TILE_SIZE);
		print_img(*game, game->floor, game->map.enemy_pos.x * TILE_SIZE, game->map.enemy_pos.y * TILE_SIZE);
		game->map.enemy_pos.x += 1;
	}
	while (path.map[game->map.enemy_pos.y - 1][game->map.enemy_pos.x] == 'F')
	{
		//sleep(1);
		print_img(*game, game->enemy, game->map.enemy_pos.x * TILE_SIZE, (game->map.enemy_pos.y - 1) * TILE_SIZE);
		print_img(*game, game->floor, game->map.enemy_pos.x * TILE_SIZE, game->map.enemy_pos.y * TILE_SIZE);
		game->map.enemy_pos.y -= 1;
	}
	while (path.map[game->map.enemy_pos.y + 1][game->map.enemy_pos.x] == 'F')
	{
		//sleep(1);
		print_img(*game, game->enemy, game->map.enemy_pos.x * TILE_SIZE, (game->map.enemy_pos.y + 1) * TILE_SIZE);
		print_img(*game, game->floor, game->map.enemy_pos.x * TILE_SIZE, game->map.enemy_pos.y * TILE_SIZE);
		game->map.enemy_pos.y += 1;
	}
	free_map(path.map, path.size.y);
}
