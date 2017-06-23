/*
** char1.c for libtech in /home/swann/projets/libtech/src
**
** Made by Swann JAUNASSE
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Fri Dec 16 11:04:40 2016 Swann JAUNASSE
** Last update Wed Dec 28 17:06:29 2016 Swann JAUNASSE
*/

#include "libtech.h"

t_bool	ch_isdigit(char ch)
{
  return (ch >= '0' && ch <= '9');
}

t_bool	ch_isupper(char ch)
{
  return (ch >= 'A' && ch <= 'Z');
}

t_bool	ch_islower(char ch)
{
  return (ch >= 'a' && ch <= 'z');
}

t_bool	ch_isletter(char ch)
{
  return (ch_islower(ch) || ch_isupper(ch));
}

t_bool	ch_isalphanum(char ch)
{
  return (ch_isdigit(ch) || ch_isletter(ch));
}
