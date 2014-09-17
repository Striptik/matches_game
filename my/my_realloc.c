/*
** my_realloc.c for my_realloc in /home/loisel_k/taff/C/Systeme-Unix/minishell1/include
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Dec 18 15:08:57 2013 Kevin LOISELEUR
** Last update Mon Jan  6 18:41:40 2014 Kevin LOISELEUR
*/

#include <stdlib.h>
#include "my.h"

char		*my_realloc(char *s1, char *s2)
{
  int		len;
  char		*ret;

  ret = NULL;
  len = (my_strlen(s1) + my_strlen(s2) + 1);
  ret = malloc(sizeof(char) * (len + 1));
  return (ret);
}
