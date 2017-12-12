/*
** exit.c for  in /home/beche_f/PSU_2015_42sh/src
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Fri May 20 15:39:28 2016 beche_f
** Last update Fri May 20 15:39:29 2016 beche_f
*/


#include <stdio.h>
#include "list.h"
#include "lib.h"

int	loop_exit(char **tab, int i, int res)
{
  while (tab[1][i] != 0)
    {
      if (tab[1][i] >= '0' && tab[1][i] <= '9')
	{
	  res = my_getnbr(tab[1]);
	  return (res);
	}
      else
	{
	  my_puterror("EXIT : Syntaxe error \n");
	  return (0);
	}
      i++;
    }
  if (i == 1)
    {
      res = my_getnbr(tab[1]);
      return (res);
    }
  return (0);
}

int	my_exit(char **tab)
{
  int	i;
  int	res;

  i = 1;
  res = 0;
  if (tab[1] != NULL)
    {
      if ((tab[1][0] >= '0' && tab[1][0] <= '9') || tab[1][0] == '-')
	{
	  res = loop_exit(tab, i, res);
	  return (res);
	}
      else
	{
	  my_puterror("EXIT : Syntaxe error \n");
	  return (0);
	}
    }
  else
    return (-1);
  return (0);
}
