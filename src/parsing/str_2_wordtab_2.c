/*
** str_2_wordtab.c for  in /home/beche_f/PSU_2015_minishell2/lib/my
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Sun Mar 20 16:28:03 2016 beche_f
** Last update Sun Jun  5 10:48:18 2016 beche_f
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

int	get_nb_line_2(char *str)
{
  int	i;
  int	nb;

  nb = 0;
  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == ' ')
	nb += 1;
      if (str[i] == '>' || str[i] == '<')
	{
	  if  (str[i+1] == '<' || str[i + 1] == '>')
	    i += 2;
	}
      i++;
    }
  nb++;
  return (nb);
}

char	**fill_char_2d_2(char **dest, char *str)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  x = 0;
  y = 0;
  while (str[i] != 0)
    {
      if (str[i] == ' ' && str[i + 1] != 0)
	{
	  i++;
	  y++;
	  x = 0;
	}
      if ((str[i] == '>') || (str[i] == '<'))
 	{
	  while ((str[i] == '>') || (str[i] == '<'))
	    i++;
	}
      else
	dest[y][x++] = str[i];
      i++;
    }
  return (dest);
}

char	**str_2_wordtab_2(char **dest, char *src)
{
  int	line;
  int	width;
  int	y;

  y = 0;
  width = my_strlen(src) + 1;
  line = get_nb_line_2(src);
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
  dest = fill_char_2d_2(dest, src);
  return (dest);
}
