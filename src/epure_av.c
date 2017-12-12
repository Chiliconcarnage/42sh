/*
** epure_av.c for  in /home/beche_f/PSU_2015_42sh/src
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Fri May 20 19:35:18 2016 beche_f
** Last update Fri May 20 19:35:32 2016 beche_f
*/

#include "lib.h"

int	end_str(char *tmp, int a)
{
  int	c;

  c = 0;
  while (tmp[a] != '\0')
    {
      if (tmp[a] != 32 && tmp[a] != 8)
        c++;
      a++;
    }
  if (c != 0)
    return (1);
  else
    return (0);
}

char	*epure_av(char *tmp)
{
  int   i;
  int   nb;

  i = 0;
  nb = 0;
  while (tmp[i] == 32 || tmp[i] == '\t')
    i++;
  while (tmp[i] != '\0')
    {
      if (tmp[i] == ' ' || tmp[i] == '\t')
        {
          if (end_str(tmp, i) == 1)
            tmp[nb++] = ' ';
          while (tmp[i] == ' ' || tmp[i] == '\t')
            i++;
        }
      tmp[nb++] = tmp[i++];
    }
  tmp[i] = '\0';
  tmp[nb] = '\0';
  if (tmp[nb - 1] == 32)
    tmp[nb - 1] = '\0';
  return (tmp);
}
