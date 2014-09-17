/*
** my_putstr.c for my_putstr.c in /home/loisel_k/rendu/Piscine-C-lib/my
** 
** Made by loisel_k
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Oct  9 10:08:19 2013 loisel_k
** Last update Wed Dec 18 16:03:37 2013 Kevin LOISELEUR
*/

int		my_rputstr(char *str)
{
  int		i;

  i = 0;
  while (str && str[i])
    my_rputchar(str[i++]);
  return (0);
}
