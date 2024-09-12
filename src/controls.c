/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:50:26 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/12 14:46:56 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_up(t_game *game)
{
	game->map.map[game->map.player_pos.y][game->map.player_pos.x] = '0';
	game->map.player_pos.y--;
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] == 'C')
		game->map.collectable--;
	else if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] == 'E' && \
		game->map.collectable == 0)
	{
		ft_printf("You win!\n");
		exit_game(game);
	}
	
	//game->textures[2] = mlx_xpm_file_to_image(game->mlx_ptr, "./possible_sprites/Player_img/player_up_transparent.xpm", &game->width, &game->height);
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] != 'E')
		game->map.map[game->map.player_pos.y][game->map.player_pos.x] = 'P';
	else
		ft_printf("You need to collect all the collectables first!\n");
	game->counter++;
	//render_map(*game);
}
void	move_down(t_game *game)
{
	game->map.map[game->map.player_pos.y][game->map.player_pos.x] = '0';
	game->map.player_pos.y++;
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] == 'C')
		game->map.collectable--;
	game->map.map[game->map.player_pos.y][game->map.player_pos.x] = 'P';
	game->counter++;
	//render_map(*game);
}

void	move_left(t_game *game)
{
	game->map.map[game->map.player_pos.y][game->map.player_pos.x] = '0';
	game->map.player_pos.x--;
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] == 'C')
		game->map.collectable--;
	game->map.map[game->map.player_pos.y][game->map.player_pos.x] = 'P';
	game->counter++;
	//render_map(*game);
}

void	move_right(t_game *game)
{
	game->map.map[game->map.player_pos.y][game->map.player_pos.x] = '0';
	game->map.player_pos.x++;
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] == 'C')
		game->map.collectable--;
	game->map.map[game->map.player_pos.y][game->map.player_pos.x] = 'P';
	game->counter++;
	//render_map(*game);
}

int    move_player(int keycode, t_game *game)
{
	// t_vector	prev_pos;
	
	// prev_pos.x = game->map.player_pos.x;
	// prev_pos.y = game->map.player_pos.y;
	// if (keycode == W)
	// {
	// 	printf("Move up player\n");
	// 	game->map.map[game->map.player_pos.y][game->map.player_pos.x] = '0';
	// 	game->map.player_pos.y--;
	// 	game->map.map[game->map.player_pos.y][game->map.player_pos.x] = 'P';
	// 	//free(game->textures[2]);
	// 	//game->textures[2] =  mlx_xpm_file_to_image(game->mlx_ptr, "./possible_sprites/Player_img/player_scale.xpm", &game->width, &game->height);
	// 	// if (!game->textures[2])
	// 	// 	ft_error(ERROR_FILE);
	// 	game->counter++;
	// 	//display(*game);
	// }
	if (keycode == S) 
	{
		printf("Move down player\n");
		game->map.map[game->map.player_pos.y][game->map.player_pos.x] = '0';
		game->map.player_pos.y++;
		game->map.map[game->map.player_pos.y][game->map.player_pos.x] = 'P';
		game->counter++;
	}
	else if (keycode == D)
	{
		printf("Move right player\n");
		game->map.map[game->map.player_pos.y][game->map.player_pos.x] = '0';
		game->map.player_pos.x++;
		game->map.map[game->map.player_pos.y][game->map.player_pos.x] = 'P';
		game->counter++;
	}
	else if (keycode == A)
	{
		printf("Move left player\n");
		game->map.map[game->map.player_pos.y][game->map.player_pos.x] = '0';
		game->map.player_pos.x--;
		game->map.map[game->map.player_pos.y][game->map.player_pos.x] = 'P';
		game->counter++;
	}
	render_map(*game);
	//mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->textures[0], prev_pos.x, prev_pos.y);
	//mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->textures[2], game->map.player_pos.x * 20, game->map.player_pos.y * 20);
	return (0);
}