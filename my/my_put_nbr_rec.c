/*
** my_put_nbr_rec.c for my_put_nbr_rec.c in /home/loisel_k/rendu/Piscine-C-lib/my
** 
** Made by loisel_k
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Oct  9 09:56:41 2013 loisel_k
** Last update Sat Nov 16 16:54:59 2013 kevin loiseleur
*/

int		my_put_nbr_rec(int nb)
{
  int		ret;

  ret = 0;
  if (nb <= -2147483648)
    {
      my_putstr("-2147483648");
      ret = 11;
    }
  else
    {
      if (nb < 0)
	{
	  my_putchar('-');
	  nb = -nb;
	  ret++;
	}
      if (nb / 10 != 0)
	ret += my_put_nbr_rec(nb / 10);
      ret++;
      my_putchar('0' + (nb % 10));
    }
  return (ret);
}
