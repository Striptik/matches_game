/*
** my_printf.c for my_printf in /home/loisel_k/travail/Systeme-Unix
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Tue Nov 12 18:51:16 2013 kevin loiseleur
** Last update Sun Nov 17 21:05:40 2013 kevin loiseleur
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "my_printf.h"

static const t_fptr      g_flags[NB_FLAGS] =
{
  { 's', &fl_s },
  { 'c', &fl_c },
  { 'd', &fl_d },
  { 'i', &fl_d },
  { 'b', &fl_b },
  { 'p', &fl_p },
  { 'o', &fl_o },
  { 'u', &fl_u },
  { 'x', &fl_x },
  { 'X', &fl_X },
  { '%', &fl_percent },
  { 'S', &fl_S },
};

int			flag_len_modif(char format)
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

int			good_flag(char format)
{
  int			j;

  j = 0;
  while (format != g_flags[j].ident && j != NB_FLAGS)
    g_flags[j++].ident;
  if (j == NB_FLAGS)
    return (-1);
  return (j);
}

int			printf_handler(int i, va_list ap, const char *format)
{
  int			returned_value;
  int			j;

  returned_value = 0;
  while (format && format[i])
    {
      if (format[i] == '%')
	{
	  while ((flag_len_modif(format[i + 1])) == 1)
	    i++;
	  if ((j = good_flag(format[i + 1])) == -1)
	    my_putchar(format[i]);
	  else
	    {
	      returned_value += g_flags[j].fptr(ap) - 1;
	      i++;
	    }
	}
      else
	my_putchar(format[i]);
     returned_value++;
      i++;
    }
  return (returned_value);
}

int		my_printf(const char *format, ...)
{
  int		i;
  int		returned_value;
  va_list	ap;

  i = 0;
  returned_value = 0;
  va_start(ap, format);
  if (format == NULL)
    return (-1);
  returned_value = printf_handler(i, ap, format);
  va_end(ap);
  return (returned_value);
}
