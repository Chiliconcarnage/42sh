/*
** malloc_char_2d.c for  in /home/beche_f/PSU_2015_minishell2/lib/my
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Mon Mar 28 20:32:25 2016 beche_f
** Last update Mon Mar 28 23:52:08 2016 beche_f
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
