/*
** my_strdup.c for my_strdup in /home/loisel_k/taff/C/Systeme-Unix/minishell1/dl
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Mon Dec 23 16:38:24 2013 Kevin LOISELEUR
** Last update Fri Jan  3 20:58:47 2014 Kevin LOISELEUR
*/

#include "my.h"
#include <stdlib.h>

char			*my_strdup(char *str)
{
  char			*ret;
  int			i;

  i = 0;
  if(!(ret = malloc(sizeof(char) * (my_strlen(str) + 1))))
    {
      my_rprintf("Malloc has shit man !\n");
      return (NULL);
    }
  while (str && str[i])
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = '\0';
  return (ret);
}

char			*my_strndup(char *str, int len)
{
  char			*ret;
  int			i;

  i = 0;
  if (!(ret = malloc(sizeof(char) * len)))
    {
      my_rprintf("Malloc has shit man !\n");
      return (NULL);
    }
  while (str && str[i] && i < len)
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = '\0';
  return (ret);
}
