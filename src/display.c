/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:54:04 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/09 19:58:11 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	assign_textures(t_game *game)
{
	game->textures[0] = mlx_xpm_file_to_image(game->mlx_ptr, FLOOR_PATH, &game->width, &game->height);
	//game.textures[1] = mlx_xpm_file_to_image(game.mlx_ptr, WALL_PATH, &game.width, &game.height);
	game->textures[2] = mlx_xpm_file_to_image(game->mlx_ptr, "./possible_sprites/Player_img/player_down_transparent.xpm", &game->width, &game->height);
	//game.textures[3] = mlx_xpm_file_to_image(game.mlx_ptr, EXIT_PATH, &game.width, &game.height);
	//game.textures[4] = mlx_xpm_file_to_image(game.mlx_ptr, COLLECTABLE_PATH, &game.width, &game.height);
	//if (!game.textures[0] || !game.textures[1] || !game.textures[2] || !game.textures[3] || !game.textures[4])
	//	ft_error(ERROR_FILE);
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
			mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.textures[0], cols, rows);
			cols++;
		}
		rows++;
	}
}
void    display(t_game game)
{
	// int		rows;
	// int		cols;

	// cols = 0;
	// rows = 0;
	render_floor(game);
	// while (game.map.map[rows])
	// {
		
	// }
}