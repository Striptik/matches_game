/*
** init_game.c for init game for allum1 (marinebend game) in /home/loisel_k/Taff/C/C-Prog-Elem/B2/Allum1/src
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Thu Feb 13 20:54:49 2014 Kevin LOISELEUR
** Last update Sun Feb 16 21:23:13 2014 Kevin LOISELEUR
*/

#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include "allum1.h"
#include "../include/my.h"

t_alum			init_game(char **env)
{
  int			mode;
  t_alum		alum;
  char			*term;

  intro_game(&alum);
  if (alum.mode == MOD_BONUS)
    {
      if (term = recup_var_term(env))
	tgetent(NULL, term);
      choose_second_player(&alum);
      choose_nb_line(&alum);
      choose_the_beginner(&alum);
    }
  else
    {
      alum.player_two = PLAY_IA;
      alum.nb_line = 4;
      choose_the_beginner(&alum);
    }
  return (alum);
}

void			intro_game(t_alum *alum)
{
  int			choice;
  int			yess;
  char			*s;

  yess = 0;
  my_printf("Bienvenue dans le Jeu des Allumettes.\n\n");
  while (!yess)
    {
      my_printf("Choisis ton mode :\n");
      my_printf("- Mode texte basique sans bonus (1)\n- Mode Bonus (2)\n\n");
      if (my_strncmp((s = get_next_line(0)), "exit", 4) == 0)
	exit(0);
      choice = my_getnbr(s);
      if (choice == MOD_BASE || choice == MOD_BONUS)
	yess = 1;
      else
	my_printf("Mauvais choix, soit '1' ou '2' ou 'exit'\n");
    }
  alum->mode = choice;
  (choice == MOD_BASE) ? (my_printf(T_MOD_BASE)) : (my_printf(T_MOD_BONUS));
  return ;
}

void			choose_second_player(t_alum *alum)
{
  int			yess;
  int			player;
  char			*s;

  yess = 0;
  while (!yess)
    {
      s = NULL;
      my_printf("\n\nChoisis le deuxieme joueur :\n - IA (1)\n");
      my_printf(" - PvP (2)\n - exit\n\n");
      if ((my_strncmp((s = get_next_line(0)), "exit", 4)) == 0)
	exit(0);
      player = my_getnbr(s);
      if (s == NULL || (player != PLAY_IA && player != PLAY_REAL))
	my_printf("Tu as fais un mauvais choix.\n\n");
      else
	{
	  alum->player_two = player;
	  yess = 1;
	}
      free(s);
    }
  (player == PLAY_IA) ? (my_printf(T_PLAY_IA)) : (my_printf(T_PLAY_REAL));
  return ;
}

void			choose_nb_line(t_alum *alum)
{
  char			*s;
  int			yess;
  int			nb_line;

  yess = 0;
  while (!yess)
    {
      my_printf("\n\nCombien de lignes d'allumettes desires tu ?\n\n");
      if ((my_strncmp((s = get_next_line(0)), "exit", 4)) == 0)
	exit(0);
      if (s == NULL || ((nb_line = my_getnbr(s)) > NB_LINE_MAX)
	  || nb_line < NB_LINE_MIN)
	{
	  my_printf("Tu as choisi un mauvais nombre !\n");
	  my_printf("Tu peux choisir entre 3 et 25 lignes ou 'exit'.\n");
	}
      else
	{
	  alum->nb_line = nb_line;
	  yess = 1;
	}
      free(s);
    }
  my_printf("Tu as choisis %d lignes.\n\n", nb_line);
  return ;
}

void			choose_the_beginner(t_alum *alum)
{
  int			yess;
  int			beginner;
  char			*s;

  yess = 0;
  while (!yess)
    {
      my_printf("Qui commence ?\n\n - J1 (1)\n - J2 ou IA (2)\n ou 'exit'\n");
      if ((my_strncmp((s = get_next_line(0)), "exit", 4)) == 0)
	exit(0);
      if ((beginner = my_getnbr(s)) == BEG_IA_J2 || beginner == BEG_J1)
	{
	  yess = 1;
	  alum->beginner = beginner;
	}
      else
	my_printf("Tu as fait un mauvais choix.\n");
      free(s);
    }
  if (alum->mode == MOD_BONUS)
    tgetstr("cl", NULL);
  return ;
}
