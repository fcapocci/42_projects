# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/04 19:04:17 by fcapocci          #+#    #+#              #
#*   Updated: 2016/04/28 23:48:04 by fcapocci         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

OTHERS_FLAGS = -framework OpenGL -framework Appkit

SRCS = main.c parsing.c manage_mlx.c bresenham.c modif.c error.c free.c

HEADS = fdf.h

LIBS = libft/libft.a minilibx_macos/libmlx.a

OTHERS = libft minilibx_macos Makefile test_maps auteur

OBJS = $(SRCS:.c=.o)

NAME = fdf

LOGFILE = $(LOGPATH) `date +'%d/%m/%y %H:%M:%S'`

all : $(NAME)

$(NAME):
	make -C libft/ all
	make -C minilibx_macos/ all
	$(CC) -c -g $(FLAGS) $(SRCS)
	$(CC) $(FLAGS) -o $(NAME) -g $(OBJS) $(LIBS) $(OTHERS_FLAGS)

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
