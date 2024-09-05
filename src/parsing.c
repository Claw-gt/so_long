/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:36:07 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/05 15:37:13 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// static void	*free_map(char **arr, int num)
// {
// 	int	i;

// 	i = 0;
// 	while (i < num)
// 	{
// 		free (arr[i]);
// 		i++;
// 	}
// 	free (arr);
// 	return (NULL);
// }

void   open_map(char *path)
{
    int		    file;
	char	    *str;
    size_t		rows;
    size_t		cols;
    int			first;
	t_map		map;
	// int			i;

	// i = 0;
    first = 1;
    rows = 0;
    cols = 0;
    file = open(path, O_RDONLY);
	if (file == -1)
        exit(1);
	while ((str = get_next_line(file)))
    {
        ft_printf("\n********\n");
        ft_printf("sol_str\n");
        write(1, str, ft_strlen(str));
        if (ft_strlen(str) != cols && first == 0)
        {
			free (str);
            perror("Wrong map dimensions");
			return ;
			//exit (0);
	        exit(EXIT_FAILURE);
        }
        cols = ft_strlen(str);
        first = 0;
        free (str);
        rows++;
        ft_printf("\n********\n");
    }
	close(file);
	map.size.x = cols - 1;
	map.size.y = rows;
	ft_printf("Rows: %d Cols: %d", map.size.y, map.size.x);
	// map.map = (char **)ft_calloc(sizeof(char *), (rows + 1));
	// if (!map.map)
	// 	return ;
	// file = open(path, O_RDONLY);
	// if (file == -1)
    //     exit(1);
	// while (cols-- > 0)
	// {
	// 	map.map[i] = (char *)ft_calloc(sizeof(char), (map.size.x + 1));
	// 	if (!map.map[i])
	// 	{
	// 		free_map(map.map, i);
	// 		return ;
	// 	}
	// 	map.map[i] = get_next_line(file);
	// 	i++;
	// }
	//free(map.map);
}