/*
** my_strcat.c for my_strcat in /home/loisel_k/rendu/Piscine-C-lib/my
** 
** Made by loisel_k
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Oct  9 12:14:46 2013 loisel_k
** Last update Mon Jan  6 18:55:56 2014 Kevin LOISELEUR
*/

#include <stdlib.h>
#include "my.h"

char		*my_strcat(char *dest, char *src)
{
  int		i;
  int		j;
  char		*ret;
  char		*tmp;

  i = 0;
  j = 0;
  ret = my_realloc(dest, src);
  while (dest && dest[i])
    ret[j++] = dest[i++];
  i = 0;
  while (src && src[i])
    ret[j++] = src[i++];
  ret[j] = 0;
  return (ret);
}
