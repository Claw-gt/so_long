/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tutorial.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:50:42 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/12 14:44:35 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;
	
	img.img_ptr = mlx_xpm_file_to_image(mlx, path, &img.width, &img.height);
	if (!img.img_ptr)
	 	exit (1);
	img.addr  = mlx_get_data_addr(img.img_ptr, &(img.bits_per_pixel), &(img.line_length), &(img.endian));
	return (img);
}

void	put_pixel_img(t_image img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img.width && y < img.height)
	{
		dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void	draw_square(t_square square, t_image img)
{
	unsigned short int	i;
	unsigned short int	j;

	i = 0;
	while (i < square.size && i + square.y < img.height)
	{
		j = 0;
		while (j < square.size && j + square.x < img.width)
		{
			put_pixel_img(img, j + square.x, i + square.y, square.color);
			j++;
		}
		i++;
	}
}

void	draw_line(t_game game, int beginX, int beginY, int endX, int endY, int color)
{
	double deltaX = endX - beginX; // 10
	double deltaY = endY - beginY; // 0
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels; // 1
	deltaY /= pixels; // 0
	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
		mlx_pixel_put(game.mlx_ptr, game.win_ptr, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}

int exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free_map(game->map.map, game->map.size.y);
	free(game->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

int on_keypress(int keysym, t_game *game)
{
	(void)game;
	printf("Pressed key: %d\n", keysym);
	return (0);
}
int	key_hook(int keycode, t_game *game)
{
	printf("Pressed key: %d\n", keycode);
	if (keycode == ESC)
		exit_game(game);
	if (game->map.player_pos.x < game->map.size.x && game->map.player_pos.y < game->map.size.y)
	{
		if (keycode == W && game->map.map[game->map.player_pos.y - 1][game->map.player_pos.x] != '1')
			move_up(game);
		else if (keycode == A && game->map.map[game->map.player_pos.y][game->map.player_pos.x - 1] != '1')
			move_left(game);
		else if (keycode == S && game->map.map[game->map.player_pos.y + 1][game->map.player_pos.x] != '1')
			move_down(game);
		else if (keycode == D && game->map.map[game->map.player_pos.y][game->map.player_pos.x + 1] != '1')
			move_right(game);
		render_map(*game);
	}
	// else if (keycode == W || keycode == A || keycode == S || keycode == D)
	// 	move_player(keycode, game);
	return (0);
}

t_game	new_game(int width, int height, char *str)
{
	t_game	game;

	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, width, height, str);
	return (game);
}

t_image	new_img(int width, int height, t_game window)
{
	t_image	image;

	image.window = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, width, height);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bits_per_pixel), &(image.line_length), &(image.endian));
	image.width = width;
	image.height = height;
	return (image);
}

int	main(int argc, char **argv)
{
	t_game	game;
	//t_image	img;
	//char	*path;
	//t_image	character;
	// int		img_width;
	// int		img_height;
	
	if (argc != 2)
	{
		perror("Wrong number of arguments");
		return (1);
	}
	else
	{
		if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		{
			perror("Wrong file extension");
			return (1);
		}
	}
	//path = "../textures/Link.xpm";
	game = new_game(500, 500, "tutorial");
	if (!game.mlx_ptr || !game.win_ptr)
		return (1);
	game.counter = 0;
	//character = ft_new_sprite(game.mlx_ptr, "./textures/Grass_01.xpm");
	//game.character_pos.x = 0;
	//game.character_pos.y = 0;
	//mlx_put_image_to_window (game.mlx_ptr, game.win_ptr, character.img_ptr, 56, 56);
	game.map = parse_map(argv[1]);
	assign_textures(&game);
	render_map(game);
	// game.mlx = mlx_init();
	// if (game.mlx == NULL)
	// {
	// 	perror("Failed to initialise MiniLibX");
	// 	return (1);
	// 	//exit(EXIT_FAILURE);
	// }
	// game.win = mlx_new_window(game.mlx, 300, 300, "Hello world!");
	// if (game.win == NULL)
	// {
	//     perror("Failed to initialise MiniLibX");
	//     free (game.mlx);
	// 	return (1);
	// 	//exit(EXIT_FAILURE);
	// }
	
	/*PRUEBAS DE IMPRESIÓN DE CUADRADO VERDE Y LÍNEA DIAGONAL BLANCA
	
	img  = new_img(1920, 1080, game);
	{
		t_square	square;
		square.x = 0;
		square.y = 0;
		square.size = 300;
		square.color = 0x00FF00;
		draw_square(square, img);
		mlx_put_image_to_window (img.window.mlx_ptr, img.window.win_ptr, img.img_ptr, 0, 0);	
	}
	draw_line(game, 640, 360, 0, 0, 0xFFFFFF); */
	
	// img.win = game;
	// img.img = mlx_new_image(game.mlx, 300, 300);
	// // if (img.img == NULL)
	// //     exit(EXIT_FAILURE);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// img.width = 300;
	// img.height = 300;
	/*printf("Let's Find out what's inside our structure :D\n");
	printf("img_ptr		: [%p]\n", img.img);
	printf("bpp		: [%d]\n", img.bits_per_pixel);
	printf("line_len	: [%d]\n", img.line_length);
	printf("endian		: [%d]\n", img.endian);
	printf("addr		: [%p]\n", img.addr);
	// put_pixel_img(img, 150, 150, 0x00FFFFFF);*/
	// mlx_put_image_to_window(img.win.mlx, img.win.win, img.img, 10, 10);
	
	//free_map(game.map.map, game.map.size.y); //modifico todo el rato el mapa
	mlx_key_hook(game.win_ptr, key_hook, &game); //same as mlx_hook(game.win, ON_KEYUP, 1L << 0, key_hook, &game);
	//mlx_hook(game.win, ON_KEYUP, 1L << 0, key_hook, &game);
	mlx_hook(game.win_ptr, ON_DESTROY, 1L << 0, exit_game, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}