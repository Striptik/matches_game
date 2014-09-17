/*
** my_getnbr.c for my_getnbr in /home/loisel_k/rendu/Piscine-C-lib/my
** 
** Made by loisel_k
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Oct  9 10:13:49 2013 loisel_k
** Last update Sun Oct 27 16:06:18 2013 loisel_k
*/

int		check_nbr_sign(char *str)
{
  int		i;
  int		count_less;

  i = 0;
  count_less = 0;
  while (str && (str[i] == '-') || (str[i] == '+'))
    {
      if (str[i] == '-')
	count_less++;
      i++;
    }
  if (str[i] <= '9' && str[i] >= '0')
    return (count_less);
  else
    return (-1);
}

int		power_ten(int ten, int power)
{
  int		i;
  int		result;

  i = 1;
  result = 1;
  while (i < power)
    {
      result = result * ten;
      i++;
    }
  return (result);
}

int		my_calc_char_int(int i, int mult, int result, char *str)
{
  while (str[i] >= '0' && str[i] <= '9')
    {
      result = result + ((str[i] - '0') * mult);
      mult = mult / 10;
      i++;
    }
  return (result);
}

int		my_getnbr(char *str)
{
  int		i;
  int		j;
  int		result;
  int		mult;
  int		less;

  i = 0;
  j = 0;
  result = 0;
  if ((less = check_nbr_sign(str)) < 0)
    return (0);
  while ((str[i] == '-') || (str[i] == '+'))
    i++;
  while (str[i] >= '0' && str[i] <= '9')
    {
      j++;
      i++;
    }
  i = i - j;
  mult = power_ten(10, j);
  result = my_calc_char_int(i, mult, result, str);
  if (less % 2 == 1)
    result *= -1;
  return (result);
}
