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

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = main.c display.c ft_ls.c modif_content.c option.c\
		 take_modes.c padding.c display2.c sort.c sort2.c\
		 recursion.c ft_ls2.c merge_sort.c merge_sort_time.c\
		 merge_sort_nano_time.c free.c

HEADS = ft_ls.h

LIBS = libft/libft.a

OTHERS = libft Makefile auteur

OBJS = $(SRCS:.c=.o)

NAME = ft_ls

LOGFILE = $(LOGPATH) `date +'%d/%m/%y %H:%M:%S'`

all : $(NAME)

$(NAME):
	make -C libft/ all
	$(CC) -c -g $(FLAGS) $(SRCS)
	$(CC) $(FLAGS) -o $(NAME) -g $(OBJS) $(LIBS)

clean : $(OBJS)
	rm -rf $(OBJS)

fclean : clean
	make -C libft/ fclean
	rm -rf $(NAME)
	rm -rf $(NAME).dSYM

push : fclean
	git add $(SRCS) $(HEADS) $(OTHERS)
	git commit -m "$(LOGFILE)"
	git push

re : fclean all

exe : re
	./$(NAME)

.PHONY: all clean fclean re exe push
