/*
** lib.h for lib.h in /home/oem/home/SBMLparser/lib/my/include
** 
** Made by maxence.lauque
** Login   <lauque_m@epitech.net>
** 
** Started on  Mon Jun 13 10:25:02 2016 maxence.lauque
** Last update Mon Jun 13 19:19:21 2016 maxence.lauque
*/

#ifndef LIB_H_
#define LIB_H_

#include "my.h"

int	my_strlen(char*);
int	my_putchar(char);
int	my_putstr(char*);
int	my_puterror(char*);
int	my_getnbr(char*);
char	*my_memset(char*, char, int);
int	my_put_nbr(int);
char	*my_strcat(char*, char*);
char	*my_strcat_2(char*, char*);
void	free_char_2d(char**);
void	display_char_2d(char**);
char	*get_next_line(int);
char	**malloc_char_2d(char**, int, int);
int	my_strcmp(char*, char*);
int	my_strcmp_no_lenght(char*, char*);
char	**str_2_wordtab(char**, char*, char, t_all *);
#endif /* !LIB_H_ */
