/*
** main.c for main test in /home/loisel_k/taff/C/Librairie/my
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Thu Jan  9 12:20:46 2014 Kevin LOISELEUR
** Last update Thu Jan  9 12:24:28 2014 Kevin LOISELEUR
*/

#include <string.h>
#include "my.h"

int			main(int ac, char **av)
{
  char			*ret;
  char			*ret2;

  ret = my_strncat(av[1], av[2], 3);
  ret2 = strncat(av[1], av[2], 3);
  my_printf("%s\n", ret);
  my_printf("%s\n", ret2);
  return (0);
}
