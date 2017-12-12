/*
** prep_cmd.c for  in /home/beche_f/PSU_2015_42sh/src
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Fri May 20 19:29:50 2016 beche_f
** Last update Thu Jun  9 11:32:42 2016 bourre_a
*/

#include <stdio.h>
#include "list.h"
#include "lib.h"

int	prep_cmd(t_shell *shell)
{
  epure_av(shell->buffer);
  if (shell->buffer[0] == ';' || shell->buffer[my_strlen(shell->buffer) - 1] == ';')
    return (-1);
  if (shell->buffer[0] == 0)
    return (-1);
  clean_my_buffer(shell);
  return (0);
}
