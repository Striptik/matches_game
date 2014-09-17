/*
** my_strcmp.c for my_strcmp in /home/loisel_k/rendu/Piscine-C-lib/my
** 
** Made by loisel_k
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Oct  9 11:37:44 2013 loisel_k
** Last update Thu Feb 13 00:48:14 2014 Kevin LOISELEUR
*/

#include <stdio.h>
#include "my.h"

int		my_strcmp(char *s1, char *s2)
{
  int		i;
  int		j;
  int		count;

  i = 0;
  if (s1 && !s2)
    {
      while (s1[i])
	{
	  if (s1[i] < s2[i])
	    return (-1);
	  if (s1[i] > s2[i])
	    return (1);
	  i++;
	}
      if (s1[i] < s2[i])
	return (-1);
      if (s1[i] > s2[i])
	return (1);
      return (0);
    }
  return (-1);
}
