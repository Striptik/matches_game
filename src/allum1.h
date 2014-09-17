/*
** allum1.h for header for allum1 in /home/loisel_k/Taff/C/C-Prog-Elem/B2/Allum1/src
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Tue Feb  4 23:50:12 2014 Kevin LOISELEUR
** Last update Sun Feb 16 22:48:19 2014 Kevin LOISELEUR
*/

#ifndef _ALLUM1_H_
# define _ALLUM1_H_

typedef struct		s_alum
{
  int			*alumtab;
  int			total;
  int			nb_line;
  int			mode;
  int			player_two;
  int			beginner;
  int			alum_max;
}			t_alum;


# define MOD_BASE	1
# define MOD_BONUS	2
# define T_MOD_BASE	"Tu as choisi le mode basique.\n"
# define T_MOD_BONUS	"Tu as choisi le mode bonus.\n"
# define NB_LINE_MIN	3
# define NB_LINE_MAX	25
# define PLAY_IA	1
# define PLAY_REAL	2
# define T_PLAY_IA	"Tu vas jouer contre moi, et perdre ...\n"
# define T_PLAY_REAL	"Jouez tour par tour.\n"
# define BEG_IA_J2	2
# define BEG_J1		1
# define END_TAB	-10
# define J_1		1
# define J_2		2

/*
** Game's init
*/

t_alum			init_game(char **env);
void			intro_game(t_alum *alum);
void			choose_nb_line(t_alum *alum);
void			choose_second_player(t_alum *alum);
void			choose_the_beginner(t_alum *alum);
void			init_alum(t_alum *alum);
void			fulfill_alumtab(t_alum *alum);
char			*recup_var_term(char **env);

/*
** Exec & Display game
*/

void			gere_display_exec(t_alum *alum);
void			exec_game(t_alum *alum, int player);
void			questions_player(t_alum *alum);
int			choose_alum(t_alum *alum, int line);
void			display_game(t_alum *alum);
void			line_creator(t_alum *alum, int i, char *tmp);
int			check_game(t_alum *alum, int *player);
void			clean_screen(void);
int			tputchar(int);

/*
** IA
*/

void			gere_ia(t_alum *alum);
int			check_line(t_alum *alum);
void			ia_easy(t_alum *alum, int activ_line);
int			*analyse_game(t_alum *alum);
void			more_difficult(t_alum *alum, int activ_line);
void			two_lines(t_alum *alum, int *);
void			two_lines_bis(t_alum *alum);
void			three_lines(t_alum *alum, int *);
void			fuck_norm(t_alum *alum, int *);

#endif /* _ALLUM1_H_ */
