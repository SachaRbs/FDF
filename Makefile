# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 14:30:43 by sarobber          #+#    #+#              #
#    Updated: 2019/02/05 17:11:23 by sarobber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf


SRC_PATH = ./srcs/

OBJ_PATH = ./objs/

CPPFLAGS = -I./includes/

SRC_NAME =	main.c					\
			init.c					\
			utilities.c				\
			read.c					\
			create_image.c			\
			events.c				\
			color.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

LDFLAGS = -L./libft/

LFT = -lft

CC = gcc $(CFLAGS)

CFLAGS = -Wall -Wextra -Werror

MLX = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@make -C./libft/
	@make -C minilibx_macos/
	@echo "\033[34mCreation of $(NAME) ...\033[0m"
	@$(CC) -o $(NAME) $(SRC) minilibx_macos/libmlx.a libft/libft.a $(MLX)
	@echo "\033[32m$(NAME) created\n\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	@make clean -C ./libft/
	@echo "\033[33mRemoval of .o files of $(NAME) ...\033[0m"
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[31mFiles .o deleted\n\033[0m"

fclean: clean
	@make fclean -C ./libft/
	@echo "\033[33mRemoval of $(NAME)...\033[0m"
	@rm -f $(NAME)
	@echo "\033[31mBinary $(NAME) deleted\n\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re