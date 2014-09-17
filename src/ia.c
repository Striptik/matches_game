/*
** ia.c for IA for alum in /home/loisel_k/Taff/C/C-Prog-Elem/B2/Allum1/src
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Sun Feb 16 14:01:03 2014 Kevin LOISELEUR
** Last update Sun Feb 16 20:02:18 2014 Kevin LOISELEUR
*/

#include <stdlib.h>
#include "../include/my.h"
#include "allum1.h"

void			gere_ia(t_alum *alum)
{
  int			activ_line;

  activ_line = check_line(alum);
  if (activ_line > 3)
    ia_easy(alum, activ_line);
  else
    more_difficult(alum, activ_line);
  return ;
}

int			check_line(t_alum *alum)
{
  int			count;
  int			i;

  i = 0;
  count  = 0;
  while (alum->alumtab[i] != END_TAB)
    {
      if (alum->alumtab[i])
	count++;
      i++;
    }
  return (count);
}

void			ia_easy(t_alum *alum, int activ_line)
{
  int			i;
  int			yess;

  i = 0;
  yess = 0;
  while (alum->alumtab[i] != END_TAB && !yess)
    {
      if (alum->alumtab[i] && alum->alumtab[i] > 2)
	{
	  if ((activ_line % 2) == 0)
	    alum->alumtab[i] = 0;
	  else
	    alum->alumtab[i] = 1;
	  yess = 1;
	}
      i++;
    }
  (alum->alumtab[i] == END_TAB) ? (i = 0) : (yess = 2);
  if (yess == 2)
    return ;
  while (alum->alumtab[i] == 0)
    i++;
  (alum->alumtab[i] == 1) ? (alum->alumtab[i] = 0) : (alum->alumtab[i] = 1);
  return ;
}

int			*analyse_game(t_alum *alum)
{
  int			*tab;
  int			i;
  int			j;

  i = 0;
  j = 0;
  if (!(tab = malloc(sizeof(int) * 4)))
    return (NULL);
  while (alum->alumtab[i] != END_TAB)
    {
      if (alum->alumtab[i])
	tab[j++] = alum->alumtab[i];
      i++;
    }
  tab[j] = END_TAB;
  return (tab);
}
