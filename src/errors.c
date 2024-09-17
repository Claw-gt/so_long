/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:02:23 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/17 15:02:54 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_error(int error_code)
{
	ft_printf("Error\n");
	if (error_code == ERROR_ARGS)
		ft_printf("Invalid number of arguments\n");
	else if (error_code == ERROR_EXTENSION)
		ft_printf("Invalid file extension\n");
	else if (error_code == ERROR_FILE)
		ft_printf("Invalid file\n");
	else if (error_code == ERROR_MAP_SIZE)
		ft_printf("Map is not rectangular\n");
	else if (error_code == ERROR_MAP_WALLS)
		ft_printf("Map is not surrounded by walls\n");
	else if (error_code == ERROR_MAP_CHARACTERS)
		ft_printf("Map contains invalid characters\n");
	else if (error_code == ERROR_MAP_COLLECTABLE)
		ft_printf("Map must have at least one collectable\n");
	else if (error_code == ERROR_MAP_PLAYER)
		ft_printf("Map must have one player\n");
	else if (error_code == ERROR_MAP_EXIT)
		ft_printf("Map must have one exit\n");
	else if (error_code == ERROR_MAP_PATH)
		ft_printf("Map path is invalid\n");
	exit (EXIT_FAILURE);
}
