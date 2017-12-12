/*
** echo.c for ech in /home/oem/home/PSU_2015_42sh/src/ECHO_MAX
**
** Made by maxence.lauque
** Login   <lauque_m@epitech.net>
**
** Started on  Fri Jun  3 16:37:06 2016 maxence.lauque
** Last update Sun Jun  5 10:35:27 2016 beche_f
*/

#include <stdio.h>
#include "lib.h"

int	my_put_echo(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] != '"')
	{
	  if (my_putchar(str[i]) == -1)
	    return (1);
	}
      i++;
    }
  return (0);
}

int	echo_n_option(char **av, int i)
{
  if ((my_strcmp(av[i + 1], "-n")) == 0 && av[i + 2] != NULL)
    {
      i = 2;
      while (av[i] != NULL)
	{
	  my_put_echo(av[i]);
	  if (av[i + 1] != NULL)
	    my_putchar(' ');
	  i++;
	}
      return (0);
    }
  else
    return (-1);
}

int	only_echo(char **av, int i)
{
  if (av[i + 1] != NULL && ((my_strcmp(av[i + 1], "-n")) != 0))
    {
      i = 1;
      while (av[i] != NULL)
	{
	  my_put_echo(av[i]);
	  if (av[i + 1] != NULL)
	    my_putchar(' ');
	  i++;
	}
      my_putchar('\n');
      return (0);
    }
  return (-1);
}

int	echo(char **av)
{
  int	i;

  i = 0;
  while (av[i] != NULL)
    {
      if (((my_strcmp(av[i], "echo")) == 0) && av[i + 1] != NULL)
	{
	  if ((echo_n_option(av, i)) == 0)
	    return (0);
	  if ((only_echo(av, i)) == 0)
	    return (0);
	}
      else if (((my_strcmp(av[i], "echo")) == 0) && (av[i + 1] == NULL))
	{
	  my_putchar('\n');
	  return (0);
	}
      i++;
    }
  return (-1);
}
