/*
** show_env.c for  in /home/beche_f/minishell/PSU_2015_42sh/src/maxence/src
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Mon Apr 25 17:54:21 2016 beche_f
** Last update Sun Jun  5 11:00:25 2016 beche_f
*/

#include <stdlib.h>
#include "list.h"
#include "lib.h"

void	show_env(t_lenv *l)
{
  t_env	*tmp;

  tmp = l->tail;
  while (tmp != NULL)
    {
      if (tmp->line[0] != '\0')
	{
	  my_putstr(tmp->line);
	  my_putchar('\n');
	}
      tmp = tmp->prev;
    }
}
