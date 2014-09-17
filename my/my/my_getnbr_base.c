/*
** my_getnbr_base.c for  in /home/loisel_k/travail/Librairie/my
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Sat Nov  9 03:31:42 2013 kevin loiseleur
** Last update Sat Nov  9 10:56:40 2013 kevin loiseleur
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int			check_base(char car, char *base)
{
  int			i;

  if (base && car == base[0])
    return (0);
  i = 0;
  while (base && base[i])
    {
      if (car == base[i])
	return (i);
      i++;
    }
  if (i == 0)
    return (-1);
  else
    return (i);
}

int			calc_nbr(char *str, int i, char *base, int len)
{
  int			i_base;
  int			result;
  int			exp;
  int			j;

  exp = 0;
  result = 0;
  j = i;
  while (str && str[j + 1] && check_base(str[j + 1], base) != -1)
    j++;
  while (str && str[j] && j >= i)
    {
      if (214783647 - result <= my_power_rec(len, exp))
	exit(3);
      i_base = check_base(str[j], base);
      result = result + (i_base * my_power_rec(len, exp));
      j--;
      exp++;
    }
  return (result);
}

char			check_sign(char *str, int len, char *base)
{
  int			i;

  i = 0;
  while (str && str[i] && (str[i] == '+' || str[i] == '-'))
    i++;
  while (str && str[i] && check_base(str[i], base) >= 0)
    i++;
  if (i > 10)
    exit(EXIT_FAILURE);
}

char			sign_base(char *str, int *i)
{
  int			count;

  count = 0;
  while (str && str[*i] == '-' || str[*i] == '+')
    {
      if (str[*i] == '-')
	count++;
      (*i)++;
    }
  if ((count % 2)== 0)
    return ('+');
  else
    return ('-');
}

int			my_getnbr_base(char *str, char *base)
{
  int			result;
  int			i;
  int			len;
  char			sign;

  i = 0;
  result = 0;
  sign ='+';
  if (str && base)
    {
      len = my_strlen(base);
      check_sign(str, len, base);
      if (str[i] == '-' || str[i] == '+')
	sign = sign_base(str, &i);
      if (check_base(str[i], base) == -1)
	return (-1);
      result = calc_nbr(str, i, base, len);
      if (sign == '-')
	result = -result;
      return (result);
    }
  else
    return (-1);
}

int			main(int ac, char **av)
{
  printf("%d\n", my_getnbr_base(av[2], av[1]));
}
