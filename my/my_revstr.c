/*
** my_revstr.c for my_revstr in /home/loisel_k/rendu/Piscine-C-lib/my
** 
** Made by loisel_k
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Oct  9 11:28:42 2013 loisel_k
** Last update Tue Oct 29 12:01:49 2013 loisel_k
*/

char		*my_revstr(char *str)
{
  int		i;
  int		j;
  char		tmp;

  i = (my_strlen(str) - 1);
  j = 0;
  while (i >= j)
    {
      tmp = str[i];
      str[i] = str[j];
      str[j] = tmp;
      i--;
      j++;
    }
  str[j] = '\0';
  return (str);
}
