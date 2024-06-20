# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 23:10:40 by eahn              #+#    #+#              #
#    Updated: 2024/06/11 16:45:18 by eahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework AppKit

NAME = so_long

FT_PRINTF_LIBDIR = ./ft_printf
GNL_LIBDIR = ./get_next_line
MLX_LIBDIR = ./mlx
LIBFLAG = -lmlx -lftprintf -lgnl -L$(FT_PRINTF_LIBDIR) -L$(MLX_LIBDIR) -L$(GNL_LIBDIR)

SRC_DIR = ./srcs/

SRCS = exit_error.c\
		image.c\
		map.c\
		move.c\
		path.c\
		so_long.c\
		utils.c

NEW_SRCS = $(addprefix $(SRC_DIR), $(SRCS))

OBJS = $(NEW_SRCS:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJS)
		@make -C ./ft_printf
		@make -C ./mlx
		@make -C ./get_next_line
		@$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFLAG) $(OBJS) -o $(NAME)

clean:
		@make -C ./ft_printf clean
		@make -C ./mlx clean
		@make -C ./get_next_line clean
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)
		@make -C ./ft_printf fclean
		@make -C ./get_next_line fclean

re			:	fclean all

.PHONY		:	all clean fclean re
