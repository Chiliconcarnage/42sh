/*
** put_in_env.c for  in /home/beche_f/minishell/PSU_2015_42sh/src/maxence/src
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Mon Apr 25 17:41:46 2016 beche_f
** Last update Sun Jun  5 11:00:10 2016 beche_f
*/

#include <stdlib.h>
#include "list.h"
#include "lib.h"

int		put_in_env(t_lenv *list, char *str)
{
  t_env		*elem;
  int		len;

  len = my_strlen(str) + 1;
  if ((elem = malloc(sizeof(t_env))) == NULL)
    return (-1);
  if ((elem->line = malloc(sizeof(char) * (len + 1))) == NULL)
    return (-1);
  my_memset(elem->line, '\0', len);
  my_strcat(elem->line, str);
  if (list->head == NULL)
    {
      elem->prev = NULL;
      elem->next = NULL;
      list->head = elem;
      list->tail = elem;
    }
  else
    {
      elem->prev = NULL;
      elem->next = list->head;
      list->head->prev = elem;
      list->head = elem;
    }
  return (0);
}
