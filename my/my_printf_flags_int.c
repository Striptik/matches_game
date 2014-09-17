/*
** my_printf_flags_int.c for flags int pour printf in /home/loisel_k/travail/Systeme-Unix/my_printf/src
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Sat Nov 16 19:11:34 2013 kevin loiseleur
** Last update Wed Dec 18 16:36:24 2013 Kevin LOISELEUR
*/

#include <stdarg.h>
#include "my.h"
#include "my_printf.h"

int                     fl_d(va_list ap)
{
  int                   returned_value;
  int                   type;

  type = va_arg(ap, int);
  returned_value = my_put_nbr_rec(type);
  return (returned_value);
}

int                     fl_u(va_list ap)
{
  int                   returned_value;
  int                   type;

  type = va_arg(ap, unsigned long int);
  returned_value = my_put_nbr_base_uns(type, "0123456789");
  return (returned_value);
}
