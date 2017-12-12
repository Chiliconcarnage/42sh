/*
** put_my_cmd.c for put_my_cmd in /home/bourre_a/Semestre_2/Programmation_Shell/PSU_2015_42sh/src/quentin/src
**
** Made by bourre_a
** Login   <bourre_a@epitech.net>
**
** Started on  Fri Apr 22 11:14:23 2016 bourre_a
** Last update Thu May 26 15:06:15 2016 beche_f
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "lib.h"

int	clean_arg_word(char **arg)
{
  int	y;

  y = 0;
  while (arg[y] != NULL)
    y++;
  y--;
  while (arg[y][0] == 0 && y > 0)
    y--;
  if (arg[y] != NULL)
    free(arg[y]);
  arg[y] = NULL;
  return (0);
}

int	fill_elem(t_elem *elem, t_final *final, char *str)
{
  int	i;
  int	size;

  i = 0;
  elem->chevron = final->chevron;
  elem->doubl = final->doubl;
  size = my_strlen(final->word);
  if ((elem->word = malloc(sizeof(char) * (size + 1))) == NULL)
    return (-1);
  elem->word = my_memset(elem->word, '\0', size);
  while (final->word[i] != '\0')
    {
      elem->word[i] = final->word[i];
      i++;
    }
  elem->arg = str_2_wordtab_2(elem->arg, str);
  if (elem->doubl != 0)
    clean_arg_word(elem->arg);
  return (0);
}

int		put_my_cmd(t_cmd *list, t_final *final, char *str)
{
  t_elem        *elem;

  if ((elem = malloc(sizeof(t_node))) == NULL)
    return (-1);
  fill_elem(elem, final, str);
  if (list->head == NULL)
    {
      elem->next = NULL;
      elem->prev = NULL;
      list->head = elem;
      list->tail = elem;
    }
  else
    {
      elem->next = list->head;
      elem->prev = NULL;
      list->head->prev = elem;
      list->head = elem;
    }
  list->nb_cmd++;
  return (0);
}
