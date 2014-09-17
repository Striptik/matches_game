/*
** ia2.c for ia2 in /home/loisel_k/Taff/C/C-Prog-Elem/B2/Allum1/src
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Sun Feb 16 19:59:43 2014 Kevin LOISELEUR
** Last update Sun Feb 16 21:52:57 2014 Kevin LOISELEUR
*/

#include "allum1.h"
#include "../include/my.h"

void			more_difficult(t_alum *alum, int activ_line)
{
  int			i;
  int			*tab;

  i = 0;
  tab = analyse_game(alum);
  if (activ_line == 3)
    three_lines(alum, tab);
  else if (activ_line == 2)
    two_lines(alum, tab);
  else
    {
      while (alum->alumtab[i] == 0)
	i++;
      if (alum->alumtab[i] == 1)
	alum->alumtab[i] = 0;
      else
	alum->alumtab[i] = 1;
    }
  return ;
}

void			two_lines(t_alum *alum, int *tab)
{
  int			i;

  i = 0;
  if (tab[0] == 1 && tab[1] == 1)
    {
      while (alum->alumtab[i] == 0)
	(alum->alumtab[i] == 0) ? (i++) : (alum->alumtab[i] = 0);
    }
  else if (tab[0] == 1 || tab[1] == 1)
    {
      while (((alum->alumtab[i]) == 1) || (((alum->alumtab[i]) % 2 == 0) &&
					   (alum->alumtab[i] == 0)))
	i++;
      alum->alumtab[i] = 0;
    }
  else if (((tab[0] % 2) == 1) && ((tab[1] % 2) == 0) ||
	   ((tab[0] % 2) == 0) && ((tab[1] % 2) == 1))
    {
      while ((alum->alumtab[i] % 2) != 1)
	i++;
      alum->alumtab[i] = (alum->alumtab[i] - 1);
    }
  else
    two_lines_bis(alum);
  return ;
}

void			two_lines_bis(t_alum *alum)
{
  int			i;

  i = 0;
  while (alum->alumtab[i] == 0 || alum->alumtab[i] == 1)
    i++;
  if (((alum->alumtab[i] % 2) == 0) && (alum->alumtab[i] != 2))
    alum->alumtab[i] = (alum->alumtab[i] - 2);
  else
    alum->alumtab[i] = (alum->alumtab[i] - 1);
}

void			three_lines(t_alum *alum, int *tab)
{
  int			i;

  i = 0;
  if ((((tab[0] % 2) == 1) && ((tab[1] % 2) == 0) && ((tab[2] % 2) == 0)) ||
      (((tab[1] % 2) == 1) && ((tab[0] % 2) == 0) && ((tab[2] % 2) == 0)) ||
      (((tab[2] % 2) == 1) && ((tab[0] % 2) == 0) && ((tab[1] % 2) == 0)))
    {
      while ((alum->alumtab[i] % 2) != 1)
	i++;
      alum->alumtab[i] = 0;
    }
  else if (((tab[0] % 2 == 1) && ((tab[1] % 2) == 1) && ((tab[2] % 2) == 0)) ||
	   ((tab[1] % 2 == 1) && ((tab[0] % 2) == 1) && ((tab[2] % 2) == 0)) ||
	   ((tab[2] % 2 == 1) && ((tab[0] % 2) == 1) && ((tab[1] % 2) == 0)))
    {
      while ((((alum->alumtab[i] % 2) == 0) && (alum->alumtab[i] == 0)) ||
	     ((alum->alumtab[i] % 2) == 1))
	i++;
      alum->alumtab[i] = 1;
    }
  else
    fuck_norm(alum, tab);
  return ;
}

void			fuck_norm(t_alum *alum, int *tab)
{
  int			i;
  int			yess;

  i = 0;
  if (tab[0] == 1 && tab[1] == 1 && tab[2] == 1)
    yess = 1;
  if (yess)
    {
      while (!alum->alumtab[i])
	i++;
      alum->alumtab[i] = 0;
    }
  else
    {
      while ((alum->alumtab[i] == 0) || (alum->alumtab[i] == 1))
	i++;
      alum->alumtab[i] = 1;
    }
  return ;
}
