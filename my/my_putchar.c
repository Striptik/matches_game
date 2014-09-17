/*
** my_putchar_error.c for putchar error in /home/loisel_k/taff/C/Systeme-Unix/minishell1/my
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Dec 18 15:41:13 2013 Kevin LOISELEUR
** Last update Wed Dec 18 15:51:34 2013 Kevin LOISELEUR
*/

#include "my.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}
