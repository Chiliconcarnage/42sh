/*
** list.h for  in /home/beche_f/minishell/PSU_2015_42sh/include
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Wed Apr 27 15:19:26 2016 beche_f
** Last update Sun Jun  5 10:28:59 2016 beche_f
*/

#ifndef	LIST_H_
# define LIST_H_

#include <sys/types.h>

typedef struct	s_elem
{
  struct s_elem	*next;
  struct s_elem	*prev;
  char		**arg;
  char		*word;
  char		chevron;
  int		doubl;
}		t_elem;

typedef struct	s_cmd
{
  t_elem	*head;
  t_elem	*tail;
  int		nb_cmd;
}		t_cmd;

typedef struct	s_node
{
  struct s_node	*next;
  struct s_node	*prev;
  int		token;
  char		*str;
  t_cmd		*cmd;
}		t_node;

typedef struct	s_list
{
  t_node	*head;
  t_node	*tail;
  int		nb_node;
}		t_list;


typedef struct	s_env
{
  struct s_env	*next;
  struct s_env	*prev;
  char		*line;
}		t_env;

typedef struct  s_lenv
{
  t_env        *head;
  t_env        *tail;
  int           nb_line;
}               t_lenv;

typedef	struct	s_shell
{
  char		**envi;
  char		*buffer;
  char		*buffer_clean;
  char		**cmd;
  int		i;
  int		j;
  int		position_tmp;
  t_list	*list;
  char		*home;
  char		**path;
  char		*pwd;
  char		*oldpwd;
  int		exit;
  t_lenv	*env;
  int		is_path;
}		t_shell;

typedef struct  s_final
{
  int		doubl;
  char		chevron;
  char		*word;
  char		**arg;
}		t_final;

typedef struct	s_fork
{
  char		*str;
  int		p[2];
  pid_t		pid;
  int		fd_in;
  t_elem	*tmp;
  int		ret;
  int		ok;
  int		r;
}		t_fork;

/**SYNTAXE**/
int	begin_by_token(char*);
int	end_by_token(char*);
int	invalid_token(char*);
int	triple_token(char*);
/***********/

/**PARSING*/
int	put_in_list(t_list*, char*, char**, char**, char**, char**);
void	my_show_list(t_list*);
int	put_in_cmd(t_cmd*, char, int, char**);
t_cmd	*creat_cmd();
t_list	*creat_list();
int	my_fork(t_cmd*,  t_shell*);
int	exec_cmd(t_fork*, t_shell*);
int	init(t_shell*, char**);
void	free_for_cmd(t_shell*);
void	free_for_prog(t_shell*);
int	prep_cmd(t_shell*);
int     fill_my_node_str(t_shell*);
int     put_my_cmd(t_cmd*, t_final*, char*);
int     num_token(char*);
int     init_final(t_final*, char*);
int     fill_chevron_doubl(t_cmd*, char*, t_final*);
int     show_cmd(t_cmd*);
char    **str_2_wordtab_1(char**, char*);
char    **str_2_wordtab_2(char**, char*);
int	free_my_list(t_list*);
int	free_my_cmd(t_cmd*);
int	show_cmd(t_cmd*);
int	num_token(char*);
int     clean_my_buffer(t_shell*);
int	boucle(char*, t_cmd*, t_final*);
int	fill_my_node_str_loop(t_node*, int, t_shell*);
/****/

/*ENV*/
int	manage_unsetenv(char**, t_lenv*);
int	manage_setenv_add(t_lenv*, char*, char*);
int	error_unsetenv(char**);
int	save_home(char**, t_shell*);
int	cut_home(t_shell*, int, char**);
int     manage_arg(char **, t_lenv*);
char	*get_first(char*, char*);
int	cut_path_until_equals(char *, t_shell*);
int	get_path(t_lenv*, t_shell*);
void	free_my_arg(t_shell*);
int	put_in_env(t_lenv*, char*);
int	get_env(t_lenv*, char**);
t_lenv	*creat_lenv();
void	show_env(t_lenv*);
int	free_env(t_lenv*);
char	*cut_path(char*, char*);
char	*epure_av(char*);
int	my_strcmp2(char*, char*);
int	manage_setenv(t_lenv*, char*, char*);
int	manage_setenv_update(t_lenv*, char*, char*);
/****/

/*EXEC CMD*/
int	redir_right(t_elem*);
int	redir_left(t_elem*);
int	redir_left2(t_elem*);
int	puterror(char*, char*);
char	*access_to_binary(char*, char**, t_shell*);
int	my_exit(char**);
int	put_cmd_error(char*);
int	parent(t_fork*);
int	cmd_statut(int, int, t_fork*);
int	check_builtin(char*);
int	go_to_exec(t_shell*, int);
/****/

/*CD*/
char	*reduce_string(char*, int);
int     manage_cd(t_lenv*, t_shell*, char**);
int     my_main_cd(t_lenv*, t_shell*, char**);
int     my_cd_dash(t_lenv*, t_shell*);
int     my_cd_tild(t_lenv*, t_shell*, char**);
int     my_cd_home(t_lenv*, t_shell*);
char    *my_search_line_home(t_lenv*);
int     search_first_char_home(char*);
int	update_pwds(t_lenv*, t_shell*, char*, char*);
/****/

/**ECHO**/
int	echo(char**);
/****/
#endif /* !LIST_H_ */
