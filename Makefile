# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/01 11:06:50 by clagarci          #+#    #+#              #
#    Updated: 2024/09/03 16:40:42 by clagarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# LIBS =  #-lft  #-lXext -lX11 -lm
MLX_DIR = minilibx-linux/ #libft/ 
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
MY_SOURCES = src/tutorial.c # src/so_long.c 

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CC = gcc
CFLAGS += -Wall -Wextra -Werror -fsanitize=address
MLX_FLAGS = -Lminilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11 -lm #math.h #-L./libft 
INCLUDES = -I/usr/include -Imlx
GREEN = \033[0;32m
RED = \033[0;31m

all: $(MLX_LIB) $(NAME)

		
%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
	
$(NAME): $(MY_OBJECTS)
#		make -C $(LIBDIR)
		$(CC) $(CFLAGS) $(MY_OBJECTS) -o $(NAME) $(MLX_FLAGS)
		@echo "\n Compilation of $(NAME):  $(GREEN)SUCCESS!"

$(MLX_LIB):
		@make -C $(MLX_DIR)

clean:
	rm -f $(MY_OBJECTS)
	@make clean -C minilibx-linux
#	@make clean -C libft

fclean: clean
	rm -f $(NAME)
#	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re