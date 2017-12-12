/*
** init.c for  in /home/beche_f/PSU_2015_42sh/src
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Fri May 20 19:12:34 2016 beche_f
** Last update Fri May 27 19:38:44 2016 beche_f
*/

#include <stdlib.h>
#include "list.h"
#include "lib.h"

int	init(t_shell *shell, char **env)
{
  if ((shell->env = creat_lenv()) == NULL)
    return (0);
  if (env[0] == NULL)
    {
      manage_setenv_add(shell->env, "PATH", "/bin");
    }
  else
    get_env(shell->env, env);
  shell->home = NULL;
  shell->pwd = NULL;
  shell->oldpwd = NULL;
  save_home(env, shell);
  shell->exit = 0;
  shell->envi = env;
  shell->is_path = 0;
  shell->oldpwd = NULL;
  return (0);
}
