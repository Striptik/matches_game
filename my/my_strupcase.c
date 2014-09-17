/*
** my_strupcase.c for strupcase in /home/loisel_k/rendu/Piscine-C-lib/my
** 
** Made by loisel_k
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Oct  9 11:41:04 2013 loisel_k
** Last update Tue Nov 12 17:35:55 2013 kevin loiseleur
*/

char		*my_strupcase(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] <= 'z' && str[i] >= 'a')
	str[i] = str[i] - 32;
      i++;
    }
  return (str);
}
