/*
** get_env.c for  in /home/beche_f/minishell/PSU_2015_42sh/src/maxence/src
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Mon Apr 25 17:40:34 2016 beche_f
** Last update Fri May 27 19:42:16 2016 beche_f
*/

#include <stdlib.h>
#include "list.h"
#include "lib.h"

int	get_env(t_lenv *list, char **env)
{
  int	y;
  int	stat;

  stat = 0;
  y = 0;
  while (env[y] != NULL)
    {
      if (put_in_env(list, env[y]) == -1)
	return (-1);
      if (my_strcmp(env[y], "PATH=") == 0)
	stat = 1;
      y++;
    }
  if (stat == 0)
    manage_setenv_add(list, "PATH", "/bin");
  return (0);
}
