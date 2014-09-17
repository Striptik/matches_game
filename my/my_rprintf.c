/*
** my_printf.c for my_printf in /home/loisel_k/travail/Systeme-Unix
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Tue Nov 12 18:51:16 2013 kevin loiseleur
** Last update Wed Dec 18 16:43:45 2013 Kevin LOISELEUR
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "my_rprintf.h"

static const t_rfptr      g_rflags[NB_FLAGS] =
{
  { 's', &rfl_s },
  { 'c', &rfl_c },
  { 'd', &rfl_d },
  { 'i', &rfl_d },
  { 'b', &rfl_b },
  { 'p', &rfl_p },
  { 'o', &rfl_o },
  { 'u', &rfl_u },
  { 'x', &rfl_x },
  { 'X', &rfl_X },
  { '%', &rfl_percent },
  { 'S', &rfl_S },
};

int			rflag_len_modif(char format)
{
  char			*len_modif;
  int			i;

  i = 0;
  len_modif = " #0123456789-+l.h*";
  while (len_modif[i])
    {
      if (format == len_modif[i])
	return (1);
      i++;
    }
  return (0);
}

int			rgood_flag(char format)
{
  int			j;

  j = 0;
  while (format != g_rflags[j].ident && j != NB_FLAGS)
    g_rflags[j++].ident;
  if (j == NB_FLAGS)
    return (-1);
  return (j);
}

int			rprintf_handler(int i, va_list ap, const char *format)
{
  int			returned_value;
  int			j;

  returned_value = 0;
  while (format && format[i])
    {
      if (format[i] == '%')
	{
	  while ((rflag_len_modif(format[i + 1])) == 1)
	    i++;
	  if ((j = rgood_flag(format[i + 1])) == -1)
	    my_rputchar(format[i]);
	  else
	    {
	      returned_value += g_rflags[j].fptr(ap) - 1;
	      i++;
	    }
	}
      else
	my_rputchar(format[i]);
     returned_value++;
      i++;
    }
  return (returned_value);
}

int		my_rprintf(const char *format, ...)
{
  int		i;
  int		returned_value;
  va_list	ap;

  i = 0;
  returned_value = 0;
  va_start(ap, format);
  if (format == NULL)
    return (-1);
  returned_value = rprintf_handler(i, ap, format);
  va_end(ap);
  return (returned_value);
}
