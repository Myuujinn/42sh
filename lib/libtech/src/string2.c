/*
** string2.c for libtech in /home/swann/projets/libtech/src
**
** Made by Swann JAUNASSE
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Fri Dec 16 11:04:40 2016 Swann JAUNASSE
** Last update Sat May 20 02:13:56 2017 Victor LE DANTEC
*/

#include "libtech.h"

char		*str_append(char *str, char c)
{
  size_t	count;
  char		*new_str;
  size_t	size;

  requires_not_empty(str, "[libtech.a](string2.c){str_append}", "str");
  size = str_size(str);
  if ((new_str = malloc(sizeof(char) * (size + 2))) == NULL)
    exit_error("[libtech.a](string2.c){str_append}",
	       MALLOC_ERROR, 84);
  count = 0;
  while (count < size)
    {
      new_str[count] = str[count];
      count++;
    }
  new_str[count++] = c;
  new_str[count] = '\0';
  return (new_str);
}

char		*str_truncate(char *str, size_t start, size_t len)
{
  char		*new_str;
  size_t	count;

  requires_not_empty(str, "[libtech.a](string2.c){str_truncate}", "str");
  requires(len <= str_size(str) - start,
	   "[libtech.a](string2.c){str_truncate}");
  if ((new_str = malloc(sizeof(char) * (len + 1))) == NULL)
    return (error_ptr("[libtech.a](string2.c){str_truncate}",
		      MALLOC_ERROR, NULL));
  count = 0;
  while (count < len)
    {
      new_str[count] = str[start + count];
      count++;
    }
  new_str[count] = '\0';
  return (new_str);
}

t_bool		str_contains(char *str, char ch)
{
  size_t	count;

  if (str == NULL || str_size(str) == 0)
    return (FALSE);
  count = 0;
  while (str[count])
    {
      if (str[count] == ch)
	return (TRUE);
      count++;
    }
  return (FALSE);
}

ssize_t		str_first(char *str, char ch)
{
  size_t	count;

  if (str == NULL || str_size(str) == 0)
    return (-1);
  count = 0;
  while (str[count])
    {
      if (str[count] == ch)
	return (count);
      count++;
    }
  return (-1);
}

size_t		str_count(char *str, char ch)
{
  size_t	count;
  size_t	nbr;

  if (str == NULL || str_size(str) == 0)
    return (0);
  count = nbr = 0;
  while (str[count])
    {
      if (str[count] == ch)
	nbr++;
      count++;
    }
  return (nbr);
}
