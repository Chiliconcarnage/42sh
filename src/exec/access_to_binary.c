/*
** access_to_binary.c for  in /home/beche_f/minishell/PSU_2015_42sh/src/exec
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Thu Apr 28 16:35:10 2016 beche_f
** Last update Thu Jun  2 16:02:28 2016 beche_f
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "list.h"
#include "lib.h"

char	*is_local_bin(char *cmd)
{
  int	len;
  char	*tmp;

  if (cmd[0] == '.' && cmd[1] == '/')
    {
      len =  my_strlen(cmd) + 4;
      if ((tmp = malloc(sizeof(char) * (len + 1))) == NULL)
      	return (NULL);
      my_memset(tmp, '\0', len);
      my_strcat(tmp, "./");
      my_strcat_2(tmp, cmd);
      return (tmp);
    }
  return (NULL);
}

char	*access_to_binary(char *cmd, char **path, t_shell *s)
{
  char	*tmp;
  int	y;
  int	len;

  y = 0;
  if (cmd[0] == '/')
    return (cmd);
  if ((tmp = is_local_bin(cmd)) != NULL)
    return (tmp);
  if (s->is_path == -1)
    return (NULL);
  while (path[y] != NULL)
    {
      len = my_strlen(path[y]) + my_strlen(cmd) + 2;
      if ((tmp = malloc(sizeof(char) * (len + 1))) == NULL)
  	return (NULL);
      my_memset(tmp, '\0', len);
      my_strcat(tmp, path[y]);
      my_strcat_2(tmp, "/");
      my_strcat_2(tmp, cmd);
      if (access(tmp, F_OK | X_OK) != -1)
  	return (tmp);
      y++;
    }
  return (cmd);
}

int	exec_cmd(t_fork *f, t_shell *shell)
{
  if (f->tmp->arg == NULL || f->tmp->arg[0] == NULL)
    return (1);
  if ((f->str = access_to_binary(f->tmp->arg[0], shell->path, shell))
      == NULL)
    {
      my_putstr(f->tmp->arg[0]);
      my_putstr(": Command not found.\n");
      return (1);
    }
  else if (execve(f->str, f->tmp->arg, shell->envi) == -1)
    {
      my_putstr(f->tmp->arg[0]);
      my_putstr(": Command not found.\n");
      return (1);
    }
  if (f->str != NULL)
    free(f->str);
  return (0);
}
