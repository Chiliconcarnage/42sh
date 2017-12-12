/*
** puterror.c for  in /home/beche_f/minishell/PSU_2015_minishell2/src
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Sat Apr  9 14:47:22 2016 beche_f
** Last update Sun Apr 10 09:41:49 2016 beche_f
*/

#include "lib.h"

int	puterror(char *s1, char *s2)
{
  if (my_putstr(s1) == -1)
    return (0);
  if (my_putstr(s2) == -1)
    return (0);
  return (0);
}
