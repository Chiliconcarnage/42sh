/*
** my_cd_home.c for my_cd_home in /home/guicha_t/rendu/b2/unix/PSU_2015_42sh/src/thomas/cd
**
** Made by guicha_t
** Login   <guicha_t@epitech.net>
**
** Started on  Wed Apr 27 14:33:46 2016 guicha_t
** Last update Thu Apr 28 18:36:43 2016 guicha_t
*/

#include <stdlib.h>
#include <unistd.h>
#include "list.h"
#include "lib.h"

int	my_cd_home(t_lenv *lenv, t_shell *s)
{
  char	*home;
  char	oldpwd[500];
  char	pwd[500];

  home = my_search_line_home(lenv);
  getcwd(oldpwd, 500);
  if (home == NULL)
    {
      if (chdir(s->home) == -1)
	{
	  free(home);
	  return (-1);
	}
    }
  else if (chdir(home) == -1)
    {
      free(home);
      return (-1);
    }
  if (home != NULL)
    free(home);
  getcwd(pwd, 500);
  if (update_pwds(lenv, s, oldpwd, pwd) == -1)
    return (-1);
  return (0);
}
