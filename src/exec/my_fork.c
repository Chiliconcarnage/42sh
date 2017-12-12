/*
** my_fork.c for  in /home/beche_f/minishell/PSU_2015_42sh/src/exec
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Wed Apr 27 15:49:34 2016 beche_f
** Last update Sun Jun  5 10:46:04 2016 beche_f
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "list.h"
#include "lib.h"

int	cmd_statut(int pid, int ok, t_fork *f)
{
  int	stats;

  if (waitpid(pid, &stats, 0) == -1)
    return (1);
  ok = 1;
  if (stats == 139 || stats == 11)
    {
      my_putstr("Segmentation fault (Core dumped)\n");
      ok = 139;
    }
  else if (stats == 136 || stats == 8)
    {
      my_putstr("Floating point exception (core dumped)\n");
      ok = 136;
    }
  else if (stats == 256)
    {
      f->r = 1;
      ok = 1;
    }
  else if (stats == 0)
    ok = 0;
  return (ok);
}

int	check_builtin(char *str)
{
  if (my_strcmp("cd", str) == 0 || my_strcmp("cd ", str) == 0)
    return (0);
  if (my_strcmp("setenv", str) == 0 || my_strcmp("setenv ", str) == 0)
    return (1);
  if (my_strcmp("unsetenv", str) == 0 || my_strcmp("unsetenv ", str) ==  0)
    return (1);
  if (my_strcmp("env", str) == 0 || my_strcmp("env ", str) == 0)
    return (4);
  if (my_strcmp("exit", str) == 0 || my_strcmp("exit ", str) == 0)
    return (2);
  if (my_strcmp("echo", str) == 0 || my_strcmp("echo ", str) == 0)
    return (5);
  return (-1);
}

int	builtin(t_elem *cmd, t_shell *s)
{
  if (check_builtin(cmd->arg[0]) == 2 && cmd->prev == NULL)
    {
      s->exit = my_exit(cmd->arg);
      return (0);
    }
  else if (check_builtin(cmd->arg[0]) == 5 && cmd->prev == NULL)
    {
      echo(cmd->arg);
      return (0);
    }
  else if (check_builtin(cmd->arg[0]) == 1 && cmd->prev == NULL)
    {
      manage_arg(cmd->arg, s->env);
      return (0);
    }
  if (check_builtin(cmd->arg[0]) == 0 && cmd->prev == NULL)
    {
      return (manage_cd(s->env, s, cmd->arg));
    }
  return (-1);
}

int	son(t_fork *f, t_shell *shell)
{
  int	ret;

  ret = 0;
  if ((f->ret = redir_left(f->tmp)) > 0)
    dup2(f->ret, 0);
  else if (f->tmp->chevron == '<' && f->tmp->doubl == 2)
    redir_left2(f->tmp);
  else
    dup2(f->fd_in, 0);
  if (f->tmp->prev != NULL)
    dup2(f->p[1], 1);
  redir_right(f->tmp);
  close(f->p[0]);
  if (check_builtin(f->tmp->arg[0]) == 1 && f->tmp->prev != NULL)
    manage_arg(f->tmp->arg, shell->env);
  else if (check_builtin(f->tmp->arg[0]) == 0 && f->tmp->prev != NULL)
    f->tmp = f->tmp->prev;
  else if (check_builtin(f->tmp->arg[0]) == 4)
    show_env(shell->env);
  else if (check_builtin(f->tmp->arg[0]) == 5)
    echo(f->tmp->arg);
  else
    ret = exec_cmd(f, shell);
  return (ret);
}

int		my_fork(t_cmd *list, t_shell *shell)
{
  t_fork	f;
  int		ret;

  f.r = 0;
  f.tmp = list->tail;
  while (f.tmp != NULL)
    {
      if ((ret = builtin(f.tmp, shell)) != -1)
	return (ret);
      pipe(f.p);
      if ((f.pid = fork()) == -1)
      	exit(EXIT_FAILURE);
      else if (f.pid == 0)
      	{
	  ret = son(&f, shell);
	  if (ret == 0)
	    exit(EXIT_SUCCESS);
	  exit(EXIT_FAILURE);
	}
      else
	parent(&f);
    }
  if (f.r == 1)
    return (1);
  return (f.ok);
}
