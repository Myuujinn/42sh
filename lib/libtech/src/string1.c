/*
** string1.c for libtech in /home/swann/Projets/libtech/src
**
** Made by Swann Jaunasse
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Fri Dec 16 11:04:40 2016 Swann Jaunasse
** Last update Sun Mar 19 15:11:49 2017 Victor LE DANTEC
*/

#include "libtech.h"

char            str_compare(char *s1, char *s2)
{
  if (s1 == NULL && s2 == NULL)
    return (0);
  if (s1 == NULL)
    return (*s2);
  if (s2 == NULL)
    return (*s1);
  while (*s1 && *s2 && *s1 == *s2)
    {
      s1++;
      s2++;
    }
  return (*s1 - *s2);
}

size_t          str_size(char *str)
{
  size_t        size;

  if (str == NULL)
    return (0);
  size = 0;
  while (str[size])
    size++;
  return (size);
}

char            *str_upper(char *str)
{
  size_t        count;

  requires_not_empty(str, "[libtech.a](string1.c){str_upper}", "str");
  count = 0;
  while (str[count])
    {
      if (ch_islower(str[count]))
        str[count] = str[count] - 'a' + 'A';
      count++;
    }
  return (str);
}

char            *str_lower(char *str)
{
  size_t        count;

  requires_not_empty(str, "[libtech.a](string1.c){str_lower}", "str");
  count = 0;
  while (str[count])
    {
      if (ch_isupper(str[count]))
        str[count] = str[count] - 'A' + 'a';
      count++;
    }
  return (str);
}

t_bool		str_isalphanum(char *str)
{
  size_t	count;

  requires_not_empty(str, "[libtech.a](string1.c){str_isalphanum}", "str");
  count = 0;
  while (str[count])
    {
      if (!ch_isalphanum(str[count]))
        return (FALSE);
      count++;
    }
  return (TRUE);
}
