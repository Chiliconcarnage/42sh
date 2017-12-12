/*
** go_to_fork.c for  in /home/beche_f/PSU_2015_42sh/src/parsing
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Sun Jun  5 10:24:42 2016 beche_f
** Last update Sun Jun  5 10:43:35 2016 beche_f
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "list.h"

int	fill_my_node_str_loop(t_node *tmp, int ret, t_shell *shell)
{
  while (tmp != NULL)
    {
      if (ret == 0 && tmp->token == 2)
	return (0);
      else if (ret == 1 && tmp->token == 2)
	tmp = tmp->prev;
      else if (ret == 1 && tmp->token == 1)
	return (1);
      if (tmp->token == 1 || tmp->token == 2)
	tmp = tmp->prev;
      while (tmp->str[0] == 0)
        tmp = tmp->prev;
      if (tmp != NULL)
	{
	  ret =  my_fork(tmp->cmd, shell);
	  tmp = tmp->prev;
	}
    }
  return (ret);
}
