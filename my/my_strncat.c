/*
** my_strncat.c for my_strncat in /home/loisel_k/rendu/Piscine-C-lib/my
** 
** Made by loisel_k
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Oct  9 12:16:29 2013 loisel_k
** Last update Thu Jan  9 16:21:25 2014 Kevin LOISELEUR
*/
#include <stdlib.h>
#include "my.h"

/*
** Difference avec le vrai strncat: creation d'un poimteur plutot que de modifier
** 'dest'. Il y a donc un pointeur de plus a free.
*/

char		*my_strncat(char *dest, char *src, int nb)
{
  int		i;
  int		j;
  char		*ret;

  i = 0;
  j = 0;
  if (!dest || !src)
    {
      my_rprintf("Src or(and) Dest is(are) empty(ies)! (my_strncat)\n");
      return (NULL);
    }
  if (!(ret = malloc(sizeof(char) * (my_strlen(dest) + nb + 1))))
    {
      my_rprintf("Error Malloc ! (my_strncat)");
      return (NULL);
    }
  while (dest[i])
    ret[j++] = dest[i++];
  i = 0;
  while (src[i] && i < nb)
    ret[j++] = src[i++];
  ret[j] = 0;
  return (ret);
}
