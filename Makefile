##
## Makefile for  in /home/beche_f/PSU_2015_minishell2
## 
## Made by beche_f
## Login   <beche_f@epitech.net>
## 
## Started on  Sun Mar 20 15:08:17 2016 beche_f
## Last update Sun Jun  5 23:04:44 2016 bourre_a
##

CC	=	gcc

RM	=	rm -rf

NAME	=	42sh

SRC	=	main.c 				\
		epure_av.c 			\
		cut_str.c			\
		config_lc.c			\
		get_env.c			\
		put_in_env.c			\
		show_env.c			\
		free_env.c			\
		my_strcmp.c			\
		manage_arg/manage_arg.c		\
		parsing/chevron_doubl.c		\
		parsing/init_final.c		\
		parsing/node.c			\
		parsing/str_2_wordtab_1.c	\
		parsing/str_2_wordtab_2.c	\
		parsing/clean_buffer.c		\
		parsing/put_my_cmd.c		\
		parsing/parsing.c		\
		parsing/list/creat_cmd.c	\
		parsing/list/creat_list.c	\
		parsing/list/show_list.c	\
		exec/my_fork.c			\
		exec/redir.c			\
		exec/access_to_binary.c		\
		puterror.c			\
		cd/manage_cd.c			\
		cd/my_cd_dash.c			\
		cd/my_cd_tild.c			\
		cd/my_main_cd.c			\
		cd/my_cd_home.c			\
		cd/basic_one.c			\
		cd/my_cd_tild_bis.c		\
		exit.c				\
		exec/cmd_error.c		\
		init.c				\
		my_free.c			\
		prep_cmd.c			\
		manage_arg/error_unsetenv.c	\
		manage_arg/setenv_update.c	\
		cd/update_pwds/update_pwds.c	\
		syntaxe/invalid_null_cmd.c	\
		syntaxe/looking_missing_name.c	\
		exec/parent.c			\
		go_to_exec.c			\
		echo.c				\
		parsing/go_to_fork.c

LIB	=	function.c		\
		get_next_line.c		\
		my_getnbr.c		\
		my_memset.c		\
		my_put_nbr.c		\
		my_strcat.c		\
		str_2_wordtab.c		\
		free_char_2d.c		\
		display_char_2d.c	\
		malloc_char_2d.c	\
		my_strcmp.c

OBJ	=	$(addprefix src/, $(SRC:.c=.o)) $(addprefix lib/my/, $(LIB:.c=.o))

INCLUDE	=	-I./include -I./lib/my/include

FLAGS   =	-W -Wall -Werror -ansi -pedantic

CFLAGS  = 	$(INCLUDE) $(FLAGS)

$(NAME)	:	$(OBJ) 
		$(CC) -o $(NAME) $(OBJ)

all	:	$(NAME)

clean	:	
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY: all clean fclean re
