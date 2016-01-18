# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 10:40:38 by fcapocci          #+#    #+#              #
#    Updated: 2016/01/18 13:35:09 by fcapocci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_C = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	  ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c\
	  ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar.c ft_putnbr.c\
	  ft_putstr.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c\
	  ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c\
	  ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c\
	  ft_toupper.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c\
	  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c\
	  ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c\
	  ft_itoa.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c\
	  ft_putendl_fd.c ft_strclr.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c\
	  ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strndup.c

SRC_O = $(SRC_C:.c=.o)

COMP_FLAG = gcc -Wall -Werror -Wextra

all: $(NAME)

$(NAME) : $(SRC_O)
	ar -qs $(NAME) $(SRC_O)

%.o: %.c
	$(COMP_FLAG) -c $<

clean:
	rm -rf $(SRC_O)

fclean: clean
	rm -rf $(NAME)

re: fclean all
