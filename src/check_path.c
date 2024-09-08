/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:52:40 by marvin            #+#    #+#             */
/*   Updated: 2024/09/08 18:52:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


void    flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x > (map->size.x - 1) || y > (map->size.y - 1) || \
	map->map[y][x] == '1' || map->map[y][x] == 'F')
		return ;
	if (map->map[y][x] == 'C')
		map->collectable--;
    map->map[y][x] = 'F';
    flood_fill(map, x + 1, y);
    flood_fill(map, x - 1, y);
    flood_fill(map, x, y + 1);
    flood_fill(map, x, y - 1);
}

t_map   create_copy(t_map map)
{
    t_map   map_copy;
    int  rows;

    rows = 0;
    map_copy.size = map.size;
    map_copy.collectable = map.collectable;
    map_copy.exit = map.exit;
    map_copy.player = map.player;
    map_copy.player_pos = map.player_pos;
	map_copy.exit_pos = map.exit_pos;
    map_copy.map = (char **)malloc(sizeof(char *) * map.size.y);
    if (!map_copy.map)
        exit (EXIT_FAILURE);
    while (rows < map.size.y)
    {
        map_copy.map[rows] = ft_strdup(map.map[rows]);
        if (!map_copy.map[rows])
			free_map(map_copy.map, rows);
        rows++;
    }
    return (map_copy);
}

void	check_path(t_map map)
{
    t_map   map_aux;

    map_aux = create_copy(map);
    ft_printf("Collectable: %d\n Player pos: [%d, %d]\n", map_aux.collectable, map_aux.player_pos.y, map_aux.player_pos.x);
	flood_fill(&map_aux, map_aux.player_pos.x, map_aux.player_pos.y);
    print_map(map_aux);
    ft_printf("Collectable %d", map_aux.collectable);
	if (map_aux.collectable != 0)
		ft_error(ERROR_MAP_PATH);
	if (map_aux.map[map_aux.exit_pos.y][map_aux.exit_pos.x] != 'F')
		ft_error(ERROR_MAP_PATH);
	free_map(map_aux.map, map_aux.size.y);
}