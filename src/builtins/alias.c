/*
** alias.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sat May 20 03:00:20 2017 Victor LE DANTEC
** Last update Sun May 21 17:52:55 2017 Victor LE DANTEC
*/

#include "42sh.h"

void		alias_replace_string(char *value, char **line,
				     size_t offset, size_t *i)
{
  char		*newline;

  *i = 0;
  if ((newline = malloc(sizeof(char) * (strlen(*line) + strlen(value) + 1)))
      == NULL)
    exit_error("[42sh]{alias}(alias_replace_string)", MALLOC_ERROR, FAILURE);
  newline[0] = '\0';
  strncpy(newline, *line, offset);
  value = str_concat(value, *line + offset + strlen(*line));
  newline = str_concat(newline, value);
  *line = newline;
}

size_t		get_offset(char *line, char *value)
{
  ssize_t	i;

  i = -1;
  while (line[++i] != '\0')
    if (strncmp(line + i, value, strlen(value)) == 0)
      break;
  return (i);
}

void		try_swap(t_shinfo *info, char **line, size_t *i)
{
  size_t	offset;
  char		*match;

  match = strstr(line[0], info->alias.name->data[*i]);
  offset = get_offset(*line, info->alias.name->data[*i]);
  if (offset == 0 &&
      (match[strlen(info->alias.name->data[*i])] == ' ' ||
       match[strlen(info->alias.name->data[*i])] == '\0'))
    alias_replace_string(info->alias.value->data[*i], line, offset, i);
  else if (offset != 0 && (*line)[offset - 1] == ' ' &&
	   (match[strlen(info->alias.name->data[*i])] == ' ' ||
	    match[strlen(info->alias.name->data[*i])] == '\0'))
    alias_replace_string(info->alias.value->data[*i], line, offset, i);
}

void		alias_swap(t_shinfo *info, char **line)
{
  size_t	i;

  i = 0;
  while (i < info->alias.size)
    {
      if (strstr(*line, info->alias.name->data[i]) != NULL &&
	  strstr(*line, "alias") == NULL)
	  try_swap(info, line, &i);
      i++;
    }
}
