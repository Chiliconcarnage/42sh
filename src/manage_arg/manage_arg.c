/*
** manage_arg.c for manage_arg in /home/guicha_t/rendu/b2/unix/PSU_2015_42sh/src/maxence/src/manage_arg
**
** Made by guicha_t
** Login   <guicha_t@epitech.net>
**
** Started on  Fri Apr 22 17:26:44 2016 guicha_t
** Last update Sun Jun  5 11:03:27 2016 beche_f
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "lib.h"

int		manage_unsetenv(char **arg, t_lenv *lenv)
{
  t_env		*tmp;
  int		size;
  int		size_line;
  char		*str;

  tmp = lenv->tail;
  (void)size_line;
  error_unsetenv(arg);
  while (tmp != NULL)
    {
      size = my_strlen(tmp->line) + 1;
      if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
      	return (-1);
      str = my_memset(str, '\0', size);
      str = get_first(str, tmp->line);
      if (my_strcmp(str, arg[1]) == 0)
      	{
	  tmp->line[0] = '\0';
      	}
      free(str);
      tmp = tmp->prev;
    }
  return (0);
}

int	manage_setenv_add(t_lenv *lenv, char *arg1, char *arg2)
{
  char	*str;
  int	size;

  if (arg2 != NULL)
    size = my_strlen(arg1) + my_strlen(arg2) + 5;
  else
    size = my_strlen(arg1) + 5 ;
  if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
    return (-1);
  my_memset(str, '\0', size);
  my_strcat_2(str, arg1);
  my_strcat_2(str, "=");
  if (arg2 != NULL)
    my_strcat_2(str, arg2);
  put_in_env(lenv, str);
  free(str);
  return (0);
}

int	manage_setenv(t_lenv *lenv, char *arg1, char *arg2)
{
  if (arg1 == NULL)
    {
      show_env(lenv);
      return (0);
    }
  else if (manage_setenv_update(lenv, arg1, arg2) == -1)
    manage_setenv_add(lenv, arg1, arg2);
  return (0);
}

int	manage_arg(char **arg, t_lenv *lenv)
{
  if (my_strcmp(arg[0], "unsetenv") == 0)
    manage_unsetenv(arg, lenv);
  else if (my_strcmp(arg[0], "env") == 0)
    show_env(lenv);
  else if (my_strcmp(arg[0], "setenv") == 0)
    {
      manage_setenv(lenv, arg[1], arg[2]);
    }
  return (0);
}
