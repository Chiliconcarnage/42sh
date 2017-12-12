/*
** invalid_null_cmd.c for  in /home/beche_f/PSU_2015_42sh/src/syntaxe
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Wed May 25 15:22:26 2016 beche_f
** Last update Wed May 25 15:40:44 2016 beche_f
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "lib.h"

int	begin_by_token(char *cmd)
{
  if (cmd[0] == '<' || cmd[0] == '>' || cmd[0] == '|' || cmd[0] == '&')
    {
      my_putstr("Invalid null command.\n");
      return (-1);
    }
  return (0);
}

int	end_by_token(char *cmd)
{
  int	i;

  i = my_strlen(cmd) - 1;
  if (cmd[i] == '<' || cmd[i] == '>' || cmd[i] == '|' || cmd[i] == '&')
    {
      my_putstr("Invalid null command.\n");
      return (-1);
    }
  return (0);
}

int	invalid_token(char *cmd)
{
  int	i;

  i = 0;
  while (cmd[i] != 0)
    {
      if (cmd[i] == '|' || cmd[i] == '&' || cmd[i] == '<' || cmd[i] == '>')
	{
	  if (cmd[i + 1] == '|' || cmd[i + 1] == '&' ||
	      cmd[i + 1] == '<' || cmd[i + 1] == '>')
	    return (0);
	  else if (cmd[i + 2] == '|' || cmd[i + 2] == '&' ||
		   cmd[i + 2] == '<' || cmd[i + 2] == '>')
	    {
	      my_putstr("Invalid null command.\n");
	      return (-1);
	    }
	}
      i++;
    }
  return (0);
}
