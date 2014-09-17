/*
** my_find_prime_sup.c for my_find_prime_sup in /home/loisel_k/rendu/Piscine-C-lib/my
** 
** Made by loisel_k
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Oct  9 10:36:51 2013 loisel_k
** Last update Tue Oct 29 11:53:43 2013 loisel_k
*/

int		my_find_prime_sup(int nb)
{
  int		sup;

  while ((sup = my_is_prime(nb)) == 0)
    nb++;
  return (nb);
}
