/*
** free_char_2d.c for  in /home/beche_f/PSU_2015_minishell2/lib/my
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Sun Mar 20 16:45:14 2016 beche_f
** Last update Fri Mar 25 18:08:09 2016 beche_f
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
