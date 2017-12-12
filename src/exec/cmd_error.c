/*
** cmd_error.c for  in /home/beche_f/PSU_2015_42sh/src/exec
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Fri May 20 16:08:03 2016 beche_f
** Last update Fri May 20 16:10:45 2016 beche_f
*/

#include <stdlib.h>
#include "list.h"
#include "lib.h"

int	put_cmd_error(char *cmd)
{
  puterror(cmd, ": Command not found.\n");
  exit(EXIT_FAILURE);
  return (0);
}
