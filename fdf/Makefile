# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/04 19:04:17 by fcapocci          #+#    #+#              #
#*   Updated: 2016/04/28 22:36:50 by fcapocci         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = main.c parcing.c manage_mlx.c error.c free.c

HEADS = fdf.h

LIBS = libft/libft.a minilibx_macos/libmlx.a

OTHERS = libft minilibx_macos test Makefile auteur

OBJS = $(SRCS:.c=.o)

NAME = fdf

LOGFILE = $(LOGPATH) `date +'%d/%m/%y %H:%M:%S'`

all : $(NAME)

$(NAME):
	make -C libft/ all
	make -C minilibx_macos/ all
	$(CC) -c -g $(FLAGS) $(SRCS)
	$(CC) $(FLAGS) -o $(NAME) -g $(OBJS) $(LIBS)

clean : $(OBJS)
	rm -rf $(OBJS)
	make -C libft/ clean
	make -C minilibx_macos/ clean

fclean : clean
	make -C libft/ fclean
	make -C minilibx_macos/ fclean
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
