/*
** config_lc.c for config_lc in /home/guicha_t/rendu/b2/unix/PSU_2015_minishell2/src/listc
**
** Made by guicha_t
** Login   <guicha_t@epitech.net>
**
** Started on  Wed Mar 30 17:18:07 2016 guicha_t
** Last update Sun Jun  5 10:56:02 2016 beche_f
*/

#include <stdlib.h>
#include "list.h"

t_lenv		*creat_lenv()
{
  t_lenv	*list;

  list = NULL;
  if ((list = malloc(sizeof(t_lenv))) == NULL)
    return (NULL);
  list->nb_line = 0;
  list->head = NULL;
  list->tail = NULL;
  return (list);
}
