/*
** my.h for my.h in /home/oem/home/SBMLparser/include
** 
** Made by maxence.lauque
** Login   <lauque_m@epitech.net>
** 
** Started on  Mon Jun 13 15:29:45 2016 maxence.lauque
** Last update Mon Jun 13 21:51:13 2016 maxence.lauque
*/

#ifndef MY_H_
#define MY_H_

typedef struct	s_all
{
  int	*size_words;
  int	nb_words;
}		t_all;

char    **my_strtowordtab_synthesis(char *);
char	*epure_av(char *);
int	get_nb_line(char *, char);

#endif /* !MY_H_ */
