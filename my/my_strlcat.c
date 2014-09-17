/*
** my_strlcat.c for my_strlcat in /home/loisel_k/rendu/Piscine-C-lib/my
** 
** Made by loisel_k
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Oct  9 12:17:46 2013 loisel_k
** Last update Thu Jan  9 16:21:23 2014 Kevin LOISELEUR
*/

int		my_strlcat(char *dest, char *src, int size)
{
  int		i;
  int		j;
  int		len_dest;
  int		len_src;

  i = 0;
  j = 0;
  while (dest[i])
    i++;
  dest[i] = *(&src[j]);
  while (src[j] && j < size)
    j++;
  src[j] = 0;
  if (size >= len_src)
    return (len_dest + len_src);
  else
    return (len_dest + size);
}
