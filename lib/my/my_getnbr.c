/*
** my_getnbr.c for  in /home/beche_f/rendu/lib/my
**
** Made by francois beche
** Login   <beche_f@epitech.net>
**
** Started on  Tue Nov 17 16:18:22 2015 francois beche
** Last update Sun Mar 20 15:18:45 2016 beche_f
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
