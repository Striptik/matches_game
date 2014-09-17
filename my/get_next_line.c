/*
** get_next_line.c for get_next_line in /home/loisel_k/Taff/C/C-Prog-Elem/B2/Allum1/src
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Thu Feb 13 10:20:58 2014 Kevin LOISELEUR
** Last update Thu Feb 13 20:31:05 2014 Kevin LOISELEUR
*/

#include <stdlib.h>
#include "get_next_line.h"

void			clearmem(char *s, char c, int len)
{
  int			i;

  i = 0;
  while (s && s[i] && i < len)
    s[i++] = c;
  return ;
}

int			count_char(char *buf)
{
  int			i;

  i = 0;
  while (buf && buf[i] && buf[i] != '\n')
    i++;
  return (i);
}

int			next_begin(char *buf, int i)
{
  int			j;

  j = 0;
  while (buf[i])
    buf[j++] = buf[i++];
  buf[j] = 0;
  clearmem((buf + j), 0, (SIZE_BUF - j));
  return (j);
}

int			fist_the_fucking_norm(char *buf, int i)
{
  int			next;

  if (buf[i] == '\n' && buf[i + 1] != 0)
    {
      i++;
      next = next_begin(buf, i);
    }
  else
    {
      next = 0;
      clearmem(buf, 0, SIZE_BUF);
      buf = NULL;
    }
  return (next);
}


char			*get_next_line(const int fd)
{
  static int		next = 0;
  static char		buf[SIZE_BUF];
  char			*line;
  int			nb_char;
  int			ret;
  int			i;

  i = 0;
  ret = read(fd, (buf + next), (SIZE_READ - next));
  buf[SIZE_BUF] = 0;
  line = malloc(sizeof(char) * (nb_char = (count_char(buf) + 1)));
  if (!line || (ret == 0 && (buf[0] == 0 || buf[0] == '\n')))
    return (NULL);
  clearmem(line, 0, nb_char);
  while (buf[i] && buf[i] != '\n')
    line[i] = buf[i++];
  next = fist_the_fucking_norm(buf, i);
  return (line);
}
