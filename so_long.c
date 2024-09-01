/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:50:42 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/01 15:28:20 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pixel_img(t_image img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img.width && y < img.height)
	{
		dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
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
int     exit_game(t_data *window)
{
	if (window)
		mlx_destroy_window (window->mlx, window->win);
	exit(EXIT_SUCCESS);
}

t_data	new_game(int width, int height, char *str)
{
	t_data	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, width, height, str);
	return (game);
}

t_image	new_img(int width, int height, t_data window)
{
	t_image	image;

	image.win = window;
	image.img = mlx_new_image(window.mlx, width, height);
	image.addr = mlx_get_data_addr(image.img, &(image.bits_per_pixel), &(image.line_length), &(image.endian));
	image.width = width;
	image.height = height;
	return (image);
}

int	main(void)
{
	t_data	game;
	t_image	img;
	//void	*character;
	// int		width;
	// int		height;

	// width = 30;
	// height = 30;
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
	game.win = mlx_new_window(game.mlx, 300, 300, "Hello world!");
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
	// character = mlx_xpm_file_to_image(game.mlx, "assets/Link.xpm", &width, &height);
	// mlx_put_image_to_window(game.mlx, game.mlx, character, 1800, 500);
	//mlx_hook(game.win, DestroyNotify, StructureNotifyMask, &on_destroy, &game);
	
	img.win = game;
	img.img = mlx_new_image(game.mlx, 300, 300);
	// if (img.img == NULL)
	//     exit(EXIT_FAILURE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.width = 300;
	img.height = 300;
	printf("Let's Find out what's inside our structure :D\n");
	printf("img_ptr		: [%p]\n", img.img);
	printf("bpp		: [%d]\n", img.bits_per_pixel);
	printf("line_len	: [%d]\n", img.line_length);
	printf("endian		: [%d]\n", img.endian);
	printf("addr		: [%p]\n", img.addr);
	//memcpy(img.addr, "s4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vf", 16*4);
	put_pixel_img(img, 150, 150, 0x00FFFFFF);
	mlx_put_image_to_window(img.win.mlx, img.win.win, img.img, 10, 10);
	mlx_hook(game.win, 17, 1L << 0, exit_game, &game);
	// my_mlx_pixel_put(&img, 5, 5, 0xFFFF0000);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(game.mlx);
	// mlx_destroy_window(game.mlx, game.win);
	// mlx_destroy_display(game.mlx);
	// free (game.mlx);
	return (0);
}