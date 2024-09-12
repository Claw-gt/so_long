# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/01 11:06:50 by clagarci          #+#    #+#              #
#    Updated: 2024/09/12 14:33:26 by clagarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long


LIBDIR = libft/
MLX_DIR = minilibx-linux/ 
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
MY_SOURCES = src/tutorial.c src/parse_map.c src/check_path.c src/render_map.c src/controls.c src/errors.c # src/so_long.c 

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CC = gcc
CFLAGS += -Wall -Wextra -Werror -fsanitize=address
LIB_FLAGS =  -L./libft -lft -lm
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

clean:
	rm -f $(MY_OBJECTS)
	@make clean -C minilibx-linux
	@make clean -C libft

fclean: clean
	rm -f $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re