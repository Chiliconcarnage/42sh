/*
** error_unsetenv.c for  in /home/beche_f/PSU_2015_42sh/src/manage_arg
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Fri May 20 19:36:57 2016 beche_f
** Last update Fri May 20 19:39:08 2016 beche_f
*/

#include <stdlib.h>
#include "list.h"
#include "lib.h"

int	error_unsetenv(char **arg)
{
  if (my_strcmp(arg[0], "unsetenv") == 1 && arg[1] == NULL)
    {
      my_putstr("unsetenv: Too few arguments.\n");
      return (-1);
    }
  return (0);
}
