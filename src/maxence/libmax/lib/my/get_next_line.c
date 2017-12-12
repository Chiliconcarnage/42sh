/*
** main.c for main in /home/oem/home/CPE_2015_getnextline_bootstrap
**
** Made by OEM Configuration (temporary user)
** Login   <oem@epitech.net>
**
** Started on  Wed Jan  6 19:02:51 2016 OEM Configuration (temporary user)
** Last update Mon Jun 13 10:34:33 2016 maxence.lauque
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	nbr_len(char *str, int a)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (a == 1)
    {
      while (str[i] != '\0')
	i++;
      return (i);
    }
  if (a == 2)
    {
      while (str[i] != '\0')
	{
	  if (str[i] == '\n')
	    j++;
	  i++;
	}
      return (j);
    }
  return (-1);
}

char	*my_realloc(char *buff, char *stock, int size)
{
  char  *tmp;
  int   i;
  int   j;

  j = i = 0;
  if ((tmp = malloc(size + 1)) == NULL)
    return (NULL);
  while (i <= size)
    tmp[i++] = 0;
  i = 0;
  if (stock != NULL)
    {
      while (stock[i] != 0)
	{
	  tmp[i] = stock[i];
	  i++;
	}
      free(stock);
    }
  i = j = 0;
  while (tmp[i] != 0)
    i++;
  while ((buff[j] != 0) && (buff[j] != '\n'))
    tmp[i++] = buff[j++];
  return (tmp);

}

char	*my_buff(char *buff)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while ((buff[i] != '\n'))
    i++;
  i++;
  while (buff[i] != '\0')
    {
      buff[j] = buff[i];
      i++;
      j++;
    }
  buff[j] = '\0';
  return (buff);
}

char	*switch_buff(char *buff, char *stock)
{
  if (nbr_len(buff, 2) <= 0)
    return (NULL);
  buff = my_buff(buff);
  if ((stock = my_realloc(buff, stock, READ_SIZE)) == NULL)
    return (NULL);
  if (nbr_len(buff, 2) < 0)
    return (stock);
  return (stock);
}

char	*get_next_line(const int folder)
{
  static char	buff[READ_SIZE + 1];
  char		*stock;
  int		a;
  int		ret;

  stock = NULL;
  ret = a = 0;
  stock = switch_buff(buff, stock);
  if (nbr_len(buff, 2) > 0)
    return (stock);
  while ((a = read(folder, buff, READ_SIZE)) > 0)
    {
      buff[a] = '\0';
      ret = ret + a + READ_SIZE;
      stock = my_realloc(buff, stock, ret);
      if (nbr_len(buff, 2) > 0)
	return (stock);
    }
  if (buff[0] != 0)
    return (stock);
  free(stock);
  return (NULL);
}
