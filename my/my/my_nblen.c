/*
** my_nblen.c for longueur d'un nombre in /home/loisel_k/travail/Librairie/my
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Thu Nov 14 16:39:22 2013 kevin loiseleur
** Last update Thu Nov 14 16:51:25 2013 kevin loiseleur
*/

#include "my.h"

int			my_nblen(int nb)
{
  int			len;
  int			i;

  i = 1;
  len = 1;
  while ((nb / i) > 9)
    {
      i *= 10;
      len++;
    }
  return (len);
}
