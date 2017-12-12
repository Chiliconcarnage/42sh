/*
** my_main_cd.c for my_main_cd in /home/guicha_t/rendu/b2/unix/PSU_2015_42sh/src/thomas/cd
**
** Made by guicha_t
** Login   <guicha_t@epitech.net>
**
** Started on  Mon Apr 25 18:35:41 2016 guicha_t
** Last update Sun Jun  5 11:02:47 2016 beche_f
*/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include "list.h"
#include "lib.h"

int		found_type(char *file)
{
  struct stat	s;

  if (stat(file, &s) != 0)
    return (0);
  if (!S_ISDIR(s.st_mode))
    {
      my_putstr(file);
      my_putstr(": Not a directory.\n");
      return (1);
    }
  return (0);
}

int	my_main_cd(t_lenv *lenv, t_shell *s, char **arg)
{
  char	oldpwd[500];
  char	pwd[500];

  getcwd(oldpwd, 500);
  if (found_type(arg[1]) == 1)
    return (-1);
  if (access(arg[1], F_OK | R_OK) == -1)
    {
      my_putstr(arg[1]);
      my_putstr(": Permission denied.\n");
      return (-1);
    }
  if (chdir(arg[1]) == -1)
    {
      my_putstr(arg[1]);
      my_putstr(": No such file or directory.\n");
      return (-1);
    }
  getcwd(pwd, 500);
  if (update_pwds(lenv, s, oldpwd, pwd) == -1)
    return (-1);
  return (0);
}
