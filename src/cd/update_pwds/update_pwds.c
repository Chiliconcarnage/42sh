/*
** update_pwds.c for update_pwds in /home/guicha_t/rendu/b2/unix/PSU_2015_42sh/src/thomas/update_pwds
**
** Made by guicha_t
** Login   <guicha_t@epitech.net>
**
** Started on  Thu Apr 28 12:23:19 2016 guicha_t
** Last update Thu Apr 28 16:50:01 2016 guicha_t
*/

#include <stdlib.h>
#include "list.h"
#include "lib.h"

char	*my_new_oldpwd_struct(char *str)
{
  int	size;
  char	*tmp;
  int	i;

  size = my_strlen(str);
  tmp = malloc(sizeof(char) * (size + 1));
  if (tmp == NULL)
    return (NULL);
  tmp = my_memset(tmp, '\0', size);
  i = 0;
  while (str[i] != '\0')
    {
      tmp[i] = str[i];
      i++;
    }
  return (tmp);
}

int	update_pwds(t_lenv *lenv, t_shell *s, char *old_pwd, char *pwd)
{
  if (s->oldpwd != NULL)
    free(s->oldpwd);
  s->oldpwd = my_new_oldpwd_struct(old_pwd);
  if (manage_setenv(lenv, "OLDPWD", old_pwd) == -1)
    return (-1);
  if (manage_setenv(lenv, "PWD", pwd) == -1)
    return (-1);
  return (0);
}
