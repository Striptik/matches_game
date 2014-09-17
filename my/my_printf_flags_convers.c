/*
** my_printf_flags_convers.c for Flags de conversion de printf in /home/loisel_k/travail/Systeme-Unix/my_printf/src
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Sat Nov 16 19:01:01 2013 kevin loiseleur
** Last update Sun Nov 17 20:23:53 2013 kevin loiseleur
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "my_printf.h"

int                     fl_b(va_list ap)
{
  int                   returned_value;
  unsigned long int     type;

  type = va_arg(ap, long unsigned int);
  returned_value = my_put_nbr_base_uns(type, "01");
  return (returned_value);
}

int                     fl_o(va_list ap)
{
  int                   returned_value;
  int                   type;

  type = va_arg(ap, unsigned long int);
  returned_value = my_put_nbr_base_uns(type, "01234567");
  return (returned_value);
}

int                     fl_x(va_list ap)
{
  int                   returned_value;
  int                   type;

  type = va_arg(ap, unsigned long int);
  returned_value = my_put_nbr_base_uns(type, "0123456789abcdef");
  return (returned_value);
}

int                     fl_X(va_list ap)
{
  int                   returned_value;
  int                   type;

  type = va_arg(ap, unsigned long int);
  returned_value = my_put_nbr_base_uns(type, "0123456789ABCDEF");
  return (returned_value);
}
