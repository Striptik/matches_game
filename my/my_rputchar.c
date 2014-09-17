/*
** my_putchar_error.c for putchar error in /home/loisel_k/taff/C/Systeme-Unix/minishell1/my
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Dec 18 15:41:13 2013 Kevin LOISELEUR
** Last update Wed Dec 18 15:51:18 2013 Kevin LOISELEUR
*/

#include "my.h"

void		my_rputchar(char c)
{
  write(2, &c, 1);
}
