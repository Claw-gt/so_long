/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:54:04 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/18 17:39:43 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	assign_textures(t_game *game)
{
	game->floor = mlx_xpm_file_to_image(game->mlx, FLOOR_PATH, &game->width, &game->height);
	game->wall = mlx_xpm_file_to_image(game->mlx, WALL_PATH, &game->width, &game->height);
	game->player = mlx_xpm_file_to_image(game->mlx, PLAYER_DOWN_PATH, &game->width, &game->height);
	game->exit = mlx_xpm_file_to_image(game->mlx, EXIT_PATH, &game->width, &game->height);
	game->collectable = mlx_xpm_file_to_image(game->mlx, COLLECTABLE_PATH, &game->width, &game->height);
	if (!game->floor || !game->wall || !game->player || !game->exit || !game->collectable)
		ft_error(ERROR_FILE);
}

void	render_frame(t_game game, t_vector previous_pos)
{
	if (game.map.map[previous_pos.y][previous_pos.x] == '0')
		mlx_put_image_to_window(game.mlx, game.win, game.floor, previous_pos.x * TILE_SIZE, previous_pos.y * TILE_SIZE);
	else if (game.map.map[previous_pos.y][previous_pos.x] == 'E')
		mlx_put_image_to_window(game.mlx, game.win, game.exit, previous_pos.x * TILE_SIZE, previous_pos.y * TILE_SIZE);
	if (game.map.map[game.map.player_pos.y][game.map.player_pos.x] == 'E')
		player_on_exit(game, game.map.player_pos.y, game.map.player_pos.x);
	else
		mlx_put_image_to_window(game.mlx, game.win, game.player, game.map.player_pos.x * TILE_SIZE, game.map.player_pos.y * TILE_SIZE);
}

void	render_floor(t_game game)
{
	int	rows;
	int	cols;

	rows = 0;
	cols = 0;
	while (game.map.map[rows])
	{
		cols = 0;
		while (game.map.map[rows][cols])
		{
			mlx_put_image_to_window(game.mlx, game.win, game.floor, cols * TILE_SIZE, rows * TILE_SIZE); //para que se impriman consecutivamente y no uno encima del otro
			cols++;
		}
		rows++;
	}
}
void    render_map(t_game game)
{
	int		rows;
	int		cols;

	rows = -1;
	render_floor(game);
	while (++rows < game.map.size.y)
	{
		cols = -1;
		while (++cols < game.map.size.x)
		{
			if (game.map.map[rows][cols] == '1')
				mlx_put_image_to_window(game.mlx, game.win, game.wall, cols * TILE_SIZE, rows * TILE_SIZE);
			else if (game.map.map[rows][cols] == 'E')
				mlx_put_image_to_window(game.mlx, game.win, game.exit, cols * TILE_SIZE, rows * TILE_SIZE);
			else if (game.map.map[rows][cols] == 'P')
				mlx_put_image_to_window(game.mlx, game.win, game.player, cols * TILE_SIZE, rows * TILE_SIZE);
			else if (game.map.map[rows][cols] == 'C')
				mlx_put_image_to_window(game.mlx, game.win, game.collectable, cols * TILE_SIZE, rows * TILE_SIZE);
		}
	}
}
