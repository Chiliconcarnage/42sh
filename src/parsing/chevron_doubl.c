/*
** chevron_doubl.c for chevrons_doubl in /home/bourre_a/Semestre_2/Programmation_Shell/PSU_2015_42sh/src/quentin/src
**
** Made by bourre_a
** Login   <bourre_a@epitech.net>
**
** Started on  Fri Apr 22 11:15:07 2016 bourre_a
** Last update Fri May 20 18:43:15 2016 beche_f
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "lib.h"


int	get_word_after_chevron(t_cmd    *list, char *str, t_final *final)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  (void)list;
  while ((str[i] != '<') && (str[i] != '>') && (str[i] != '\0'))
    i++;
  while ((str[i] != ' ') && (str[i] != '\0'))
    i++;
  i++;
  while (str[i] != ' ' && str[i] != '\0')
    final->word[j++] = str[i++];
  return (0);
}

int	fill_chevron_doubl(t_cmd        *list, char *buffer, t_final *final)
{
  int   i;

  i = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '>')
	{
	  final->chevron = '>';
	  final->doubl = 1;
	  if (buffer[++i] == '>')
	    final->doubl = 2;
	}
      else if (buffer[i] == '<')
	{
	  final->chevron = '<';
	  final->doubl = 1;
	  if (buffer[++i] == '<')
	    final->doubl = 2;
	}
      i++;
    }
  if (final->doubl != 0)
    get_word_after_chevron(list, buffer, final);
  return (0);
}


int	boucle(char	*buffer, t_cmd *list, t_final *final)
{
  char	**tmp;
  int	i;

  tmp = NULL;
  if ((tmp = str_2_wordtab(tmp, buffer, '|')) == NULL)
    return (-1);
  i = 0;
  while (tmp[i] != NULL)
    {
      init_final(final, tmp[i]);
      tmp[i] = epure_av(tmp[i]);
      fill_chevron_doubl(list, tmp[i], final);
      put_my_cmd(list, final, tmp[i]);
      i++;
      if (final->word != NULL)
	free(final->word);
    }
  free_char_2d(tmp);
  return (0);
}
