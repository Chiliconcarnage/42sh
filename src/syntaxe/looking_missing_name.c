/*
** looking_missing_name.c for  in /home/beche_f/PSU_2015_42sh/src/syntaxe
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Wed May 25 15:45:32 2016 beche_f
** Last update Wed May 25 15:52:33 2016 beche_f
*/

#include <stdlib.h>
#include "list.h"
#include "lib.h"

int	triple_token(char *cmd)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (cmd[i] != 0)
    {
      while (cmd[i] == '>' || cmd[i] == '<' || cmd[i] == '|' || cmd[i] == '&')
	{
	  nb++;
	  i++;
	}
      if (nb > 2)
	{
	  my_putstr("Missing name\n");
	  return (-1);
	}
      nb = 0;
      i++;
    }
  return (0);
}
