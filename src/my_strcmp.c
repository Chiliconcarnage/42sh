/*
** my_strcmp.c for  in /home/beche_f/PSU_2015_42sh/src
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Fri May 20 15:51:02 2016 beche_f
** Last update Fri May 20 15:51:16 2016 beche_f
*/

#include "lib.h"

int	my_strcmp2(char *src, char *dest)
{
  int	inc;

  inc = 0;
  while (src[inc] != '\0')
    {
      if (dest[inc] == '\0')
	return (1);
      if (dest[inc] != src[inc])
	return (-1);
      inc++;
    }
  return (0);
}

int	my_strcmp3(char *src, char *dest)
{
  int	inc;

  inc = 0;
  while (src[inc] != '\0' && src[inc] == dest[inc])
    {
      if (dest[inc] == '\0')
	return (1);
      inc++;
    }
  return (0);
}
