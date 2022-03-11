# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rliu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 10:44:26 by rliu              #+#    #+#              #
#    Updated: 2022/03/10 15:12:36 by rliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CFLAG	= -Wall -Wextra -Werror

MFLAGS	= -Lmlx -lmlx -framework OpenGL -framework Appkit

IFLAGS	= -I. -I./mlx

MLX_DIR	= ./mlx

MLX		= libmlx.dylib

SRC		= testimage.c

OBJ		= $(SRC:%.c=%.o)

%.o:	%.c
		gcc $(CFLAGS) $(IFLAGS) -c $< -o $@

ifeq ($(shell uname), linux)
$(NAME): IFLAGS = -I./mlx_linux
$(NAME): MFLAGS = -L./mlx_linux -lmlx_linux -lXext -lX11
$(NAME): MLX_DIR = ./mlx_linux
$(NAME): MLX = 	libmlx.a
endif

$(NAME):	$(OBJ)
			$(MAKE) -C ./$(MLX_DIR)
			cp ./$(MLX_DIR)/$(MLX) .
			gcc $(CFLAGS) $(OBJ) $(IFLAGS) $(LFLAGS) $(MFLAGS) -o $@

all:		$(NAME)

clean:		
			#$(MAKE) -C libft clean
			rm -rf $(OBJ)

ifeq ($(shell uname), linux)
fclean:		MLX_DIR = ./mlx_linux
fclean:		MLX = libmlx.a
endif

fclean:		clean
			#$(MAKE) -C libft fclean
			$(MAKE) -C $(MLX_DIR) clean
			rm -rf $(MLX)
			rm -rf $(NAME)

re:			fclean all

.PHONY: all clean fclean re
