# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/04 19:04:17 by fcapocci          #+#    #+#              #
#    Updated: 2016/02/04 19:06:27 by fcapocci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FILESC = main_test.c display.c ft_ls.c modif_content.c option.c\
		 take_modes.c padding.c

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
