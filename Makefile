# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jochang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/16 01:46:29 by jochang           #+#    #+#              #
#    Updated: 2019/04/16 01:46:30 by jochang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRC = src/main.c \
	src/make_list.c \
	src/ft_select.c \
	src/free_cdll.c \
	src/signal_handler.c \
	src/input_handler.c \
	src/get_winsize.c \
	src/printer.c \

TRM = src/term_check.c \
	src/term_init.c \
	src/term_revert.c \

DIS = dis/d_delete.c \
	dis/d_exit.c \
	dis/d_move.c \
	dis/d_select.c \

INC = -I inc \
	-I libft/inc \

LIB = -L libft -lft \
	-ltermcap \

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

$(NAME):
	@make -C libft
	@echo "\033[32mmaking ft_select...\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(TRM) $(DIS) $(INC) $(LIB)

.PHONY: clean
clean:
	@make -C libft clean

.PHONY: fclean
fclean:
	@make -C libft fclean
	@echo "\033[33mremoving executable...\033[0m"
	@/bin/rm -f $(NAME)

.PHONY: re
re: fclean all
