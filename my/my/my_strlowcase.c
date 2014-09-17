/*
** my_strlowcase.c for my_strlowcase in /home/loisel_k/rendu/Piscine-C-lib/my
** 
** Made by loisel_k
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Oct  9 11:42:09 2013 loisel_k
** Last update Tue Oct 29 17:45:48 2013 loisel_k
*/

char		*my_strlowcase(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	str[i] = str[i] + 32;
      i++;
    }
  return (str);
}
