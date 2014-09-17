/*
** my_strcpy.c for my_strcpy in /home/loisel_k/rendu/Piscine-C-lib/my
** 
** Made by loisel_k
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Oct  9 10:38:22 2013 loisel_k
** Last update Tue Oct 29 11:58:02 2013 loisel_k
*/

#include <stdio.h>

char		*my_strcpy(char *dest, char *src)
{
  int		i;

  i = 0;
  if (src == NULL || dest == NULL)
    return (NULL);
  while (src[i] != '\0')
    dest[i] = src[i++];
  dest[i] = '\0';
  return (dest);
}
