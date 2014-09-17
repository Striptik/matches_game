/*
** flag_char.c for Flags de charactere in /home/loisel_k/travail/Systeme-Unix/my_printf/src
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Sat Nov 16 18:45:31 2013 kevin loiseleur
** Last update Wed Dec 18 17:00:50 2013 Kevin LOISELEUR
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "my_rprintf.h"

int                     rfl_c(va_list ap)
{
  int                   returned_value;
  char                  type;

  returned_value = 1;
  type = va_arg(ap, int);
  my_rputchar(type);
  return (returned_value);
}

int                     rfl_s(va_list ap)
{
  int                   returned_value;
  char                  *type;
  int                   i;

  i = 0;
  returned_value = 0;
  type = va_arg(ap, char *);
  if (type == NULL)
    {
      my_rputstr("(null)");
      returned_value = 6;
    }
  else
    {
      while (type && type[i])
        {
          my_rputchar(type[i++]);
          ++returned_value;
        }
    }
  return (returned_value);
}

int                     rfl_S(va_list ap)
{
  int                   returned_value;
  char                  *type;
  int                   i;

  i = 0;
  type = va_arg(ap, char *);
  while (type && type[i])
    {
      if (type[i] > 32 && type[i] <= 127)
        my_rputchar(type[i]);
      else
        {
          my_rputchar('\\');
          my_rputchar('0');
          returned_value += 2 + my_rput_nbr_base_uns(type[i], "01234567");
        }
      returned_value++;
      i++;
    }
  return (returned_value);
}

int                     rfl_percent(va_list ap)
{
  int                   returned_value;

  returned_value = 1;
  my_rputchar('%');
  return (returned_value);
}

int                     rfl_p(va_list ap)
{
  int                   returned_value;
  unsigned long int     type;

  returned_value = 0;
  type = va_arg(ap, unsigned long int);
  if (type == 0)
    {
      my_rputstr("(nil)");
      returned_value = 5;
    }
  else
    {
      my_rputstr("0x");
      returned_value += 2 + my_rput_nbr_base_uns(type, "0123456789abcdef");
    }
  return (returned_value);
}
