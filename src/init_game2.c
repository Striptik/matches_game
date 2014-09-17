/*
** init_game2.c for init the game suit in /home/loisel_k/Taff/C/C-Prog-Elem/B2/Allum1/src
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Sat Feb 15 15:26:59 2014 Kevin LOISELEUR
** Last update Sun Feb 16 22:44:24 2014 Kevin LOISELEUR
*/

#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include "../include/my.h"
#include "allum1.h"

void			init_alum(t_alum *alum)
{
  int			size;

  size = alum->nb_line;
  if (!(alum->alumtab = malloc(sizeof(int) * (size + 1))))
    {
      my_rprintf("Erreur Malloc tableau allumette.\n");
      exit(1);
    }
  alum->alumtab[size] = END_TAB;
  fulfill_alumtab(alum);
  alum->alum_max = alum->alumtab[size - 1];
  return ;
}

void			fulfill_alumtab(t_alum *alum)
{
  int			nb_alum;
  int			total;
  int			nb_line;

  nb_alum = 1;
  total = 1;
  nb_line = 0;
  while (nb_line < alum->nb_line)
    {
      alum->alumtab[nb_line] = nb_alum;
      nb_alum = nb_alum + 2;
      total = total + nb_alum;
      nb_line++;
    }
  alum->total = total;
  return ;
}

char			*recup_var_term(char **env)
{
  int			i;
  int			j;
  char			*s;
  int			len;
  int			k;

  i = 0;
  j = 0;
  k = 0;
  while (env[i])
    {
      if (my_strncmp(env[i], "TERM=", 5) == 0)
	{
	  len = my_strlen(env[i]) - 5;
	  if (s = malloc(sizeof(char) * len))
	    return (NULL);
	  while (env[i][j] != '=')
	    j++;
	  while (env[i][j])
	    s[k++] = env[i][j++];
	  s[k] = 0;
	  return (s);
	}
      i++;
    }
}

int			tputchar(int c)
{
  write(1, &c, 1);
  return (0);
}
