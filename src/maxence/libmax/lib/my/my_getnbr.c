/*
** my_getnbr.c for my_get_nbr in /home/oem/home/SBMLparser/lib/my
** 
** Made by maxence.lauque
** Login   <lauque_m@epitech.net>
** 
** Started on  Mon Jun 13 10:27:05 2016 maxence.lauque
** Last update Mon Jun 13 10:27:06 2016 maxence.lauque
*/

#include "lib.h"

int	my_getnbr(char *str)
{
  int	i;
  int	res;
  int	multi;
  int	is_neg;

  i = my_strlen(str) - 1;;
  multi = 1;
  res = 0;
  is_neg = 0;
  if (str[0] == '-')
    is_neg = 1;
  while (i >= is_neg)
    {
      res = (str[i] - 48) * multi + res;
      i = i - 1;
      multi = multi * 10;
    }
  if (is_neg == 1)
    res = -res;
  return (res);
}
