/*
** my_printf.h for my_printf.h in /home/loisel_k/travail/Systeme-Unix
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Tue Nov 12 14:26:41 2013 kevin loiseleur
** Last update Wed Dec 18 16:49:25 2013 Kevin LOISELEUR
*/

#ifndef MY_RPRINTF_H_
# define MY_RPRINTF_H_

#define NB_FLAGS	13

#include <stdarg.h>

typedef struct		s_rfptr
{
  char			ident;
  int (*fptr)		(va_list ap);
}			t_rfptr;

int			rgood_flags(char format);
int			rmy_printf(const char *format, ...);
int			rprintf_handler(int i, va_list ap, const char *format);
int			rfl_s(va_list ap);
int			rfl_c(va_list ap);
int			rfl_d(va_list ap);
int			rfl_b(va_list ap);
int			rfl_p(va_list ap);
int			rfl_o(va_list ap);
int			rfl_u(va_list ap);
int			rfl_o(va_list ap);
int			rfl_x(va_list ap);
int			rfl_X(va_list ap);
int			rfl_percent(va_list ap);
int			rfl_S(va_list ap);

static const t_rfptr		g_rflags[NB_FLAGS];

#endif /* MY_PRINTF_H_ */
