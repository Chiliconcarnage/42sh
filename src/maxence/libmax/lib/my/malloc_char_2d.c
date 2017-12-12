/*
** malloc_char_2d.c for malloc_char_2d in /home/oem/home/SBMLparser/lib/my
** 
** Made by maxence.lauque
** Login   <lauque_m@epitech.net>
** 
** Started on  Mon Jun 13 10:26:50 2016 maxence.lauque
** Last update Mon Jun 13 10:26:51 2016 maxence.lauque
*/

#include <stdlib.h>
#include "lib.h"

char	**malloc_char_2d(char **tab, int width, int height)
{
  int	y;

  y = 0;
  if ((tab = malloc(sizeof(char*) * (height + 1))) == NULL)
    return (NULL);
  tab[height] = NULL;
  while (y < height)
    {
      if ((tab[y] = malloc(sizeof(char) * (width + 1))) == NULL)
	return (NULL);
      my_memset(tab[y], '\0', width);
      y++;
    }
  return (tab);
}
