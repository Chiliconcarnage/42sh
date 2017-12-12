/*
** my_put_nbr.c for my_put_nbr in /home/oem/home/SBMLparser/lib/my
** 
** Made by maxence.lauque
** Login   <lauque_m@epitech.net>
** 
** Started on  Mon Jun 13 10:27:33 2016 maxence.lauque
** Last update Mon Jun 13 10:27:33 2016 maxence.lauque
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
