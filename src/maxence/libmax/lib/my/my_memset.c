/*
** my_memset.c for my_memset in /home/oem/home/SBMLparser/lib/my
** 
** Made by maxence.lauque
** Login   <lauque_m@epitech.net>
** 
** Started on  Mon Jun 13 10:27:20 2016 maxence.lauque
** Last update Mon Jun 13 10:27:21 2016 maxence.lauque
*/

char	*my_memset(char *str, char c, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      str[i] = c;
      i++;
    }
  str[i] = 0;
  return (str);
}
