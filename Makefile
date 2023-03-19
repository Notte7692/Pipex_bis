# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nassimsalhi <marvin@42.fr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 15:37:00 by nassimsalhi       #+#    #+#              #
#    Updated: 2023/03/15 15:43:04 by nassimsalhi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
FLAGS = -wall -wextra -werror
LIBFT_PATH = ./includes/libft/

LIBFT = $(LIBFT_PATH)libft.a

SRC = ./src/child.c \
	./src/error.c \
	./src/free.c \
	./src/main.c \

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJ)
	make clean -C $(LIBFT_PATH)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re : fclean all

.PHONY: all clean fclean re
