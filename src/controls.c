/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:50:26 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/10 14:06:41 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int    move_player(int keycode, t_game *game)
{
	t_vector	prev_pos;
	
	prev_pos.x = game->map.player_pos.x;
	prev_pos.y = game->map.player_pos.y;
	if (keycode == W)
	{
		printf("Move up player\n");
		game->map.player_pos.y--;
		game->textures[2] =  mlx_xpm_file_to_image(game->mlx_ptr, "./possible_sprites/Player_img/player_scale.xpm", &game->width, &game->height);
		game->counter++;
	}
	else if (keycode == S)
	{
		printf("Move down player\n");
		game->map.player_pos.y++;
		game->counter++;
	}
	else if (keycode == D)
	{
		printf("Move right player\n");
		game->map.player_pos.x++;
		game->counter++;
	}
	else if (keycode == A)
	{
		printf("Move left player\n");
		game->map.player_pos.x--;
		game->counter++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->textures[0], prev_pos.x, prev_pos.y);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->textures[2], game->map.player_pos.x * 20, game->map.player_pos.y * 20);
	return (0);
}