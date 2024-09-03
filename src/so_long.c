/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:51:58 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/03 13:27:13 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_pixel_img(t_image img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img.width && y < img.height)
	{
		dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

int on_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int on_keypress(int keycode, t_game *game)
{
	printf("Pressed key: %d\n", keycode);
	if (keycode == 0xff1b)
		on_destroy(game);
	return (0);
}

t_image	new_img(int width, int height, t_game window)
{
	t_image	image;

	image.win = window;
	image.img = mlx_new_image(window.mlx, width, height);
	image.addr = mlx_get_data_addr(image.img, &(image.bits_per_pixel), &(image.line_length), &(image.endian));
	image.width = width;
	image.height = height;
	return (image);
}
t_game	new_game(int width, int height, char *str)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, width, height, str);
	return (game);
}

int main(void)
{
    t_game	game;
	t_image	img;
    //t_image character;
    char    *relative_path;
    int     image_width;
    int     image_height;

    image_width = 50;
    image_height = 50;
    relative_path = "../textures/Link.xpm";
	game = new_game(640, 480, "Hello");
	if (!game.mlx || !game.win)
		return (1);
    img  = new_img(1920, 1080, game);
    //put_pixel_img(img, 500, 500, 0x00FF0000);
	// mlx_put_image_to_window(game.mlx, game.win, img.img, 0, 0);
    mlx_key_hook(game.win, on_keypress, &game);
	mlx_hook(game.win, ON_DESTROY, 1L << 0, on_destroy, &game);
	mlx_loop(game.mlx);
    return (0);
}