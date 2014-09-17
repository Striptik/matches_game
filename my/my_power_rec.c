/*
** my_power_rec.c for my_power_rec in /home/loisel_k/rendu/Piscine-C-lib/my
** 
** Made by loisel_k
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Oct  9 10:23:12 2013 loisel_k
** Last update Sun Nov 17 21:11:34 2013 kevin loiseleur
*/

int		my_power_rec(int nb, int power)
{
  int		res;

  if (power == 0 && nb == 0)
    return (1);
  else if (power < 0 || nb == 0)
    return (0);
  else if (power == 0)
    return (1);
  power = power - 1;
  res = 1;
  if (power != 0)
    res = my_power_rec(nb, power);
  res = res * nb;
  return (res);
}
