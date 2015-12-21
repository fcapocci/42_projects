# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 14:11:52 by vcastro-          #+#    #+#              #
#    Updated: 2015/12/17 11:24:32 by fcapocci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
FLAGS=-Wall -Werror -Wextra
FILESC=checkentries.c checktetri.c ft_savefile.c list.c main.c order.c
FILESO=$(FILESC:.c=.o)
BINNAME = fillit

all: compileo compile

compileo:
	@$(CC) $(FLAGS) -c $(FILESC)
	@echo "\033[1;36m[\033[0mFILES .c \033[1;32mSUCCESSFULLY\033[0m \
	COMPILED\033[1;36m]\033[0m"

compile: compileo
	@$(CC) $(FLAGS) -o $(BINNAME) $(FILESO)
	@echo "\033[1;36m[\033[0m$(BINNAME) \033[1;32mSUCCESSFULLY\033[0m \
	CREATED\033[1;36m]\033[0m"

clean:
	@rm -rf $(FILESO)
	@echo "\033[1;36m[\033[0mFILES .o \033[0;31mDELETED\033[1;36m]\033[0m"

fclean: clean
	@rm -rf $(BINNAME)
	@echo "\033[1;36m[\033[0m$(BINNAME) \033[0;31mDELETED\033[1;36m]\033[0m"

re: fclean all
