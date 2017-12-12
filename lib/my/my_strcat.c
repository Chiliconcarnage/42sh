/*
** my_strcat.c for  in /home/beche_f/PSU_2015_minishell2/lib/my
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Sun Mar 20 16:09:00 2016 beche_f
** Last update Mon Mar 21 20:24:41 2016 beche_f
*/

#include "lib.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != 0)
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}

char	*my_strcat_2(char *dest, char *src)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (dest[i] != 0)
    i++;
  while (src[j] != 0)
    {
      dest[i] = src[j];
      i++;
      j++;
    }
    dest[i] = 0;
  return (dest);
}
