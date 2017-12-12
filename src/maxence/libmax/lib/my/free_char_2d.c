/*
** free_char_2d.c for free_char_2d in /home/oem/home/SBMLparser/lib/my
** 
** Made by maxence.lauque
** Login   <lauque_m@epitech.net>
** 
** Started on  Mon Jun 13 10:25:44 2016 maxence.lauque
** Last update Mon Jun 13 10:25:46 2016 maxence.lauque
*/

#include <stdlib.h>
#include "lib.h"

void	free_char_2d(char **map)
{
  int	y;

  y = 0;
  while (map[y] != NULL)
    {
      free(map[y]);
      y++;
    }
  free(map);
  map = NULL;
}
