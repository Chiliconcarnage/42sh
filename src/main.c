/*
** main.c for main in /home/oem/home/PSU_2015_42sh/src/Maxence_part
**
** Made by OEM Configuration (temporary user)
** Login   <lauque_m@epitech.net>
**
** Started on  Tue Apr 19 14:41:27 2016 OEM Configuration (temporary user)
** Last update Thu Jun  9 11:31:19 2016 bourre_a
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "lib.h"

int	save_home(char **env, t_shell *shell)
{
  int	i;

  i = 0;
  while (env[i] != '\0')
    {
      if (my_strcmp2(env[i], "HOME") == 1)
	if ((cut_home(shell, i, env)) == -1)
	  return (-1);
      i++;
    }
  return (0);
}

char	*get_first(char	*tmp, char *str)
{
  int	i;

  i = 0;
  while ((str[i] != '=') && (str[i] != '\0'))
    {
      tmp[i] = str[i];
      i++;
    }
  return (tmp);
}
int		cut_path_until_equals(char *str, t_shell *all)
{
  int		size_path;
  char		*tmp;

  (void)all;
  size_path = my_strlen(str) + 1;
  if ((tmp = malloc(sizeof(char) * (size_path + 1))) == NULL)
    return (-1);
  tmp = my_memset(tmp, '\0', size_path);
  tmp = cut_path(str,  tmp);
  all->path = str_2_wordtab(all->path, tmp, ':');
  free(tmp);
  return (0);
}

int	get_path(t_lenv *lenv, t_shell *shell)
{
  t_env	*tmp;

  tmp = lenv->tail;
  while (tmp != NULL)
    {
      if (tmp->line[0] == 'P' && tmp->line[1] == 'A' &&
	  tmp->line[2] == 'T' && tmp->line[3] == 'H' &&
	  tmp->line[4] == '=')
	{
	  cut_path_until_equals(tmp->line, shell);
	  return (0);
	}
      tmp = tmp->prev;
    }
  shell->path = NULL;
  return (-1);
}

int		main(int ac, char **av, char **env)
{
  t_shell	shell;
  int		ret;

  (void)ret;
  (void)ac;
  (void)av;
  ret = 0;
  init(&shell, env);
  while (shell.exit == 0)
    {
      if (get_path(shell.env, &shell) == -1)
	{
	  shell.path = NULL;
	  shell.is_path = -1;
	}
      else
	shell.is_path = 0;
      if (isatty(0))
	my_putstr("$>");
      if ((shell.buffer = get_next_line(0)) == NULL)
	return (ret);
      ret = go_to_exec(&shell, ret);
    }
  free_for_prog(&shell);
  return (shell.exit);
}
