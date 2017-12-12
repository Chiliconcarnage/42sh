/*
** display_char_2d.c for  in /home/beche_f/PSU_2015_minishell2/lib/my
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Sun Mar 20 16:48:55 2016 beche_f
** Last update Sun Mar 20 16:51:15 2016 beche_f
*/

#include <stdlib.h>
#include "lib.h"

void	display_char_2d(char **map)
{
  int	y;

  y = 0;
  while (map[y] != NULL)
    {
      my_putstr(map[y]);
      my_putchar('\n');
      y++;
    }
}
