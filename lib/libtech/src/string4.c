/*
** string4.c for libtech in /home/swann/LibTech/src
** 
** Made by Swann JAUNASSE
** Login   <swann.jaunasse@epitech.eu>
** 
** Started on  Sun Mar 19 15:18:14 2017 Swann JAUNASSE
** Last update Mon Apr 10 20:19:34 2017 Swann JAUNASSE
*/

#include "libtech.h"

char		*str_reverse(char *str)
{
  size_t	i;
  size_t	j;
  char		*rev_str;

  if (str == NULL)
    return (NULL);
  i = str_size(str) - 1;
  j = 0;
  if ((rev_str = malloc(sizeof(char) * (str_size(str) + 1))) == NULL)
    return (NULL);
  while (i > 0)
    rev_str[j++] = str[i--];
  rev_str[j++] = str[i];
  rev_str[j] = '\0';
  return (rev_str);
}

t_strlist       *str_split(char *str, char *sep)
{
  t_strlist     *list;
  size_t        count;
  size_t        len;

  requires_not_null(str, "[libtech.a](string4.c){str_split}", "str");
  requires_not_empty(sep, "[libtech.a](string4.c){str_split}", "sep");
  if ((list = strlist_create(NULL)) == NULL)
    return (error_ptr("[libtech.a](string4.c){str_split}",
                      "strlist creation failed", NULL));
  count = len = 0;
  while (str[count])
    {
      if (str_contains(sep, str[count]))
        {
          if (len > 0)
            strlist_append(list, str_truncate(str, count - len, len));
          len = 0;
        }
      else
        len++;
      count++;
    }
  if (len > 0)
    strlist_append(list, str_truncate(str, count - len, len));
  return (list);
}

char		*str_replace(char *str, char old, char new)
{
  char		*new_str;
  size_t	new_size;
  size_t	count;

  new_size = str_size(str);
  if ((new_str = malloc(sizeof(char) * (new_size + 1))) == NULL)
    return (error_ptr("[libtech.a]{string4.c}(str_replace)",
		      MALLOC_ERROR, NULL));
  count = 0;
  while (count < new_size)
    {
      if (str[count] == old)
	new_str[count] = new;
      else
	new_str[count] = str[count];
      count++;
    }
  new_str[count] = '\0';
  return (new_str);
}
