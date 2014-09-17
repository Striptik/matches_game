/*
** my_put_nbr.c for my_put_nbr in /home/loisel_k/rendu/Piscine-C-lib/my
** 
** Made by loisel_k
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Oct  9 09:46:14 2013 loisel_k
** Last update Wed Oct  9 10:01:47 2013 loisel_k
*/

int		my_put_nbr(int nb)
{
  int		nbd;

  nbd = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  while (nb / nbd > 9)
    nbd = nbd * 10;
  while (nbd > 0)
    {
      my_putchar('0' + (nb / nbd));
      nb = nb % nbd;
      nbd = nbd / 10;
    }
}
