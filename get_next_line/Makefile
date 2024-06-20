# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 15:31:45 by eahn              #+#    #+#              #
#    Updated: 2024/06/11 15:32:10 by eahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

SRCS = ./get_next_line.c\
		./get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(AR) $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
