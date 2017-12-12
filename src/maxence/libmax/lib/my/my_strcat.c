/*
** my_strcat.c for my_strcat in /home/oem/home/SBMLparser/lib/my
** 
** Made by maxence.lauque
** Login   <lauque_m@epitech.net>
** 
** Started on  Mon Jun 13 10:27:42 2016 maxence.lauque
** Last update Mon Jun 13 10:27:43 2016 maxence.lauque
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
