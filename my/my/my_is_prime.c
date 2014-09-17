/*
** my_is_prime.c for my_is_prime in /home/loisel_k/rendu/Piscine-C-lib/my
** 
** Made by loisel_k
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Oct  9 10:35:05 2013 loisel_k
** Last update Tue Oct 29 11:43:52 2013 loisel_k
*/

int		my_is_prime(int nombre)
{
  int		i;
  
  i = 2;
  if (nombre == 0 || nombre == 1)
    return (0);
  while (i < nombre)
    {
      if ((nombre % i) == 0)
	return (0);
      i++;
    }
  return (1);
}
