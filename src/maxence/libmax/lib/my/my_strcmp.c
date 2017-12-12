/*
** my_strcmp.c for strcmp in /home/oem/home/SBMLparser/lib/my
** 
** Made by maxence.lauque
** Login   <lauque_m@epitech.net>
** 
** Started on  Mon Jun 13 10:27:53 2016 maxence.lauque
** Last update Mon Jun 13 10:27:54 2016 maxence.lauque
*/

#include <stdlib.h>
#include "lib.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (s2 == NULL)
    return (1);
  if (my_strlen(s1) != my_strlen(s2))
    return (-1);
  while (s1[i] != '\0')
    {
      if ((s1[i] != s2[i]) || s1 == '\0' || s2 == '\0')
	return (1);
      i = i + 1;
    }
  return (0);
}

int	my_strcmp_no_lenght(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (s2 == NULL)
    return (1);
  while (s1[i] != '\0')
    {
      if ((s1[i] != s2[i]) || s1 == '\0' || s2 == '\0')
	return (1);
      i = i + 1;
    }
  return (0);
}
