/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:46:55 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/22 13:20:25 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	*free_map(char **map, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		free (map[i]);
		i++;
	}
	free (map);
	return (NULL);
}

char	**duplicate_map(t_map map)
{
	char	**map_aux;
	int		rows;

	rows = 0;
	map_aux = (char **)malloc(sizeof(char *) * map.size.y);
	if (!map_aux)
		exit (EXIT_FAILURE);
	while (rows < map.size.y)
	{
		map_aux[rows] = ft_strdup(map.enemy_map[rows]);
		if (!map_aux[rows])
			free_map(map_aux, rows);
		rows++;
	}
	return (map_aux);
}

void	print_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.size.y)
	{
		ft_printf("%s\n", map.enemy_map[i]);
		i++;
	}
}

void	init_map(t_map *map)
{
	map->object = 0;
	map->exit = 0;
	map->player = 0;
	map->player_pos.x = 0;
	map->player_pos.y = 0;
	map->exit_pos.x = 0;
	map->exit_pos.y = 0;
	map->enemy_pos.x = 0;
	map->enemy_pos.y = 0;
	map->enemy_map = NULL;
}
