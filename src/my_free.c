/*
** my_free.c for  in /home/beche_f/PSU_2015_42sh/src
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Fri May 20 19:16:54 2016 beche_f
** Last update Fri May 20 19:22:46 2016 beche_f
*/

#include <stdlib.h>
#include "list.h"
#include "lib.h"

void	free_for_cmd(t_shell *shell)
{
  free(shell->buffer);
  if (shell->path != NULL)
    free_char_2d(shell->path);
  free(shell->buffer_clean);
  free_char_2d(shell->cmd);
}

void	free_for_prog(t_shell *shell)
{
  if (shell->oldpwd != NULL)
    free(shell->oldpwd);
  if (shell->pwd != NULL)
    free(shell->oldpwd);
  free_env(shell->env);
  if (shell->home != NULL)
    free(shell->home);
}
