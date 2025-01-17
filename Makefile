# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/01 11:06:50 by clagarci          #+#    #+#              #
#    Updated: 2024/09/21 17:36:15 by clagarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long


LIBDIR = libft/
MLX_DIR = minilibx-linux/ 
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
MY_SOURCES = src/so_long.c src/parse_map.c src/check_path.c src/render_map.c src/move_player.c \
			src/errors.c src/reduced_mlx.c src/map_utils.c src/print_on_screen.c src/on_exit.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

MY_BONUS_SOURCES = src/bonus/so_long_bonus.c src/bonus/parse_map_bonus.c src/bonus/check_path_bonus.c\
				src/bonus/render_map_bonus.c src/bonus/move_player_bonus.c src/bonus/errors_bonus.c \
				src/bonus/reduced_mlx_bonus.c src/bonus/map_utils_bonus.c src/bonus/print_on_screen_bonus.c\
				src/bonus/on_exit_bonus.c src/bonus/enemy_bonus.c

MY_BONUS_OBJECTS = $(MY_BONUS_SOURCES:.c=.o)

CC = gcc
CFLAGS += -Wall -Wextra -Werror -fsanitize=address -static-libasan
LIB_FLAGS =  -L./libft -lft
MLX_FLAGS = -Lminilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11
INCLUDES = -I/usr/include -Imlx
GREEN = \033[0;32m
RED = \033[0;31m

all: $(MLX_LIB) $(NAME)

		
%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
	
$(NAME): $(MY_OBJECTS)
		make -C $(LIBDIR)
		$(CC) $(CFLAGS) $(MY_OBJECTS) -o $(NAME) $(MLX_FLAGS) $(LIB_FLAGS)
		@echo "\n Compilation of $(NAME):  $(GREEN)SUCCESS!"

$(MLX_LIB):
		@make -C $(MLX_DIR)

bonus: $(MLX_LIB) $(MY_BONUS_OBJECTS)
		make -C $(LIBDIR)
		$(CC) $(CFLAGS) $(MY_BONUS_OBJECTS) -o $(NAME) $(MLX_FLAGS) $(LIB_FLAGS)
		@echo "\n Compilation of bonus:  $(GREEN)SUCCESS!"

clean:
	rm -f $(MY_OBJECTS) $(MY_BONUS_OBJECTS)
	@make clean -C minilibx-linux
	@make clean -C libft

fclean: clean
	rm -f $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re bonus