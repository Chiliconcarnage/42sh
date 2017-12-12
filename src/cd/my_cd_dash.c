/*
** my_cd_dash.c for my_cd_dash in /home/guicha_t/rendu/b2/unix/PSU_2015_42sh/src/thomas/cd
**
** Made by guicha_t
** Login   <guicha_t@epitech.net>
**
** Started on  Mon Apr 25 18:52:06 2016 guicha_t
** Last update Sun Jun  5 11:01:27 2016 beche_f
*/

#include "list.h"
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

int	check_line_oldpwd(char *str)
{
  if (str[0] == 'O')
    if (str[1] == 'L')
      if (str[2] == 'D')
	if (str[3] == 'P')
	  if (str[4] == 'W')
	    if (str[5] == 'D')
	      return (0);
  return (-1);
}

char		*search_oldpwd_in_listenv(t_lenv *lenv)
{
  t_env		*elem;
  char		*tmp;

  elem = lenv->head;
  while (elem != NULL)
    {
      if (check_line_oldpwd(elem->line) == 0)
	{
	  tmp = reduce_string(elem->line, 7);
	  return (tmp);
	}
      elem = elem->next;
    }
  return (NULL);
}

int	write_not_set(char *path)
{
  my_puterror("OLDPWD is not set.\n");
  free(path);
  return (-1);
}

int	my_cd_dash(t_lenv *lenv, t_shell *s)
{
  char	*path;
  char	oldpwd[500];
  char	pwd[500];

  getcwd(oldpwd, 500);
  path = search_oldpwd_in_listenv(lenv);
  if (path == NULL)
    {
      if (chdir(s->oldpwd) == -1)
	{
	  write_not_set(path);
	  return (-1);
	}
    }
  else if (chdir(path) == -1)
    {
      write_not_set(path);
      return (-1);
    }
  getcwd(pwd, 500);
  free(path);
  if (update_pwds(lenv, s, oldpwd, pwd) == -1)
    return (-1);
  return (0);
}
