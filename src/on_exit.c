/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:29:21 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/19 19:30:41 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	exit_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->object);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_map(game->map.map, game->map.size.y);
	free(game->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

void	player_on_exit(t_game game, int r, int c)
{
	int	width;
	int	height;

	width = c * TILE_SIZE;
	height = r * TILE_SIZE;
	print_img(game, game.exit, width, height);
	print_img(game, game.player, width, height);
	custom_msg(game, 1);
	if (game.map.object == 0)
	{
		ft_printf("You WON!\n");
		exit_game(&game);
	}
	else
	{
		if (game.map.object == 1)
			ft_printf("You need to collect one last heart!\n");
		else
			ft_printf("%d hearts remaining!\n", game.map.object);
	}
}
