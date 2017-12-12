/*
** str_2_wordtab.c for  in /home/beche_f/PSU_2015_minishell2/lib/my
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Sun Mar 20 16:28:03 2016 beche_f
** Last update Fri Apr 22 11:55:28 2016 bourre_a
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

int	get_nb_line_1(char *str)
{
  int	i;
  int	nb;

  nb = 0;
  i = 0;
  while (str[i] != 0)
    {
      if (((str[i] == '&') && (str[i + 1] == '&'))
	  || ((str[i] == '|') && (str[i + 1] == '|')))
	nb += 2;
      i++;
    }
  nb++;
  return (nb);
}

char	**fill_char_2d_1(char **dest, char *str)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  x = 0;
  y = 0;
  while (str[i] != 0)
    {
      if (((str[i] == '&') && (str[i + 1] == '&'))
	  || ((str[i] == '|') && (str[i + 1] == '|')))
	{
	  dest[++y][0] = str[i++];
	  dest[y++][1] = str[i];
	  i++;
	  x = 0;
	}
      else
	{
	  dest[y][x] = str[i];
	  x++;
	}
      i++;
    }
  return (dest);
}

char	**str_2_wordtab_1(char **dest, char *src)
{
  int	line;
  int	width;
  int	y;

  y = 0;
  width = my_strlen(src) + 1;
  line = get_nb_line_1(src);
  if ((dest = malloc(sizeof(char*) * (line + 1))) == NULL)
    return (NULL);
  dest[line] = NULL;
  while (y < line)
    {
      if ((dest[y] = malloc(sizeof(char) * (width + 1))) == NULL)
	return (NULL);
      my_memset(dest[y], '\0', width);
      y++;
    }
  dest = fill_char_2d_1(dest, src);
  return (dest);
}
