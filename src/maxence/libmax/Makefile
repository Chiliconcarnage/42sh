##
## Makefile for Makefile in /home/oem/home/SBMLparser
## 
## Made by maxence.lauque
## Login   <lauque_m@epitech.net>
## 
## Started on  Mon Jun 13 10:21:35 2016 maxence.lauque
## Last update Mon Jun 13 19:08:05 2016 maxence.lauque
##

CC	=	cc


NAME	=	SBMLparser

RM	=	rm -rf

SRC	=	src/main.c

LIB	=	lib/my/get_next_line.c		\
		lib/my/malloc_char_2d.c		\
		lib/my/my_strcmp.c		\
		lib/my/str_2_wordtab.c		\
		lib/my/function.c		\
		lib/my/display_char_2d.c	\
		lib/my/free_char_2d.c		\
		lib/my/my_memset.c		\
		lib/my/my_getnbr.c		\
		lib/my/my_put_nbr.c		\
		lib/my/my_strcat.c		

OBJ	=	$(SRC:.c=.o) $(LIB:.c=.o)

INCLUDE	=	-I./include -I./lib/my/include

FLAGS	=	-W -Wall -Wextra -Werror -ansi -pedantic

CFLAGS	=	$(INCLUDE) $(FLAGS)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all	:	$(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)
		$(RM) bin

re	:	fclean all

.PHONY	:	all clean fclean all
