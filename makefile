# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rliu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 10:44:26 by rliu              #+#    #+#              #
#    Updated: 2022/03/24 13:10:51 by rliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

NAME_B	= so_long_bonus

CC	= gcc

CFLAG	= -Wall -Wextra -Werror -fPIE

IFLAGS	= -I./incs -I./libft -I./mlx

LFLAGS	= -L./libft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit


MLX_DIR	= ./mlx

MLX		= libmlx.dylib

SRC		= srcs/check_map.c srcs/check_map_utile.c\
	       	srcs/mov.c srcs/image.c \
		srcs/so_long.c

SRC_B		= srcs_bonus/check_map_bonus.c srcs_bonus/check_map_utile_bonus.c\
	       	srcs_bonus/mov_bonus.c srcs_bonus/image_bonus.c \
		srcs_bonus/so_long_bonus.c	

OBJ		= $(SRC:%.c=%.o)

OBJ_B		= $(SRC_B:%.c=%.o)

%.o:	%.c
		$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

ifeq ($(shell uname), Linux)
$(NAME): IFLAGS         = -I./incs -I./libft/inc -I./mlx_linux/
$(NAME): LFLAGS = -L./libft -lft -L./mlx_linux -lmlx_Linux -lXext -lX11
$(NAME): MLX_DIR = ./mlx_linux
$(NAME): MLX = libmlx.a

bonus: IFLAGS         = -I./incs -I./libft/inc -I./mlx_linux/
bonus: LFLAGS = -L./libft -lft -L./mlx_linux -lmlx_Linux -lXext -lX11
bonus: MLX_DIR = ./mlx_linux
bonus: MLX = libmlx.a
endif

$(NAME):	$(OBJ)
			$(MAKE) -C libft
			$(MAKE) -C $(MLX_DIR)
			cp $(MLX_DIR)/$(MLX) .
			$(CC) $(CFLAGS) $(IFLAGS) $(OBJ) $(LFLAGS) -o $@

bonus: 	$(OBJ_B)
			$(MAKE) -C libft
			$(MAKE) -C $(MLX_DIR)
			cp $(MLX_DIR)/$(MLX) .
			$(CC) $(CFLAGS) $(IFLAGS) $(OBJ_B) $(LFLAGS) -o $(NAME_B)

all:		$(NAME)

clean:		
			$(MAKE) -C libft clean
			rm -rf $(OBJ)
			rm -rf $(OBJ_B)

ifeq ($(shell uname), linux)
fclean:		MLX_DIR = ./mlx_linux
fclean:		MLX = libmlx.a
endif

fclean:		clean
			$(MAKE) -C libft fclean
			$(MAKE) -C $(MLX_DIR) clean
			rm -rf $(MLX)
			rm -rf $(NAME)
			rm -rf $(NAME_B)
			rm -rf libmlx.a

re:			fclean all

.PHONY: all clean fclean 
