/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduced_mlx_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:17:27 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/21 13:26:50 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	print_img(t_game game, void *img, int width, int height)
{
	mlx_put_image_to_window(game.mlx, game.win, img, width, height);
}

void	print_msg(t_game game, int x, int y, char *str)
{
	mlx_string_put(game.mlx, game.win, x, y, WHITE, str);
}
