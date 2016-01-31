# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/31 14:26:43 by fcapocci          #+#    #+#              #
#    Updated: 2016/01/31 16:58:40 by rorousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = games_2048

FILESC = main.c collision.c ft_d_array.c move.c random.c check.c fill.c init.c

FILESO = $(FILESC:.c=.o)

INCLUDES = game.h

CC = gcc -Wall -Werror -Wextra

all: compileo compile

compileo:
	@$(CC) -c $(FILESC)
	@echo "\033[1;36m[\033[0mFILES .c \033[1;32mSUCCESSFULLY\033[0m \
	COMPILED\033[1;36m]\033[0m"

compile: compileo
	@$(CC) $(FLAGS) -lncurses -o $(NAME) $(FILESO) $(LIB)
	@echo "\033[1;36m[\033[0m$(NAME) \033[1;32mSUCCESSFULLY\033[0m \
	CREATED\033[1;36m]\033[0m"

clean:
	@rm -rf $(FILESO)
	@echo "\033[1;36m[\033[0mFILES .o \033[0;31mDELETED\033[1;36m]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[1;36m[\033[0m$(NAME) \033[0;31mDELETED\033[1;36m]\033[0m"

re: fclean all
