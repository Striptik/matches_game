/*
** flag_char.c for Flags de charactere in /home/loisel_k/travail/Systeme-Unix/my_printf/src
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Sat Nov 16 18:45:31 2013 kevin loiseleur
** Last update Sun Nov 17 21:08:39 2013 kevin loiseleur
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "my_printf.h"

int                     fl_c(va_list ap)
{
  int                   returned_value;
  char                  type;

  returned_value = 1;
  type = va_arg(ap, int);
  my_putchar(type);
  return (returned_value);
}

int                     fl_s(va_list ap)
{
  int                   returned_value;
  char                  *type;
  int                   i;

  i = 0;
  returned_value = 0;
  type = va_arg(ap, char *);
  if (type == NULL)
    {
      my_putstr("(null)");
      returned_value = 6;
    }
  else
    {
      while (type && type[i])
        {
          my_putchar(type[i++]);
          ++returned_value;
        }
    }
  return (returned_value);
}

int                     fl_S(va_list ap)
{
  int                   returned_value;
  char                  *type;
  int                   i;

  i = 0;
  type = va_arg(ap, char *);
  while (type && type[i])
    {
      if (type[i] > 32 && type[i] <= 127)
        my_putchar(type[i]);
      else
        {
          my_putchar('\\');
          my_putchar('0');
          returned_value += 2 + my_put_nbr_base_uns(type[i], "01234567");
        }
      returned_value++;
      i++;
    }
  return (returned_value);
}

int                     fl_percent(va_list ap)
{
  int                   returned_value;

  returned_value = 1;
  my_putchar('%');
  return (returned_value);
}

int                     fl_p(va_list ap)
{
  int                   returned_value;
  unsigned long int     type;

  returned_value = 0;
  type = va_arg(ap, unsigned long int);
  if (type == 0)
    {
      my_putstr("(nil)");
      returned_value = 5;
    }
  else
    {
      my_putstr("0x");
      returned_value += 2 + my_put_nbr_base_uns(type, "0123456789abcdef");
    }
  return (returned_value);
}
