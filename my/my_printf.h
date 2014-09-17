/*
** my_printf.h for my_printf.h in /home/loisel_k/travail/Systeme-Unix
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Tue Nov 12 14:26:41 2013 kevin loiseleur
** Last update Mon Dec 23 14:30:52 2013 Kevin LOISELEUR
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

#include <stdarg.h>

#define NB_FLAGS	13

typedef struct		s_fptr
{
  char			ident;
  int (*fptr)		(va_list ap);
}			t_fptr;

int			good_flags(char format);
int			my_printf(const char *format, ...);
int			printf_handler(int i, va_list ap, const char *format);
int			fl_s(va_list ap);
int			fl_c(va_list ap);
int			fl_d(va_list ap);
int			fl_b(va_list ap);
int			fl_p(va_list ap);
int			fl_o(va_list ap);
int			fl_u(va_list ap);
int			fl_o(va_list ap);
int			fl_x(va_list ap);
int			fl_X(va_list ap);
int			fl_percent(va_list ap);
int			fl_S(va_list ap);

static const t_fptr		g_flags[NB_FLAGS];

#endif /* MY_PRINTF_H_ */
