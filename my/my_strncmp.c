/*
** my_strncmp.c for my_strncmp in /home/loisel_k/rendu/Piscine-C-lib/my
** 
** Made by loisel_k
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Oct  9 11:39:29 2013 loisel_k
** Last update Sat Nov  9 03:12:01 2013 kevin loiseleur
*/

int		my_strncmp(char *s1, char *s2, int nb)
{
  int		i;
  int		j;
  int		count;

  i = 0;
  j = 0;
  while ((s1[i] || s2[i]) && i < nb)
    {
      if (s1[i] < s2[i])
	return (-1);
      if (s1[i] > s2[i])
	return (1);
      i++;
    }
  if ((s1[i] < s2[i]) && i < nb)
    return (1);
  if ((s1[i] > s2[i]) && i < nb)
    return (1);
  return (0);
}
