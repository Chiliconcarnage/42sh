/*
** manage_cd.c for manage_cd in /home/guicha_t/rendu/b2/unix/PSU_2015_42sh/src/thomas
**
** Made by guicha_t
** Login   <guicha_t@epitech.net>
**
** Started on  Thu Apr 21 11:57:34 2016 guicha_t
** Last update Sun Jun  5 11:01:03 2016 beche_f
*/

#include <stdlib.h>
#include "list.h"
#include "lib.h"

int	manage_cd(t_lenv *lenv, t_shell *s, char **arg)
{
  int	ret;

  if (arg[1] == NULL)
    ret = my_cd_home(lenv, s);
  else if (my_strcmp(arg[1], "-") == 0)
    ret = my_cd_dash(lenv, s);
  else if (arg[1][0] == '~')
    ret = my_cd_tild(lenv, s, arg);
  else
    ret = my_main_cd(lenv, s, arg);
  if (ret == -1)
    {
      return (1);
    }
  return (0);
}
