/*
** init_final.c for init_final in /home/bourre_a/Semestre_2/Programmation_Shell/PSU_2015_42sh/src/quentin/src
**
** Made by bourre_a
** Login   <bourre_a@epitech.net>
**
** Started on  Fri Apr 22 11:15:59 2016 bourre_a
** Last update Wed Apr 27 15:29:18 2016 beche_f
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "lib.h"

int	init_final(t_final *final, char *str)
{
  int   size;

  final->doubl = 0;
  final->chevron = '\0';
  size = my_strlen(str);
  if ((final->word = malloc(sizeof(char) * (size + 1))) == NULL)
    return (-1);
  final->word = my_memset(final->word, '\0', size);
  return (0);
}
