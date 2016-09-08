#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: fpasquer <fcapocci@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/05/17 16:07:18 by fcapocci          #+#    #+#             *#
#*   Updated: 2016/08/27 15:57:04 by fcapocci         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME			= ft_select

SRC_NAME		= main.c ft_select.c init_lst.c free.c print_argv.c util.c event_key.c move.c print_selected.c print_argv2.c catch_signal.c

INCLUDES		=ft_select.h

LIBRARY			= libft/libft.a

OTHERS			= libft Makefile auteur

OTHER_FLAGS 	= -lncurses 

GCC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g
OBJ_NAME		= $(SRC_NAME:.c=.o)

SRCDIR			= srcs
OBJDIR			= objs
INCDIR			= incs

SRC				= $(addprefix $(SRCDIR)/, $(SRC_NAME))
OBJ				= $(addprefix $(OBJDIR)/, $(OBJ_NAME))
INC				= $(addprefix $(INCDIR)/, $(INCLUDES))
DATE			= `date +'%d/%m/%y %H:%M:%S'`

All : $(NAME)

$(NAME) : $(OBJDIR) $(OBJ) $(LIBRARY)
	$(GCC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBRARY) $(OTHER_FLAGS)
	@echo "\033[0;32m"$(NAME) "DONE\033[0m"

$(LIBRARY) :
	make -C libft

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INC)
	$(GCC) -I $(INCDIR)/ $(CFLAGS) -o $@ -c $<

$(OBJDIR) :
	mkdir -p $(OBJDIR)

clean :
	rm -rf $(OBJ)
	rm -rf $(OBJDIR)
	make -C libft clean

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME).dSYM
	rm -rf $(OBJDIR)
	make -C libft fclean

push : fclean
	git add $(SRCDIR) $(INCDIR) $(OTHERS) ./libft
	git commit -m "$(DATE)"
	git push

re : fclean All

norm:
	norminette $(SRC) $(INC)
