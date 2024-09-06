/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:36:07 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/06 12:58:33 by clagarci         ###   ########.fr       */
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

int	parse_map(t_map map)
{
	int	i;
	int	j;
	int	player;
	int	exit;
	int	collectable;
	
	player = 0;
	exit = 0;
	collectable = 0;
	i = -1;
	j = -1;
	while (++i < map.size.y)
	{
		j = 0;
		while (++j < map.size.x)
		{
			if (map.map[0][j] != '1' || map.map[map.size.y - 1][j] != '1' || \
			 map.map[i][0] != '1' || map.map[i][map.size.x - 1] != '1')
			{
				perror("Map is not surrounded by walls");
				return (-1);
			}
			if (map.map[i][j] == 'P')
				player++;
			else if (map.map[i][j] == 'E')
				exit++;
			else if (map.map[i][j] == 'C')
				collectable++;
		}
	}
	if (player != 1 || exit != 1 || collectable < 1)
	{
		if (player != 1)
			perror("Map must have one player");
		if (exit != 1)
			perror("Map must have one exit");
		if (collectable < 1)
			perror("Map must have at least one collectable");
		return (-1);
	}
	return (0);
}
void	print_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.size.y)
	{
		ft_putendl_fd(map.map[i], 1);
		i++;
	}
}

t_vector	dimensions(char *path)
{
	int		    file;
	char	    *str;
	t_vector    dim;
	int         first;
	size_t		rows;
	size_t		cols;

	first = 1;
	rows = 0;
	cols = 0;
	file = open(path, O_RDONLY);
	if (file == -1)
		exit(EXIT_FAILURE);
	while ((str = get_next_line(file)))
	{
		if (ft_strlen(str) != cols && first == 0)
		{
			free (str);
			perror("Wrong map dimensions");
			exit (EXIT_FAILURE);
		}
		cols = ft_strlen(str);
		first = 0;
		free (str);
		rows++;
	}
	close(file);
	dim.x = cols - 1;
	dim.y = rows;
	return (dim);
}

t_map   open_map(char *path)
{
    int		    file;
	char	    *str;
    size_t		rows;
	t_map		map;

	rows = 0;
	map.size = dimensions(path);
	map.map = (char **)malloc(sizeof(char *) * map.size.y);
	if (!map.map)
		exit (EXIT_FAILURE);
	file = open(path, O_RDONLY);
	if (file == -1)
		exit(EXIT_FAILURE);
	while ((str = get_next_line(file)))
	{
		map.map[rows] = ft_strdup(str);
		if (!map.map[rows])
			free_map(map.map, rows);
		free (str);
		rows++;
	}
	print_map(map);
	if (parse_map(map) == -1)
		map.map = free_map(map.map, map.size.y);
	return (map);
}