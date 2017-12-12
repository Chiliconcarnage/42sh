/*
** main.c for main in /home/oem/home/SBMLparser/src
** 
** Made by maxence.lauque
** Login   <lauque_m@epitech.net>
** 
** Started on  Mon Jun 13 10:35:24 2016 maxence.lauque
** Last update Mon Jun 13 22:26:59 2016 maxence.lauque
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "lib.h"
#include "get_next_line.h"
#include "my.h"

/* int     get_nb_line(char *str, char c) */
/* { */
/*   int   i; */
/*   int   nb; */

/*   nb = 0; */
/*   i = 0; */
/*   (void)c; */
/*   while (str[i] != 0) */
/*     { */
/*       if ((str[i] >= 97 && str[i] <= 122) || */
/*           (str[i] >= 65 && str[i] >= 90)  || */
/*           (str[i] >= '0' && str[i] <= '9')) */
/*         { */
/*           while ((str[i] >= 97 && str[i] <= 122) || */
/*                  (str[i] >= 65 && str[i] >= 90)  || */
/*                  (str[i] >= '0' && str[i] <= '9')) */
/*             i++; */
/*           nb++; */
/*         } */
/*       else */
/*         i++; */
/*     } */
/*   nb = nb + 1; */
/*   return (nb); */
/* } */

char	*epure_av(char *tmp)
{
  int	i;

  i = 0;
  while (tmp[i] != '\0')
    {
      if (((tmp[i] < 48) || (tmp[i] > 57))
          && ((tmp[i] < 97) || (tmp[i] > 122))
          && ((tmp[i] < 65) || (tmp[i] > 90)))
        tmp[i] = '+';
      i++;
    }
  return (tmp);
}

char	**my_strtowordtab_synthesis(char *str)
{
  char	**tab;
  t_all all;
  int	a;

  a = 0;
  (void)tab;
  (void)all;
  tab = NULL;
  str = epure_av(str);
  tab = str_2_wordtab(tab, str, '+', &all);
  while (tab[a] != NULL)
    {
      my_putstr(tab[a]);
      my_putchar('\n');
      a++;
    }
  my_putchar('\n');
  return (0);
}

int	main(int ac, char **av)
{
  int	fd;
  char	*buff;

  (void)av;
  (void)fd;
  if (ac != 2)
    {
      my_puterror("error\n");
      return (0);
    }
  fd = open(av[1], O_RDONLY);
  while ((buff = get_next_line(fd)))
    my_strtowordtab_synthesis(buff);
  return (0);
}
