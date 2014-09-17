/*
** my_swap.c for my_swap in /home/loisel_k/rendu/Piscine-C-lib/my
** 
** Made by loisel_k
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Oct  9 10:05:29 2013 loisel_k
** Last update Wed Oct  9 10:07:16 2013 loisel_k
*/

int		my_swap(int *a, int *b)
{
  int		tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}
