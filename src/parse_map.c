/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:36:07 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/16 13:23:15 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


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
void	print_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.size.y)
	{
		printf("%s\n",map.map[i]);
		i++;
	}
}

void	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < map->size.y)
	{
		j = -1;
		while (++j < map->size.x)
			if (map->map[0][j] != '1' || map->map[map->size.y - 1][j] != '1' || 
			 map->map[i][0] != '1' || map->map[i][map->size.x - 1] != '1')
				ft_error(ERROR_MAP_WALLS);
	}
}
void	check_character(char element)
{
	if (element != '1' && element != '0' && element != 'P' && 
	element != 'E' && element != 'C')
		ft_error(ERROR_MAP_CHARACTERS);
}
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
			check_character(map->map[i][j]);
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
				map->collectable++;
		}
	}
}
// void	count_elements(t_map *map)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = -1;
// 	j = -1;
// 	while (++i < map->size.y)
// 	{
// 		j = 0;
// 		while (++j < map->size.x)
// 		{
// 			if (map->map[i][j] == 'P')
// 				map->player++;
// 			else if (map->map[i][j] == 'E')
// 				map->exit++;
// 			else if (map->map[i][j] == 'C')
// 				map->collectable++;
// 		}
// 	}
// 	if (map->player != 1)
// 		ft_error(ERROR_MAP_PLAYER);
// 	else if (map->exit != 1)
// 		ft_error(ERROR_MAP_EXIT);
// 	else if (map->collectable < 1)
// 		ft_error(ERROR_MAP_COLLECTABLE);
// }




// t_vector	check_dimensions(char *path)
// {
// 	int		    file;
// 	char	    *str;
// 	t_vector    dim;
// 	int         first;

// 	first = 1;
// 	dim.y = 0;
// 	dim.x = 0;
// 	file = open(path, O_RDONLY);
// 	if (file == -1)
// 		ft_error(ERROR_FILE);
// 	while ((str = get_next_line(file)))
// 	{
// 		//PROBLEMA: gnl no lee el ultimo caracter de la ultima linea pues no hay salto de linea
// 		if (ft_strlen(str) != (size_t)dim.x && first == 0)
// 		{
// 			printf("Prev Dim.x: %d Now Len: %zu\n", dim.x, ft_strlen(str));
// 			write(1, str, ft_strlen(str));
// 			ft_error(ERROR_MAP_SIZE);
// 		}
// 		dim.x = ft_strlen(str);
// 		printf("Dim.x: %d\n", dim.x);
// 		first = 0;
// 		free (str);
// 		dim.y++;
// 	}
// 	close(file);
// 	dim.x--;
// 	return (dim);
// }

void	init_map(t_map *map)
{
	map->collectable = 0;
	map->exit = 0;
	map->player = 0;
	map->player_pos.x = 0;
	map->player_pos.y = 0;
	map->exit_pos.x = 0;
	map->exit_pos.y = 0;
}

// t_map   open_map(char *path)
// {
//     int		    file;
// 	char	    *str;
//     size_t		rows;
// 	t_map		map;

// 	rows = 0;
// 	map.size = check_dimensions(path);
// 	map.map = (char **)malloc(sizeof(char *) * map.size.y);
// 	if (!map.map)
// 		exit (EXIT_FAILURE);
// 	file = open(path, O_RDONLY);
// 	if (file == -1)
// 		ft_error(ERROR_FILE);
// 	while ((str = get_next_line(file)))
// 	{
// 		map.map[rows] = ft_strdup(str);
// 		if (!map.map[rows])
// 			free_map(map.map, rows);
// 		free (str);
// 		rows++;
// 	}
// 	print_map(map);
// 	return (map);
// }
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
t_map   open_map(char *path)
{
    int		    file;
	char	    *str;
	t_map		map;
	char		*map_aux;
	char		*aux;

	map_aux = ft_strdup("");
	if (!map_aux)
		exit (EXIT_FAILURE);
	file = open(path, O_RDONLY);
	if (file == -1)
		ft_error(ERROR_FILE);
	while ((str = get_next_line(file)))
	{
		if (str[0] == '\n')
			ft_error(ERROR_MAP_SIZE); // para evitar que se lea un salto de linea como una linea
		aux = ft_strjoin(map_aux, str);
		free (map_aux);
		map_aux = aux;
		free (str);
	}
	map.map = ft_split(map_aux, '\n');
	free (map_aux);
	close(file);
	return (map);
}

t_map	parse_map(char *path)
{
	t_map	map;

	map = open_map(path);
	check_dimensions(&map);
	print_map(map);
	printf("Cols: %d\nRows: %d\n", map.size.x, map.size.y);
	init_map(&map);
	check_walls(&map);
	count_elements(&map);
	if (map.player != 1)
		ft_error(ERROR_MAP_PLAYER);
	else if (map.exit != 1)
		ft_error(ERROR_MAP_EXIT);
	else if (map.collectable < 1)
		ft_error(ERROR_MAP_COLLECTABLE);
	check_path(map);
	return (map);
}
