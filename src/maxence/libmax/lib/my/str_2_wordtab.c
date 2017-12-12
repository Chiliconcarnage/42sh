/*
** str_2_wordtab.c for str_2_wordtab in /home/oem/home/SBMLparser/lib/my
** 
** Made by maxence.lauque
** Login   <lauque_m@epitech.net>
** 
** Started on  Mon Jun 13 10:28:11 2016 maxence.lauque
** Last update Mon Jun 13 22:46:35 2016 maxence.lauque
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
#include "my.h"

int	get_width(char	*str, char c)
{
  int	i;
  int	len;
  int	width;

  width = 0;
  len = 0;
  i = 0;
  while (str[i] != 0)
    {
      if (str[i] != c)
	{
	  len++;
	}
      else
	{
	  if (width < len)
	    width = len;
	  len = 0;
	}
      i++;
    }
  if (width < len)
    width = len;
  return (width);
}

int	get_nb_line(char *str, char c)
{
  int	i;
  int	nb;

  nb = 0;
  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == c)
	nb++;
      i++;
    }
  nb = nb + 1;
  return (nb);
}

/* int	get_nb_line(char *str, char c) */
/* { */
/*   int	i; */
/*   int	nb; */

/*   nb = 0; */
/*   i = 0; */
/*   (void)c; */
/*   while (str[i] != '\0') */
/*     { */
/*       if ((str[i] >= 97 && str[i] <= 122) || */
/* 	  (str[i] >= 65 && str[i] >= 90)  || */
/* 	  (str[i] >= '0' && str[i] <= '9')) */
/* 	{ */
/* 	  while ((str[i] >= 97 && str[i] <= 122) || */
/* 		 (str[i] >= 65 && str[i] >= 90)  || */
/* 		 (str[i] >= '0' && str[i] <= '9')) */
/* 	    i++; */
/* 	  nb++; */
/* 	} */
/*       else */
/* 	i++; */
/*     } */
/*   nb = nb + 1; */
/*   return (nb); */
/* } */

char	**fill_char_2d(char **dest, char *src, char c)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  x = 0;
  y = 0;
  while (src[i] != 0)
    {
      if (src[i] == c)
	{
	  y++;
	  x = 0;
	}
      else
	{
	  dest[y][x] = src[i];
	  x++;
	}
      i++;
    }
  return (dest);
}

char	**str_2_wordtab(char **dest, char *src, char c, t_all *all)
{
  int	line;
  int	width;
  int	y;

  (void)all;
  y = 0;
  width = get_width(src, c) + 1;
  line = get_nb_line(src, c) + 1;
  /* my_put_nbr(line); */
  /* my_putchar('\n'); */
  if ((dest = malloc(sizeof(char*) * (line+ 1))) == NULL)
    return (NULL);
  dest[line] = NULL;
  while (y < line)
    {
      if ((dest[y] = malloc(sizeof(char) * (width+ 1))) == NULL)
	return (NULL);
      my_memset(dest[y], '+', width);
      y++;
    }
  dest = fill_char_2d(dest, src, c);
  return (dest);
}
