/*
** node.c for node in /home/bourre_a/Semestre_2/Programmation_Shell/PSU_2015_42sh/src/quentin/src
**
** Made by bourre_a
** Login   <bourre_a@epitech.net>
**
** Started on  Fri Apr 22 11:17:45 2016 bourre_a
** Last update Thu Jun  9 11:33:55 2016 bourre_a
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "lib.h"

int	fill_node(t_node *node, char *str, int size)
{
  if ((node->str = malloc(sizeof(char) * (size + 1))) == NULL)
    return (-1);
  node->str = my_memset(node->str, '\0', size);
  node->str = my_strcat_2(node->str, str);
  node->token = num_token(str);
  node->cmd = creat_cmd();
  return (0);
}

int		put_in_node_str(t_list *list, char *str, int size)
{
  t_node        *node;
  t_final       final;

  if ((node = malloc(sizeof(t_node))) == NULL)
    return (-1);
  fill_node(node, str, size);
  boucle(str, node->cmd, &final);
  if (list->head == NULL)
    {
      node->next = NULL;
      node->prev = NULL;
      list->head = node;
      list->tail = node;
    }
  else
    {
      node->next = list->head;
      node->prev = NULL;
      list->head->prev = node;
      list->head = node;
    }
  list->nb_node++;
  return (0);
}

int		fill_node_str(t_shell *shell, char *buffer)
{
  int           size;

  size = my_strlen(buffer);
  if ((put_in_node_str(shell->list, buffer, size)) == -1)
    return (-1);
  return (0);
}

int	fill_tmp(t_shell *shell, int i)
{
  char  **tmp;
  int   j;

  j = 0;
  tmp = NULL;
  tmp = str_2_wordtab_1(tmp, shell->cmd[i]);
  while (tmp[j] != NULL)
    {
      fill_node_str(shell, tmp[j]);
      j++;
    }
  j = 0;
  while (tmp[j] != NULL)
    {
      free(tmp[j]);
      j++;
    }
  free(tmp);
  return (0);
}

int		fill_my_node_str(t_shell *shell)
{
  int		i;
  t_node	*tmp;
  int		ret;

  i = 0;
  ret = 0;
  shell->list = creat_list();
  shell->position_tmp = 0;
  while (shell->cmd[i] != NULL)
    fill_tmp(shell, i++);
  tmp =  shell->list->tail;
  ret = fill_my_node_str_loop(tmp, ret, shell);
  free_my_list(shell->list);
  return (ret);
}
