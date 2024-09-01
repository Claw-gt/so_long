/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:50:42 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/01 14:42:34 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_image *game, int x, int y, int color)
{
	char	*dst;

	dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int on_destroy(t_data *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	//return (0);
	exit(0);
}

int on_keypress(int keysym, t_data *game)
{
	(void)game;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

t_game	new_game(int width, int height, char *str)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, width, height, str);
	return (game);
}

int	main(void)
{
	t_data	game;
	//t_image	img;
	void	*character;
	int		width;
	int		height;

	width = 30;
	height = 30;
	// game = new_game(1920, 1080, "Hello World!");
	// if (!game.mlx || !game.win)
	// 	return (1);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
	{
		perror("Failed to initialise MiniLibX");
		return (1);
		//exit(EXIT_FAILURE);
	}
	game.win = mlx_new_window(game.mlx, 1920, 1080, "Hello world!");
	if (game.win == NULL)
	{
	    perror("Failed to initialise MiniLibX");
	    free (game.mlx);
		return (1);
		//exit(EXIT_FAILURE);
	}
	//mlx_hook(game.win, KeyRelease, KeyReleaseMask, &on_keypress, &game);
	//mlx_hook(game.win, 2, 1L<<0, &on_keypress, &game);
	//mlx_hook(game.win,17, 1L<<17, &on_destroy, &game);
	character = mlx_xpm_file_to_image(game.mlx, "assets/Link.xpm", &width, &height);
	mlx_put_image_to_window(game.mlx, game.mlx, character, 1800, 500);
	//mlx_hook(game.win, DestroyNotify, StructureNotifyMask, &on_destroy, &game);
	
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// if (img.img == NULL)
	//     exit(EXIT_FAILURE);
	// img.addr = mlx_get_game_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0xFFFF0000);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.win);
	mlx_destroy_display(game.mlx);
	free (game.mlx);
	return (0);
}