/*
** cmd_alias.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sat May 20 01:36:40 2017 Victor LE DANTEC
** Last update Sun May 21 18:17:02 2017 Victor LE DANTEC
*/

#include "42sh.h"

ssize_t		is_alias(t_shinfo *info, char *alias_name)
{
  ssize_t	i;

  i = 0;
  while ((size_t)i < info->alias.size)
    {
      if (strcmp(alias_name, info->alias.name->data[i]) == 0)
	return (i);
      i++;
    }
  return (-1);
}

static int	print_alias(t_shinfo *info, char *alias_name)
{
  ssize_t	index;

  if ((index = is_alias(info, alias_name)) != -1)
    puts(info->alias.value->data[index]);
  return (SUCCESS_STATUS);
}

static int	put_in_db(t_shinfo *info, t_strlist *commands, ssize_t index,
			  char *buffer)
{
  if (index == -1)
    {
      strlist_append(info->alias.name, commands->data[1]);
      strlist_append(info->alias.value, buffer);
      info->alias.size++;
    }
  else
    info->alias.value->data[index] = buffer;
  return (SUCCESS_STATUS);
}

static int	add_alias(t_shinfo *info, t_strlist *commands, ssize_t index)
{
  char		*buffer;
  size_t	i;

  i = 2;
  if ((buffer = strdup("")) == NULL)
    exit_error("[42sh]{cmd_alias}(add_alias)", MALLOC_ERROR, FAILURE);
  while (i < commands->size)
    {
      buffer = str_concat(buffer, commands->data[i]);
      i++;
      if (i < commands->size)
	buffer = str_concat(buffer, " ");
    }
  return (put_in_db(info, commands, index, buffer));
}

int		cmd_alias(t_shinfo *info, t_strlist *commands)
{
  ssize_t	index;

  if (commands->size < 2)
    {
      index = -1;
      while ((size_t)++index < info->alias.size)
	printf("%s\t(%s)\n", info->alias.name->data[index],
	       info->alias.value->data[index]);
      return (SUCCESS_STATUS);
    }
  if (commands->size == 2)
    return (print_alias(info, commands->data[1]));
  if ((index = is_alias(info, commands->data[1])) != -1)
    add_alias(info, commands, index);
  else if (strcmp(commands->data[1], "alias") == 0)
    return (error_int("alias", "Too dangerous to alias that.", 1));
  add_alias(info, commands, -1);
  return (SUCCESS_STATUS);
}
