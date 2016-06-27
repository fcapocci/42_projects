#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/05/17 16:07:18 by fpasquer          #+#    #+#             *#
#*   Updated: 2016/06/24 21:41:14 by fpasquer         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME			= 42sh

SRC_NAME		= main.c sh.c save_hash_bin.c hash_tab.c del_hash_bin.c			\
				save_sort_bin.c sort_list.c sort_fonctions.c autocompletion.c	\
				loop_shell.c builtin.c env.c env1.c builtin_echo.c multy_line.c	\
				builtin_setenv.c term.c exe_bin.c argv.c catch_signal.c key.c	\
				key_event1.c

INCLUDES		= _42sh.h key.h

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
	$(GCC) -I $(INCDIR)/ $(CFLAG) -o $@ -c $<

$(OBJDIR) :
	mkdir -p $(OBJDIR)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME).dSYM
	rm -rf $(OBJDIR)
	make -C libft fclear

re : fclean All

push : fclean
	git add $(SRCDIR) $(INCDIR) $(OTHERS) ./libft
	git commit -m "$(DATE)"
#	echo "Enter Your Commit : "
#	read root_path ; git commit -m "$$root_path"
	git push

norm:
	norminette $(SRC) $(INC)

#GCC = gcc
#NAME = 42sh

#CFLAGS			= -Wall -Wextra -Werror -g
#OBJ_NAME		= $(SRC_NAME:.c=.o)
#SRC_NAME		=	main.c sh.c save_hash_bin.c hash_tab.c del_hash_bin.c\

#OTHERS			= libft Makefile auteur

#NCURSE_FLAGS 	=
#SRCDIR			= srcs
#OBJDIR			= objs
#INCDIR1			= -I incs/
#INCDIR			= incs/
#INCLUDES		= incs/_42sh.h

#LIBRARY			= libft/libft.a

#SRC				= $(addprefix $(SRCDIR)/, $(SRC_NAME))
#OBJ				= $(addprefix $(OBJDIR)/, $(OBJ_NAME))
#DATE			= `date +'%d/%m/%y %H:%M:%S'`

#All : $(NAME)

#$(NAME) : $(OBJ) $(LIBRARY)
#	$(GCC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBRARY) $(NCURSE_FLAGS)
#	@echo "\033[0;32m"$(NAME) "DONE\033[0m"

#$(LIBRARY) :
#	make -C libft

#$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCLUDES) 
#	$(GCC) $(INCDIR1) $(CFLAG) -o $@ -c $<

#clean :
#	rm -rf $(OBJ)

#fclean : clean
#	rm -rf $(NAME)
#	rm -rf $(NAME).dSYM
#	make -C libft fclear

#re : fclean All

#push : fclean
#	git add $(SRCDIR) $(INCDIR) $(OTHERS) ./libft
#	git commit -m "$(DATE)"
#	echo "Enter Your Commit : "
#	read root_path ; git commit -m "$$root_path"
#	git push




















# NAME 		= corewar
# FLAGS		= -Wall -Werror -Wextra -g
# SRC 		= main.c util.c init_vm.c virtual_machin.c print_info.c save_player.c

# OTHERS		= libft Makefile auteur minilibx_macos exemple


# OBJ			= $(SRC:.c=.o)
# INC			= incs/virtual_machine.h
# LIBFLAGS	= -L./libft/ -lft -lncurses
# SRCDIR		= ./srcs/
# OBJDIR		= ./objs/
# INCDIRLIB	= ./libft/incs/
# INCDIR		= ./incs/
# SRCS		= $(addprefix $(SRCDIR), $(SRC))
# OBJS		= $(addprefix $(OBJDIR), $(OBJ))
# DATE		= `date +'%d/%m/%y %H:%M:%S'`
# # .SILENT:


# all : $(NAME)

# $(NAME) : $(OBJ) $(LIBFLAGS)

# $(LIBFLAGS) :
# 	Make -C libft

# $(OBJDIR)/%.o : $(SRCDIR)/%.c $(INC)
# 	$(GCC) $(INCDIR) $(CFLAG) -o $@ -c $<


# all : 		$(NAME)

# $(NAME) :
# 	echo "\\033[1;31mCompilation with -Wall -Wextra -Werror...\\033[0;39m"
# 	echo "\\033[1;34mGenerating objects... Please wait.\\033[0;39m"
# 	Make -C libft/
# 	gcc $(FLAGS) -c $(SRCS) -I $(INCDIR) -I $(INCDIRLIB)
# 	echo "compiling $(NAME)..."
# 	mkdir -p $(OBJDIR)
# 	mv $(OBJ) $(OBJDIR)
# #	gcc $(FLAGS) -o $(NAME) -I /usr/X11/include -g -L/usr/X11/lib -lX11 -lmlx -lXext -framework OpenGL -framework AppKit $(OBJS) $(LIBFLAGS)
# 	gcc $(FLAGS) -o $(NAME) $(OBJS) $(LIBFLAGS)
# 	echo "$(NAME) has been created !"

# .PHONY:		clean fclean re push exe

# clean :
# 			Make -C ./libft/ clear
# 			rm -rf $(OBJS)
# 			rm -rf $(OBJDIR)
# 			echo "objects files has been removed !"

# fclean :	clean
# 			Make -C ./libft/ fclear
# 			rm -rf $(NAME)
# 			echo "$(NAME) has been removed !"

# re		:	fclean all

# exe		:	re
# 	./$(NAME) 

# push	:	fclean
# 			git add $(SRCDIR) $(INCDIR) $(OTHERS) ./libft
# 			git commit -m "$(DATE)"
# #			echo "Enter Your Commit : "
# #			read root_path ; git commit -m "$$root_path"
# 			git push
