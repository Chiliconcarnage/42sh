/*
** go_to_exec.c for  in /home/beche_f/PSU_2015_42sh/src
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Fri Jun  3 15:12:56 2016 beche_f
** Last update Fri Jun  3 15:15:34 2016 beche_f
*/

#include <stdlib.h>
#include "list.h"
#include "lib.h"

int	go_to_exec(t_shell *shell, int ret)
{
  if (prep_cmd(shell) == 0 &&
      triple_token(shell->buffer_clean) == 0 &&
      begin_by_token(shell->buffer_clean) == 0 &&
      end_by_token(shell->buffer_clean) == 0 &&
      invalid_token(shell->buffer_clean) == 0 )
    {
      shell->cmd = str_2_wordtab(shell->cmd, shell->buffer_clean, ';');
      ret = fill_my_node_str(shell);
      free_for_cmd(shell);
    }
  return (ret);
}
