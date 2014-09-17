/*
** my_put_nbr_base.c for my_put_nbr_base in /home/loisel_k/travail/Librairie/my
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Tue Nov 12 17:28:30 2013 kevin loiseleur
** Last update Thu Nov 14 20:04:38 2013 kevin loiseleur
*/

#include "my.h"

int		my_put_nbr_base(int nb, char *base)
{
  int		i;
  int		len;
  int		nb_len;

  i = 0;
  nb_len = 0;
  len = my_strlen(base);
  if (nb < 0)
    {
      my_putchar('-');
      nb *= -1;
    }
  i = nb % len;
  nb = nb / len;
  if (nb > 0)
    nb_len = nb_len + my_put_nbr_base(nb, base);
  my_putchar(base[i]);
  nb_len++;
  return (nb_len);
}

int		my_put_nbr_base_uns(long unsigned int nb, char *base)
{
  int		len;
  int		i;
  int		nb_len;
  
  i = 0;
  nb_len = 0;
  len = my_strlen(base);
  if (nb < 0)
    {
      my_putchar('-');
      nb *= -1;
    }
  i = nb % len;
  nb = nb / len;
  if (nb > 0)
    nb_len = nb_len + my_put_nbr_base_uns(nb, base);
  my_putchar(base[i]);
  nb_len++;
  return (nb_len);
}
