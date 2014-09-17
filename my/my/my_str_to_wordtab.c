/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/loisel_k/Librairie
** 
** Made by loisel_k
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Oct 23 01:36:01 2013 loisel_k
** Last update Fri Oct 25 20:33:08 2013 loisel_k
*/

#include <stdio.h>
#include <stdlib.h>

int		my_count_tab(char *str)
{
  int		i;
  int		count;

  i = 1;
  count = 1;
  while (str && str[i])
    {
      while ((str[i] <= 'a' || str[i] >= 'z') && (str[i] <= 'A' ||
						  str[i] >='Z'))
	i++;
      count++;
      while ((str[i] <= 'z' && str[i] >= 'a') || (str[i] <= 'Z' &&
						  str[i] >= 'A'))
	i++;
    }
  return (count);
}

int		my_count_char_alph(int i, char *str)
{
  int		len;

  len = 1;
  while ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' &&
					      str[i] <= 'z'))
    {
      i++;
      len++;
    }
  return (len);
}

int		go_to_alpha(int i, char *str)
{
  while ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' ||
					    str[i] >'Z'))
    i++;
  return (i);
}

char		**my_str_to_wordtab(char *str)
{
  char		**tab;
  int		i1;
  int		i;
  int		j;
  char		*tmp;

  j = 0;
  i = 0;
  if ((tab = malloc(my_count_tab(str) * sizeof(*tab))) == NULL)
    return (NULL);
  while (str[i])
    {
      i1 = 0;
      i = go_to_alpha(i, str);
      if ((tmp = malloc(my_count_char_alph(i, str) * sizeof(tmp))) == NULL)
	return (NULL);
      while ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' &&
						  str[i] <= 'Z'))
	  tmp[i1++] = str[i++];
      tmp[i1] = '\0';
      tab[j] = tmp;
      j++;
    }
  tab[j] = NULL;
  return (tab);
}
