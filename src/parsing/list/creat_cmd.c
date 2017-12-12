/*
** creat_cmd.c for  in /home/beche_f/PSU_2015_42sh/src/fran/src/list
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Tue Apr 19 21:45:44 2016 beche_f
** Last update Tue Apr 19 21:48:37 2016 beche_f
*/

#include <stdlib.h>
#include "list.h"
#include "lib.h"

t_cmd	*creat_cmd()
{
  t_cmd	*cmd;

  if ((cmd = malloc(sizeof(t_cmd))) == NULL)
    return (NULL);
  cmd->head = NULL;
  cmd->tail = NULL;
  cmd->nb_cmd = 0;
  return (cmd);
}
