/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:54:04 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/17 11:43:18 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	assign_textures(t_game *game)
{
	game->textures[0] = mlx_xpm_file_to_image(game->mlx_ptr, "./possible_sprites/50x50/floor_50x50.xpm", &game->width, &game->height);
	game->textures[1] = mlx_xpm_file_to_image(game->mlx_ptr, "./possible_sprites/50x50/wall_50x50.xpm", &game->width, &game->height);
	game->textures[2] = mlx_xpm_file_to_image(game->mlx_ptr, "./possible_sprites/50x50/player_33x50.xpm", &game->width, &game->height);
	game->textures[3] = mlx_xpm_file_to_image(game->mlx_ptr, "./possible_sprites/exit2.xpm", &game->width, &game->height);
	game->textures[4] = mlx_xpm_file_to_image(game->mlx_ptr, "./possible_sprites/collectable_small.xpm", &game->width, &game->height);
	// game->textures[5] = mlx_xpm_file_to_image(game->mlx_ptr, "./possible_sprites/50x50/player_up_50.xpm", &game->width, &game->height);
	// game->textures[6] = mlx_xpm_file_to_image(game->mlx_ptr, "./possible_sprites/50x50/player_left_50.xpm", &game->width, &game->height);
	// game->textures[7] = mlx_xpm_file_to_image(game->mlx_ptr, "./possible_sprites/50x50/player_right_50.xpm", &game->width, &game->height);
	if (!game->textures[0] || !game->textures[1] || !game->textures[2] || !game->textures[3] || !game->textures[4])
		ft_error(ERROR_FILE);
}

void	render_frame(t_game game, t_vector previous_pos)
{
	if (game.map.map[previous_pos.y][previous_pos.x] == '0')
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.textures[0], previous_pos.x * TILE_SIZE, previous_pos.y * TILE_SIZE);
	else if (game.map.map[previous_pos.y][previous_pos.x] == 'E')
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.textures[3], previous_pos.x * TILE_SIZE, previous_pos.y * TILE_SIZE);
	if (game.map.map[game.map.player_pos.y][game.map.player_pos.x] == 'E')
		player_on_exit(game, game.map.player_pos.y, game.map.player_pos.x);
	else
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.textures[2], game.map.player_pos.x * TILE_SIZE, game.map.player_pos.y * TILE_SIZE);
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
			mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.textures[0], cols * TILE_SIZE, rows * TILE_SIZE); //para que se impriman consecutivamente y no uno encima del otro
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
			// if (game.map.map[rows][cols] == 'E' && game.map.player_pos.x == cols && game.map.player_pos.y == rows)
			// 	player_on_exit(game, rows, cols);
			// else
			// {
				if (game.map.map[rows][cols] == '1')
					mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.textures[1], cols * TILE_SIZE, rows * TILE_SIZE);
				else if (game.map.map[rows][cols] == 'E')
					mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.textures[3], cols * TILE_SIZE, rows * TILE_SIZE);
				else if (game.map.map[rows][cols] == 'P')
					mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.textures[2], cols * TILE_SIZE, rows * TILE_SIZE);
				else if (game.map.map[rows][cols] == 'C')
					mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.textures[4], cols * TILE_SIZE, rows * TILE_SIZE);
			//}
		}
	}
}
