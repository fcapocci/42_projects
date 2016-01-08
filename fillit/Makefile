# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 14:11:52 by vcastro-          #+#    #+#              #
#    Updated: 2016/01/08 16:13:49 by vcastro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FILESC = checkentries.c checktetri.c ft_savefile.c list.c main.c order.c\
		 rename.c resolv.c piece_man.c sizes.c map.c

FILESO = $(FILESC:.c=.o)

INCLUDES = fillit.h libft/libft.h

LIB = libft/libft.a

CC = gcc -Wall -Werror -Wextra

all: compileo compile

compileo:
	@$(CC) -c $(FILESC)
	@echo "\033[1;36m[\033[0mFILES .c \033[1;32mSUCCESSFULLY\033[0m \
	COMPILED\033[1;36m]\033[0m"

compile: compileo
	@$(CC) $(FLAGS) -o $(NAME) $(FILESO) $(LIB)
	@echo "\033[1;36m[\033[0m$(NAME) \033[1;32mSUCCESSFULLY\033[0m \
	CREATED\033[1;36m]\033[0m"

clean:
	@rm -rf $(FILESO)
	@echo "\033[1;36m[\033[0mFILES .o \033[0;31mDELETED\033[1;36m]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[1;36m[\033[0m$(NAME) \033[0;31mDELETED\033[1;36m]\033[0m"

re: fclean all
