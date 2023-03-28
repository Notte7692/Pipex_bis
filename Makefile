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
NAME_BONUS = pipex_bonus
CC = cc
FLAGS = -wall -wextra -werror
LIBFT_PATH = ./includes/libft/

LIBFT = $(LIBFT_PATH)libft.a

SRC = ./src/child.c \
	./src/error.c \
	./src/free.c \
	./src/main.c \

BONUS_SRC = ./bonus/child_bonus.c \
	./bonus/error_bonus.c \
	./bonus/free_bonus.c \
	./bonus/get_file_bonus.c \
	./bonus/heredoc_bonus.c \
	./bonus/main_bonus.c \

OBJ = $(SRC:.c=.o)


BONUSOBJ = $(BONUS_SRC:.c=.o)

$(NAME) : $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(NAME_BONUS) : $(BONUSOBJ)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(BONUSOBJ) $(LIBFT) -o $(NAME_BONUS)

bonus : $(NAME_BONUS)

all : $(NAME)

clean :
	rm -rf $(OBJ) $(BONUSOBJ)
	make clean -C $(LIBFT_PATH)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C $(LIBFT_PATH)

re : fclean all

.PHONY: all clean fclean re
