/*
** parent.c for  in /home/beche_f/PSU_2015_42sh/src/exec
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Thu Jun  2 16:03:36 2016 beche_f
** Last update Thu Jun  2 16:08:39 2016 beche_f
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "list.h"
#include "lib.h"

int	parent(t_fork *f)
{
  f->ok = cmd_statut(f->pid, f->ok, f);
  close(f->p[1]);
  f->fd_in = f->p[0];
  if (check_builtin(f->tmp->arg[0]) == 1 && f->tmp->prev != NULL)
    f->r = 0;
  f->tmp = f->tmp->prev;
  return (0);
}
