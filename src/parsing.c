/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:36:07 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/05 15:15:45 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_vector   open_map(char *path)
{
    int		    file;
	char	    *str;
	t_vector	size;
    size_t		rows;
    size_t		cols;
    int			first;

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
			//exit (0);
	        exit(EXIT_FAILURE);
        }
        cols = ft_strlen(str);
        first = 0;
        free (str);
        rows++;
        ft_printf("\n********\n");
    }
	size.x = cols - 1;
	size.y = rows;
	ft_printf("Rows: %d Cols: %d", size.y, size.x);
	return (size);
}

//t_map	store_map()