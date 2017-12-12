/*
** show_list.c for  in /home/beche_f/PSU_2015_42sh/src/fran/src/list
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Tue Apr 19 21:17:56 2016 beche_f
** Last update Sun Jun  5 11:05:50 2016 beche_f
*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "lib.h"

void		my_show_cmd(t_cmd *c)
{
  t_elem	*tmp;

  tmp = c->tail;
  while (tmp != NULL)
    {
      if (tmp->arg != NULL)
	display_char_2d(tmp->arg);
      my_putchar('\n');
      tmp = tmp->prev;
    }
}

void		my_show_list(t_list *l)
{
  t_node	*tmp;

  tmp = l->tail;
  while (tmp != NULL)
    {
      tmp = tmp->prev;
    }
}
