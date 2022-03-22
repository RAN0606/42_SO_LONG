# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rliu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 10:44:26 by rliu              #+#    #+#              #
#    Updated: 2022/03/22 19:15:12 by rliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC	= gcc

CFLAG	= -Wall -Wextra -Werror -fPIE

IFLAGS	= -I. -I./libft -I./mlx

LFLAGS	= -L./libft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit

MLX_DIR	= ./mlx

MLX		= libmlx.a

SRC		= src/read_map.c src/init_image.c

OBJ		= $(SRC:%.c=%.o)

%.o:	%.c
		$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

ifeq ($(shell uname), Linux)
$(NAME): IFLAGS         = -I./incs -I./libft/inc -I./mlx_linux/
$(NAME): LFLAGS = -L./libft -lft -L./mlx_linux -lmlx_Linux -lXext -lX11
$(NAME): MLX_DIR = ./mlx_linux
$(NAME): MLX = libmlx.a
endif

$(NAME):	$(OBJ)
			$(MAKE) -C libft
			$(MAKE) -C $(MLX_DIR)
			cp $(MLX_DIR)/$(MLX) .
			$(CC) $(CFLAGS) $(IFLAGS) $(OBJ) $(LFLAGS) -o $@

all:		$(NAME)

clean:		
			$(MAKE) -C libft clean
			rm -rf $(OBJ)

ifeq ($(shell uname), linux)
fclean:	MLX_DIR = ./mlx_linux
fclean:	MLX = libmlx.a
endif

fclean:		clean
			$(MAKE) -C libft fclean
			$(MAKE) -C $(MLX_DIR) clean
			rm -rf $(MLX)
			rm -rf $(NAME)

re:			fclean all

.PHONY: all clean fclean 
