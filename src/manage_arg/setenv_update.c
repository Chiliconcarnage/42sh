/*
** setenv_update.c for  in /home/beche_f/PSU_2015_42sh/src/manage_arg
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Fri May 20 19:40:52 2016 beche_f
** Last update Fri May 20 19:48:56 2016 beche_f
*/

#include <stdlib.h>
#include "list.h"
#include "lib.h"

int	if_finded(char *arg1, char *arg2, t_env *tmp, int size)
{
  free(tmp->line);
  if (arg2 != NULL)
    size = my_strlen(arg1) + my_strlen(arg2) + 5;
  else
    size = my_strlen(arg1) + 5 ;
  if ((tmp->line = malloc(sizeof(char) * (size + 1))) == NULL)
    return (-1);
  tmp->line = my_memset(tmp->line, '\0', size);
  my_strcat_2(tmp->line, arg1);
  my_strcat_2(tmp->line, "=");
  if (arg2 != NULL)
    my_strcat_2(tmp->line, arg2);
  return (0);
}

int		manage_setenv_update(t_lenv *lenv, char *arg1, char *arg2)
{
  t_env         *tmp;
  int           size;
  char          *str;

  (void)lenv;
  tmp = lenv->tail;
  while (tmp != NULL)
    {
      size = my_strlen(tmp->line) + 1;
      if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
	return (-1);
      str = my_memset(str, '\0', size);
      str = get_first(str, tmp->line);
      if (my_strcmp(str, arg1) == 0)
	{
	  if_finded(arg1, arg2, tmp, size);
	  free(str);
	  return (0);
	}
      free(str);
      tmp = tmp->prev;
    }
  return (-1);
}
