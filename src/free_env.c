/*
** free_env.c for  in /home/beche_f/minishell/PSU_2015_42sh/src/maxence/src
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Mon Apr 25 18:02:33 2016 beche_f
** Last update Sun Jun  5 10:57:43 2016 beche_f
*/

#include <stdlib.h>
#include "list.h"
#include "lib.h"

int		free_env(t_lenv* list)
{
  t_env		*tmp;

  if (list->head == NULL)
    {
      free(list);
      return (0);
    }
  tmp = list->head;
  list->head = list->head->next;
  if (tmp->line != NULL)
    free(tmp->line);
  free(tmp);
  tmp = NULL;
  free_env(list);
  return (0);
}
