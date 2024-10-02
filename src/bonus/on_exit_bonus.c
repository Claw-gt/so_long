/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:29:21 by clagarci          #+#    #+#             */
/*   Updated: 2024/10/02 18:53:35 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

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
	if (game->map.enemy_map)
		free_map(game->map.enemy_map, game->map.size.y);
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

void	enemy_on_exit(t_game game, int r, int c)
{
	int	width;
	int	height;

	width = c * TILE_SIZE;
	height = r * TILE_SIZE;
	print_img(game, game.exit, width, height);
	print_img(game, game.enemy, width, height);
}

void	enemy_attack(t_game *game)
{
	int	width;
	int	height;

	width = game->map.player_pos.x * TILE_SIZE;
	height = game->map.player_pos.y * TILE_SIZE;
	print_img(*game, game->floor, width, height);
	print_img(*game, game->ghost, width, height);
	ft_printf("You LOST!\n");
	game->dead = 1;
	//exit_game(game);
}
