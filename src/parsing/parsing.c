/*
** main.c for  in /home/beche_f/PSU_2015_42sh/src
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Tue Apr 19 14:28:35 2016 beche_f
** Last update Sun Jun  5 11:04:56 2016 beche_f
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "lib.h"

int	num_token(char *str)
{
  if (my_strcmp(str, "&&") == 0)
    return (1);
  else if (my_strcmp(str, "||") == 0)
    return (2);
  return (0);
}

int		show_cmd(t_cmd *cmd)
{
  t_elem        *tmp;
  int		i;

  i = 0;
  tmp = cmd->tail;
  while (tmp != NULL)
    {
      while (tmp->arg[i] != NULL)
	{
	  printf("tmp->arg[%d] = %s\n", i , tmp->arg[i]);
	  i++;
	}
      my_putchar('\n');
      tmp = tmp->prev;
    }
  return (0);
}

int		free_my_cmd(t_cmd *cmd)
{
  t_elem	*tmp;

  if (cmd->head == NULL)
    {
      free(cmd);
      return (0);
    }
  tmp = cmd->head;
  cmd->head = cmd->head->next;
  free(tmp->word);
  free_char_2d(tmp->arg);
  free(tmp);
  tmp = NULL;
  free_my_cmd(cmd);
  return (0);
}

int		free_my_list(t_list *list)
{
  t_node	*tmp;

  if (list->head == NULL)
    {
      free(list);
      return (0);
    }
  tmp = list->head;
  list->head = list->head->next;
  if (tmp->str != NULL)
    free(tmp->str);
  if (tmp->cmd != NULL)
    free_my_cmd(tmp->cmd);
  free(tmp);
  tmp = NULL;
  free_my_list(list);
  return (0);
}
