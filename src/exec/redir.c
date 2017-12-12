/*
** redir.c for  in /home/beche_f/PSU_2015_42sh/src/fran/src
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Thu Apr 21 21:13:19 2016 beche_f
** Last update Fri May 20 15:55:10 2016 beche_f
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "list.h"
#include "lib.h"

int	redir_right(t_elem *tmp)
{
  int	ret;

  if (tmp->chevron == '>' && tmp->doubl == 1)
    {
      if ((ret = open(tmp->word, O_WRONLY | O_TRUNC |
		      O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR)) == -1)
	return (-1);
      dup2(ret, 1);
    }
  if (tmp->chevron == '>' && tmp->doubl == 2)
    {
      if ((ret = open(tmp->word, O_WRONLY | O_APPEND |
  		      O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR)) == -1)
  	return (-1);
      dup2(ret, 1);
    }
  return (0);
}

int	redir_left(t_elem *tmp)
{
  int	ret;

  if (tmp->chevron == '<' && tmp->doubl == 1)
    {
      if ((ret = open(tmp->word, O_RDONLY)) == -1)
	  return (-1);
      return (ret);
    }
  return (0);
}

int	redir_left2(t_elem *tmp)
{
  int	i;
  char	*s;

  i = 0;
  while (i == 0)
    {
      s = get_next_line(0);
      if (my_strcmp(s, tmp->word) == 0)
	i = 1;
    }
  return (0);
}
