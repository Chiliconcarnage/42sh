/*
** cut_str.c for  in /home/oem/home/Minishell_1
**
** Made by OEM Configuration (temporary user)
** Login   <lauque_m@epitech.net>
**
** Started on  Mon Mar 21 15:31:18 2016 OEM Configuration (temporary user)
** Last update Sun Jun  5 10:56:14 2016 beche_f
*/

#include <stdlib.h>
#include "list.h"
#include "lib.h"

int	cut_home(t_shell *shell, int i, char **env)
{
  int	size_str;
  int	j;
  int	k;

  j = 0;
  k = 0;
  size_str = 0;
  size_str = my_strlen(env[i]);
  if ((shell->home = malloc(sizeof(char *) * size_str + 1)) == NULL)
    return (-1);
  shell->home = my_memset(shell->home, '\0', size_str);
  while (env[i][j] != '=')
    j++;
  j++;
  while (env[i][j] != '\0')
    shell->home[k++] = env[i][j++];
  shell->home[k] = '\0';
  return (0);
}

char	*cut_path(char *src, char *tmp)
{
  int	i;
  int	j;

  i = 5;
  j = 0;
  while (src[i] != 0)
    {
      tmp[j] = src[i];
      j++;
      i++;
    }
  return (tmp);
}
