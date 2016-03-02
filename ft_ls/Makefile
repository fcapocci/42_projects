# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/04 19:04:17 by fcapocci          #+#    #+#              #
#*   Updated: 2016/03/02 15:13:11 by fcapocci         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FILESC = main.c display.c ft_ls.c modif_content.c option.c\
		 take_modes.c padding.c display2.c sort.c sort2.c\
		 recursion.c ft_ls2.c merge_sort.c merge_sort_time.c\
		 merge_sort_nano_time.c

FILESO = $(FILESC:.c=.o)

INCLUDES = ft_ls.h libft/libft.h

LIB = libft

CC = gcc -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make -C $(LIB)
	@$(CC) -c $(FILESC) -g
	@echo "\033[1;36m[\033[0mFILES/libft .c \033[1;32mSUCCESSFULLY\033[0m \
	COMPILED\033[1;36m]\033[0m"
	@$(CC) -o $(NAME) $(FILESO) -L $(LIB) libft/libft.a
	@echo "\033[1;36m[\033[0m$(NAME) \033[1;32mSUCCESSFULLY\033[0m \
	CREATED\033[1;36m]\033[0m"

libft:
	@make -C libft fclean
	@make -C libft

clean:
	@rm -rf $(FILESO)
	@make -C libft clean
	@echo "\033[1;36m[\033[0mFILES/libft .o \033[0;31mDELETED\033[1;36m]\033[0m"

fclean: clean
	@rm -rf libft/libft.a
	@rm -rf $(NAME)
	@echo "\033[1;36m[\033[0m$(NAME)/libft.a \033[0;31mDELETED\033[1;36m]\033[0m"

re: fclean all
