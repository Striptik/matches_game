/*
** my_isneg.c for my_isneg in /home/loisel_k/rendu/Piscine-C-lib/my
** 
** Made by loisel_k
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Oct  9 09:44:21 2013 loisel_k
** Last update Wed Oct  9 09:45:49 2013 loisel_k
*/

int		my_isneg(int nb)
{
  if (nb >= 0)
    my_putchar('P');
  else
    my_putchar('N');
}
