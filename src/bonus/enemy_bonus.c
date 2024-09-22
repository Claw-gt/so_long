/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:21:32 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/22 14:12:48 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

int	on_enemy(t_vector player_pos, t_vector enemy_pos)
{
	if (player_pos.x == enemy_pos.x && player_pos.y == enemy_pos.y)
		return (1);
	return (0);
}

void	path_enemy(t_map *map)
{
	t_map	map_aux;
	char	**aux;

	map_aux = create_copy(*map);
	flood_fill(&map_aux, map_aux.enemy_pos.x, map_aux.enemy_pos.y, 1);
	map_aux.enemy_map = map_aux.map;
	aux = duplicate_map(map_aux);
	if (map->enemy_map)
		free_map(map->enemy_map, map->size.y);
	map->enemy_map = aux;
	free_map(map_aux.map, map_aux.size.y);
}

int	on_path(t_game game, char *direction)
{
	int		x;
	int		y;
	char	**map_aux;

	x = game.map.enemy_pos.x;
	y = game.map.enemy_pos.y;
	map_aux = game.map.enemy_map;
	if (ft_strncmp(direction, "up", 2) == 0)
		y -= 1;
	else if (ft_strncmp(direction, "left", 4) == 0)
		x -= 1;
	else if (ft_strncmp(direction, "down", 4) == 0)
		y += 1;
	else if (ft_strncmp(direction, "right", 5) == 0)
		x += 1;
	if (map_aux[y][x] != 'F')
		return (0);
	return (1);
}

void	persecute_player(t_game *game, char *direction)
{
	int	width;
	int	height;

	width = game->map.enemy_pos.x * TILE_SIZE;
	height = game->map.enemy_pos.y * TILE_SIZE;
	if (game->map.map[game->map.enemy_pos.y][game->map.enemy_pos.x] == 'E')
		print_img(*game, game->exit, width, height);
	else
		print_img(*game, game->floor, width, height);
	if (ft_strncmp(direction, "up", 2) == 0)
		game->map.enemy_pos.y -= 1;
	else if (ft_strncmp(direction, "left", 4) == 0)
		game->map.enemy_pos.x -= 1;
	else if (ft_strncmp(direction, "down", 4) == 0)
		game->map.enemy_pos.y += 1;
	else if (ft_strncmp(direction, "right", 5) == 0)
		game->map.enemy_pos.x += 1;
	width = game->map.enemy_pos.x * TILE_SIZE;
	height = game->map.enemy_pos.y * TILE_SIZE;
	print_img(*game, game->enemy, width, height);
}

void	move_enemy(t_game *game, int *update_path, int space_available)
{
	int	right;
	int	up;
	int	left;
	int	down;

	if (space_available == 0)
		return ;
	if (*update_path == 1)
		path_enemy(&game->map);
	right = on_path(*game, "right");
	up = on_path(*game, "up");
	left = on_path(*game, "left");
	down = on_path(*game, "down");
	if (game->map.player_pos.x > game->map.enemy_pos.x && right == 1)
		persecute_player(game, "right");
	else if (game->map.player_pos.y > game->map.enemy_pos.y && down == 1)
		persecute_player(game, "down");
	else if (game->map.player_pos.x < game->map.enemy_pos.x && left == 1)
		persecute_player(game, "left");
	else if (game->map.player_pos.y < game->map.enemy_pos.y && up == 1)
		persecute_player(game, "up");
	if (game->map.map[game->map.enemy_pos.y][game->map.enemy_pos.x] == 'P')
		enemy_attack(game);
}
