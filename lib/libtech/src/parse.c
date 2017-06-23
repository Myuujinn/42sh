/*
** parse.c for libtech in /home/swann/Projets/libtech/src
**
** Made by swann jaunasse
** Login   <swann.jaunasse@epitech.net>
**
** Started on  Tue Oct 11 20:03:59 2016 swann jaunasse
** Last update Wed Oct 12 11:16:55 2016 swann jaunasse
*/

#include "libtech.h"

char            is_nbr(char *str)
{
  size_t        count;

  requires_not_empty(str, "[libtech.a](parse.c){is_nbr}", "str");
  count = 0;
  while (str[count] == '-' || str[count] == '+')
    count++;
  while (str[count])
    {
      if (str[count] < '0' || str[count] > '9')
        return (FALSE);
      count++;
    }
  return (TRUE);
}

ssize_t		parse_nbr(char *str)
{
  size_t	count;
  ssize_t	number;
  char		minus;

  requires_not_empty(str, "[libtech.a](parse.c){parse_nbr}", "str");
  number = minus = count = 0;
  while (str[count] == '-' || str[count] == '+' || str[count] == ' ')
    {
      minus = (str[count] == '-') ? (!minus) : (minus);
      count++;
    }
  while (str[count] && str[count] >= '0' && str[count] <= '9')
    {
      number = number * 10;
      number += str[count] - '0';
      count++;
    }
  return ((minus) ? (-number) : (number));
}
