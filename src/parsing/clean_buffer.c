/*
** clean_buffer.c for clean_buffer in /home/bourre_a/Semestre_2/Programmation_Shell/PSU_2015_42sh/src/quentin/src
**
** Made by bourre_a
** Login   <bourre_a@epitech.net>
**
** Started on  Tue Apr 26 13:50:55 2016 bourre_a
** Last update Wed May 25 14:32:38 2016 beche_f
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "lib.h"

int	nb_more_malloc(char *str)
{
  int   i;
  int   nb;

  i = 0;
  nb = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
        nb++;
      if ((str[i] == '>') || (str[i] == '<')
          || (str[i] == '&') || (str[i] == '|'))
        nb += 2;
      i++;
    }
  nb++;
  return (nb);
}

int	fill_new_part(t_shell *shell, char c)
{
  shell->buffer_clean[shell->j++] = ' ';
  while (shell->buffer[shell->i] == c)
    {
      shell->buffer_clean[shell->j] = shell->buffer[shell->i];
      shell->j++;
      shell->i++;
    }
  shell->buffer_clean[shell->j++] = ' ';
  return (0);
}

int	fill_buffer_clean(t_shell *s)
{
  s->i = 0;
  s->j = 0;
  while (s->buffer[s->i] != '\0')
    {
      if (s->buffer[s->i] == '>')
        fill_new_part(s, '>');
      else if (s->buffer[s->i] == '<')
        fill_new_part(s, '<');
      else if (s->buffer[s->i] == '&')
        fill_new_part(s, '&');
      else if (s->buffer[s->i] == '|')
      	fill_new_part(s, '|');
      else
        {
          s->buffer_clean[s->j] = s->buffer[s->i];
          s->i++;
          s->j++;
        }
    }
  return (0);
}

int	clean_my_buffer(t_shell *shell)
{
  int   size;
  int   nb_word;

  nb_word = nb_more_malloc(shell->buffer);
  size = my_strlen(shell->buffer) + (nb_word + 1);
  if ((shell->buffer_clean = malloc(sizeof(char) * (size + 1))) == NULL)
    return (-1);
  shell->buffer_clean = my_memset(shell->buffer_clean, '\0', size);
  fill_buffer_clean(shell);
  shell->buffer_clean = epure_av(shell->buffer_clean);
  return (0);
}
