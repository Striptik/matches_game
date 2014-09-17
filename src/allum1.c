/*
** allum1.c for allum1 in /home/loisel_k/Taff/C/C-Prog-Elem/B2/Allum1
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Tue Feb  4 23:49:31 2014 Kevin LOISELEUR
** Last update Tue Feb 18 12:50:43 2014 Kevin LOISELEUR
*/

#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include "../include/my.h"
#include "allum1.h"

/*
** Ajouter des couleurs pour l'affichage
*/

void			gere_display_exec(t_alum *alum)
{
  int			i;
  int			player;
  int			yess;

  yess = 0;
  clean_screen();
  my_printf("\t\t\033[1;4;31m JEU DES ALLUMETTES (Marienbad)\033[00m\n\n\n");
  (alum->beginner == BEG_IA_J2) ? (player = J_2) : (player = J_1);
  while (!yess)
    {
      if (player == 1 || (player == 2 && alum->player_two != PLAY_IA))
	{
	  display_game(alum);
	  my_printf("\n\n\033[1;4;32m A Joueur %d de jouer :\033[00m\n", player);
	}
      exec_game(alum, player);
      yess = check_game(alum, &player);
      if (alum->mode == MOD_BONUS && !yess)
	clean_screen();
    }
  return ;
}

void			exec_game(t_alum *alum, int player)
{
  int			yess;

  yess = 0;
  if (player == J_2 && alum->player_two == PLAY_IA)
    gere_ia(alum);
  else
    questions_player(alum);
  return ;
}

int			check_game(t_alum *alum, int *player)
{
  int			i;
  int			yess;

  i = 0;
  yess = 0;
  while (!yess && alum->alumtab[i] != END_TAB)
    {
      if (alum->alumtab[i])
	yess = 1;
      i++;
    }
  if (yess == 1)
    {
      (player[0] == J_1) ? (player[0] = J_2) : (player[0] = J_1);
      return (0);
    }
  clean_screen();
  my_printf("\033[1;4;31m LE JOUEUR %d A PERDU !!\n", player[0]);
  my_printf("Bien joue !!\033[00m\n\n\n");
  return (1);
}

int			main(int ac, char **av, char **env)
{
  t_alum		alum;

  alum = init_game(env);
  init_alum(&alum);
  gere_display_exec(&alum);
  return (0);
}
