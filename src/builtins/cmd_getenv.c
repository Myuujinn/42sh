/*
** cmd_getenv.c for 42sh in /home/swann/PSU_2016_42sh
**
** Made by Swann Jaunasse
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Fri Dec 16 11:08:20 2016 Swann Jaunasse
** Last update Tue Apr 11 20:02:07 2017 Victor LE DANTEC
*/

#include "42sh.h"

char	*get_env(t_strlist *env, char *name)
{
  char	*value;

  if ((value = strlist_find(env, name)) == NULL)
    return (NULL);
  return (value + str_size(name) + 1);
}

int	cmd_getenv(t_shinfo *info, t_strlist *cmd)
{
  char	*value;

  if (cmd->size > 2)
    return (error_int("getenv", "Too many arguments.", 1));
  if (cmd->size < 2)
    return (error_int("getenv", "Too few arguments.", 1));
  value = str_concat(cmd->data[1], "=");
  value = get_env(info->env, value);
  if (value != NULL)
    print_line(value, 1);
  return (SUCCESS_STATUS);
}
