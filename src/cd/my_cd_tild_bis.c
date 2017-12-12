/*
** my_cd_tild_bis.c for my_cd_tild_bis in /home/guicha_t/rendu/b2/unix/PSU_2015_42sh/src/thomas/cd
**
** Made by guicha_t
** Login   <guicha_t@epitech.net>
**
** Started on  Wed Apr 27 14:55:55 2016 guicha_t
** Last update Thu Apr 28 18:30:30 2016 guicha_t
*/

#include "list.h"
#include "lib.h"

int	search_first_char_home(char *str)
{
  if (str[0] == 'H')
    if (str[1] == 'O')
      if (str[2] == 'M')
        if (str[3] == 'E')
          if (str[4] == '=')
            return (0);
  return (-1);
}
