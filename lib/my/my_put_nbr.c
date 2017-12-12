/*
** my_put_nbr.c for  in /home/beche_f/rendu/pushswap
**
** Made by francois beche
** Login   <beche_f@epitech.net>
**
** Started on  Sat Nov  7 18:27:45 2015 francois beche
** Last update Wed Mar 16 14:07:10 2016 beche_f
*/

#include "lib.h"

int	my_put_nbr(int nb)
{
  int	diviseur;
  int	result;

  if (nb < 0)
    {
      if ((my_putchar('-')) == -1)
	return (-1);
      nb = -nb;
    }
  diviseur = 1;
  while ( (nb / diviseur) >= 10)
    diviseur = diviseur * 10;
  while (diviseur > 0)
    {
      result = (nb / diviseur) % 10;
      if ((my_putchar(result + 48)) == -1)
	return (-1);
      diviseur = diviseur / 10;
    }
  return (0);
}
