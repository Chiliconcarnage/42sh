/*
** basic_one.c for basic_one in /home/guicha_t/rendu/b2/unix/PSU_2015_42sh/src/thomas/basic
**
** Made by guicha_t
** Login   <guicha_t@epitech.net>
**
** Started on  Thu Apr 21 12:12:44 2016 guicha_t
** Last update Thu Apr 28 18:08:08 2016 beche_f
*/

#include <stdlib.h>
#include "list.h"
#include "lib.h"

char	*reduce_string(char *str, int i)
{
  char	*tmp;
  int	size;
  int	t;

  size = my_strlen(str);
  if ((tmp = malloc(sizeof(char) * size + 1)) == NULL)
    return (NULL);
  tmp = my_memset(tmp, '\0', size);
  t = 0;
  while (str[i] != '\0')
    {
      tmp[t] = str[i];
      i++;
      t++;
    }
  tmp[t] = 0;
  return (tmp);
}
