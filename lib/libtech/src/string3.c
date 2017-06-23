/*
** string2.c for libtech in /home/swann/Projets/libtech/src
**
** Made by Swann Jaunasse
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Fri Dec 16 11:04:40 2016 Swann Jaunasse
** Last update Sat May 20 02:13:45 2017 Victor LE DANTEC
*/

#include "libtech.h"

char		*str_concat(char *s1, char *s2)
{
  char		*new_str;
  size_t	s1_size;
  size_t	s2_size;
  size_t	size;
  size_t	count;

  s1_size = str_size(s1);
  s2_size = str_size(s2);
  size = s1_size + s2_size;
  if ((new_str = malloc(sizeof(char) * (size + 1))) == NULL)
    exit_error("libtech", MALLOC_ERROR, 84);
  count = 0;
  while (count < s1_size)
    {
      new_str[count] = s1[count];
      count++;
    }
  count = 0;
  while (count < s2_size)
    {
      new_str[s1_size + count] = s2[count];
      count++;
    }
  new_str[s1_size + count] = '\0';
  return (new_str);
}

t_bool		str_start_with(char *str, char *pattern)
{
  size_t	count;

  if (str == NULL || pattern == NULL)
    return (FALSE);
  if (str_size(pattern) > str_size(str))
    return (FALSE);
  count = 0;
  while (pattern[count])
    {
      if (str[count] != pattern[count])
	return (FALSE);
      count++;
    }
  return (TRUE);
}

t_bool          str_end_with(char *str, char *pattern)
{
  size_t        count;
  size_t	size_str;
  size_t	size_pattern;

  if (str == NULL || pattern == NULL)
    return (FALSE);
  if ((size_pattern = str_size(pattern)) > (size_str = str_size(str)))
    return (FALSE);
  count = 0;
  while (count < size_pattern)
    {
      if (str[size_str - (count + 1)] != pattern[size_pattern - (count + 1)])
        return (FALSE);
      count++;
    }
  return (TRUE);
}

void		str_copy(char *src, char *dest, size_t size)
{
  size_t	count;

  if (src != NULL && dest != NULL)
    {
      count = 0;
      while (count < size && src[count])
	{
	  dest[count] = src[count];
	  count++;
	}
      while (count < size)
	{
	  dest[count] = '\0';
	  count++;
	}
    }
}

char		*str_clone(char *str)
{
  size_t	count;
  char		*new_str;
  size_t	size;

  if (str == NULL)
    return (NULL);
  size = str_size(str);
  if ((new_str = malloc(sizeof(char) * (size + 1))) == NULL)
    exit_error("libtech", MALLOC_ERROR, 84);
  count = 0;
  while (count < size)
    {
      new_str[count] = str[count];
      count++;
    }
  new_str[count] = '\0';
  return (new_str);
}
