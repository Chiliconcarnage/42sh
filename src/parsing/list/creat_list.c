/*
** creat_list.c for  in /home/beche_f/PSU_2015_42sh/src/fran/src/list
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Tue Apr 19 16:33:23 2016 beche_f
** Last update Sun Jun  5 11:06:11 2016 beche_f
*/

#include <stdlib.h>
#include "list.h"
#include "lib.h"

t_list		*creat_list()
{
  t_list	*list;

  list = NULL;
  if ((list = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  list->nb_node = 0;
  list->head = NULL;
  list->tail = NULL;
  return (list);
}
