/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_on_screen_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:21:28 by clagarci          #+#    #+#             */
/*   Updated: 2024/10/04 12:11:51 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	custom_msg(t_game game, int player_on_exit)
{
	int	center_col;
	int	first_row;

	first_row = TILE_SIZE / 2;
	center_col = (game.map.size.x / 2 - 1) * TILE_SIZE;
	if (player_on_exit == 1)
		print_msg(game, center_col, first_row, EXIT_MSG);
	else
	{
		print_img(game, game.wall, game.map.size.x / 2 * TILE_SIZE, 0);
		print_img(game, game.wall, (game.map.size.x / 2 - 1) * TILE_SIZE, 0);
	}
}

void	print_count(t_game game)
{
	char	*count_string;

	custom_msg(game, 0);
	count_string = ft_itoa(game.counter);
	ft_printf("Moves: %s\n", count_string);
	print_msg(game, 10, 20, "Moves:");
	print_img(game, game.wall, TILE_SIZE, 0);
	print_msg(game, 50, 20, count_string);
	free(count_string);
}
