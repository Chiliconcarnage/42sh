/*
** my_cd_tild.c for my_cd_tild in /home/guicha_t/rendu/b2/unix/PSU_2015_42sh/src/thomas/cd
**
** Made by guicha_t
** Login   <guicha_t@epitech.net>
**
** Started on  Tue Apr 26 16:22:20 2016 guicha_t
** Last update Sun Jun  5 11:02:23 2016 beche_f
*/

#include <stdlib.h>
#include <unistd.h>
#include "list.h"
#include "lib.h"

char		*my_search_line_home(t_lenv *lenv)
{
  t_env		*elem;
  char		*tmp;

  elem = lenv->head;
  while (elem != NULL)
    {
      if (search_first_char_home(elem->line) == 0)
	{
	  tmp = reduce_string(elem->line, 5);
	  return (tmp);
	}
      elem = elem->next;
    }
  return (NULL);
}

char	*my_concat_home_and_arg(char *home, char *arg)
{
  char	*tmp;
  int	size;
  int	t;
  int	i;

  size = my_strlen(home) + my_strlen(arg);
  if ((tmp = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  tmp = my_memset(tmp, '\0', size);
  t = 0;
  i = 0;
  while (home[i] != '\0')
    tmp[t++] = home[i++];
  i = 1;
  while (arg[i] != '\0')
    tmp[t++] = arg[i++];
  return (tmp);
}

int	my_really_cd_tild(t_lenv *lenv, t_shell *s, char *path)
{
  char	oldpwd[500];
  char	pwd[500];

  getcwd(oldpwd, 500);
  if (chdir(path) == -1)
    {
      my_puterror(path);
      my_puterror(": No such file or directory.\n");
      return (-1);
    }
  getcwd(pwd, 500);
  free(path);
  if (update_pwds(lenv, s, oldpwd, pwd) == -1)
    return (-1);
  return (0);
}

int	my_tild_extend(t_lenv *lenv, t_shell *s, char **arg)
{
  char	*home;
  char	*path;

  home = my_search_line_home(lenv);
  if (home != NULL)
    path = my_concat_home_and_arg(home, arg[1]);
  else
    path = my_concat_home_and_arg(s->home, arg[1]);
  if (my_really_cd_tild(lenv, s, path) == -1)
    return (-1);
  free(home);
  return (0);
}

int	my_cd_tild(t_lenv *lenv, t_shell *s, char **arg)
{
  if (my_strlen(arg[1]) == 1)
    my_cd_home(lenv, s);
  else
    {
      if (my_tild_extend(lenv, s, arg) == -1)
	return (-1);
    }
  return (0);
}
