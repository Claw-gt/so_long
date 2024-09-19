/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:36:07 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/19 12:51:13 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_char_and_walls(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < map->size.y)
	{
		j = -1;
		while (++j < map->size.x)
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0' && \
				map->map[i][j] != 'P' && map->map[i][j] != 'E' && \
				map->map[i][j] != 'C')
				ft_error(ERROR_MAP_CHARACTERS);
			if (map->map[0][j] != '1' || map->map[map->size.y - 1][j] != '1' || \
			map->map[i][0] != '1' || map->map[i][map->size.x - 1] != '1')
				ft_error(ERROR_MAP_WALLS);
		}
	}
}

// void	check_character(char element)
// {
// 	if (element != '1' && element != '0' && element != 'P' &&
// 	element != 'E' && element != 'C')
// 		ft_error(ERROR_MAP_CHARACTERS);
// }

void	count_elements(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < map->size.y)
	{
		j = -1;
		while (++j < map->size.x)
		{
			//check_character(map->map[i][j]);
			if (map->map[i][j] == 'P')
			{
				map->player_pos = (t_vector){j, i};
				map->player++;
			}
			else if (map->map[i][j] == 'E')
			{
				map->exit_pos = (t_vector){j, i};
				map->exit++;
			}
			else if (map->map[i][j] == 'C')
				map->object++;
		}
	}
}

void	check_dimensions(t_map *map)
{
	int	rows;
	int	cols;
	int	first;

	rows = 0;
	cols = 0;
	first = 1;
	while (map->map[rows])
	{
		if (ft_strlen(map->map[rows]) != (size_t)cols && first == 0)
			ft_error(ERROR_MAP_SIZE);
		cols = ft_strlen(map->map[rows]);
		first = 0;
		rows++;
	}
	map->size.y = rows;
	map->size.x = cols;
}

char	*open_map(char *path)
{
	int		file;
	char	*str;
	char	*map_aux;
	char	*aux;

	map_aux = ft_strdup("");
	if (!map_aux)
		exit (EXIT_FAILURE);
	file = open(path, O_RDONLY);
	if (file == -1)
		ft_error(ERROR_FILE);
	str = get_next_line(file);
	while (str)
	{
		if (str[0] == '\n')
			ft_error(ERROR_MAP_SIZE);
		aux = ft_strjoin(map_aux, str);
		free (map_aux);
		map_aux = aux;
		free (str);
		str = get_next_line(file);
	}
	close(file);
	return (map_aux);
}

t_map	parse_map(char *path)
{
	t_map	map;
	char	*map_aux;

	map_aux = open_map(path);
	map.map = ft_split(map_aux, '\n');
	free (map_aux);
	check_dimensions(&map);
	print_map(map);
	printf("Cols: %d\nRows: %d\n", map.size.x, map.size.y);
	init_map(&map);
	check_char_and_walls(&map);
	count_elements(&map);
	printf("Player position: %d %d", map.player_pos.x, map.player_pos.y);
	if (map.player != 1)
		ft_error(ERROR_MAP_PLAYER);
	else if (map.exit != 1)
		ft_error(ERROR_MAP_EXIT);
	else if (map.object < 1)
		ft_error(ERROR_MAP_OBJECT);
	check_path(map);
	return (map);
}
