/*
** parser_utils.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Wed Apr 12 11:09:26 2017 Victor LE DANTEC
** Last update Wed Apr 12 11:56:43 2017 Victor LE DANTEC
*/

#include <string.h>
#include "libtech.h"

char		*str_trunc(char *string, size_t begin, size_t end)
{
  char		*new;

  requires_not_empty(string, "parser_utils.c", "str_trunc");
  if ((strlen(string) > begin || strlen(string) > end) && begin > end)
    exit_error("[42sh]{parser_utils}(str_trunc)", APP_CRASHED, FAILURE);
  new = str_clone(string) + begin;
  new[end] = '\0';
  return (new);
}

char		*my_strchr(char *string, size_t begin, char to_find)
{
  size_t	i;

  requires_not_empty(string, "parser_utils.c", "str_trunc");
  if (strlen(string) > begin)
    exit_error("[42sh]{parser_utils}(my_strchr)", APP_CRASHED, FAILURE);
  i = begin;
  while (string[i] != '\0')
    {
      if (string[i] == to_find)
	return (string + i);
      i++;
    }
  return (NULL);
}
