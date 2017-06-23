/*
** char2.c for libtech in /home/swann/projets/libtech/src
**
** Made by Swann JAUNASSE
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Fri Dec 16 11:04:40 2016 Swann JAUNASSE
** Last update Wed Dec 28 17:06:29 2016 Swann JAUNASSE
*/

#include "libtech.h"

t_bool	ch_iseol(char ch)
{
  return (ch == '\n' || ch == '\r');
}

t_bool	ch_iswhitespace(char ch)
{
  return (ch == ' ' || ch == '\f' || ch == '\t' || ch == '\v');
}

t_bool	ch_ispunctuation(char ch)
{
  if (str_contains("+-*/%^²~<>=(){}[];:,.!?&\\'", ch))
    return (TRUE);
  return (FALSE);
}

t_bool	ch_isidentifier(char ch)
{
  return (ch_isletter(ch) || ch_isdigit(ch));
}
