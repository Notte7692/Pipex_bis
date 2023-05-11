# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 15:37:00 by nassimsalhi       #+#    #+#              #
#    Updated: 2023/05/11 14:39:37 by nsalhi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
LIBFT_PATH = ./includes/libft/

LIBFT = $(LIBFT_PATH)libft.a

SRC = ./src/pipex.c \
	./src/error_child.c \
	./src/pipex_utils.c \
	./src/child.c \
	./src/here_doc.c \
	./src/free.c \
	./src/check_args.c \

BONUS_SRC = ./bonus/pipex_bonus.c \
			./bonus/error_child_bonus.c \
			./bonus/pipex_bonus_utils.c \
			./bonus/child_bonus.c \
			./bonus/here_doc_bonus.c \
			./bonus/free_bonus.c \
			./bonus/check_args_bonus.c \

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
