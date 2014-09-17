/*
** display.c for display in /home/loisel_k/Taff/C/C-Prog-Elem/B2/Allum1/src
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Sat Feb 15 15:22:51 2014 Kevin LOISELEUR
** Last update Sun Feb 16 22:46:53 2014 Kevin LOISELEUR
*/

#include <stdlib.h>
#include "../include/my.h"
#include "allum1.h"

void			display_game(t_alum *alum)
{
  int			i;
  char			*tmp_line;

  i = 0;
  while (alum->alumtab[i] != END_TAB)
    {
      if ((i + 1) < 10)
	my_printf(" ");
      my_printf("\033[1;35m Ligne [%d] :  \033[00m", (i + 1));
      if (!(tmp_line = malloc(sizeof(char) * (alum->alum_max + 1))))
	{
	  my_printf("Malloc Erreur.\n");
	  exit(1);
 	}
      line_creator(alum, i, tmp_line);
      my_printf("\033[1;33m%s\033[00m  ", tmp_line);
      my_printf("\033[1;35m[%d] allumettes\033[00m\n", alum->alumtab[i]);
      i++;
      free(tmp_line);
    }
  return ;
}

void			line_creator(t_alum *alum, int i, char *tmp)
{
  int			spaces_between;
  int			j;
  int			k;
  int			l;

  j = 0;
  k = 0;
  l = 0;
  spaces_between = (alum->alum_max - alum->alumtab[i]) / 2;
  while (j < spaces_between)
    tmp[j++] = ' ';
  tmp[alum->alum_max] = 0;
  while (k < alum->alumtab[i])
    {
      tmp[j++] = '|';
      k++;
    }
  while (l < spaces_between)
    {
      tmp[j++] = ' ';
      l++;
    }
  tmp[j] = 0;
  return ;
}

void			questions_player(t_alum *alum)
{
  char			*s;
  int			yess;
  int			choice;

  yess = 0;
  while (!yess)
    {
      s = NULL;
      my_printf("\033[1;36m\n\nSur quelle ligne ");
      my_printf("veux-tu retirer des allumettes ?\033[00m\n");
      if (!(my_strncmp((s = get_next_line(0)), "exit", 4)))
	exit(0);
      choice = my_getnbr(s);
      if (choice > 0 && choice <= alum->nb_line &&
	  alum->alumtab[choice - 1] != 0)
	yess = choose_alum(alum, (choice - 1));
      else
 	{
	  my_printf("Mauvais choix. Soit la ligne est vide soit invalide.\n");
	  my_printf("(exit pour quitter)\n\n");
	}
      free(s);
    }
  return ;
}

int			choose_alum(t_alum *alum, int line)
{
  char			*s;
  int			choice;

  my_printf("\n\033[1;34mCombien d'allumettes veux-tu retirer ?\n");
  if (!(my_strncmp((s = get_next_line(0)), "exit", 4)))
    exit(0);
  choice = my_getnbr(s);
  if (choice <= 0 || choice > alum->alumtab[line])
    {
      my_printf("Mauvais choix, tu as mis trop ou pas assez\n");
      my_printf("(exit pour quitter)\n\n");
      free(s);
      return (0);
    }
  alum->alumtab[line] = alum->alumtab[line] - choice;
  my_printf("Tu as retire %d allumettes a la ligne %d\n", choice, (line + 1));
  free(s);
  return (1);
}

void			clean_screen(void)
{
  char			s;

  s = tgetstr("cl", NULL);
  tputs(s, 1, tputchar);
  return ;
}
