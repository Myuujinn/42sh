/*
** cmd_getenv.c for 42sh in /home/swann/PSU_2016_42sh
**
** Made by Swann Jaunasse
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Fri Dec 16 11:08:20 2016 Swann Jaunasse
** Last update Tue Apr 11 20:02:28 2017 Victor LE DANTEC
*/

#include "42sh.h"

int		set_env(t_strlist *env, char *name, char *value)
{
  ssize_t	index;
  char		*line;

  if ((str_size(name) <= 0) || (!ch_isletter(name[0])))
    return (error_int("setenv", "Variable name must begin with a letter.", 1));
  if (!str_isalphanum(name))
    return (error_int("setenv",
		  "Variable name must contain alphanumeric characters.", 1));
  line = str_concat(name, "=");
  index = strlist_index(env, line);
  line = str_concat(line, value);
  if (index < 0)
    strlist_append(env, line);
  else
    env->data[index] = line;
  return (SUCCESS_STATUS);
}

int		cmd_setenv(t_shinfo *info, t_strlist *cmd)
{
  if (cmd->size > 3)
    return (error_int("setenv", "Too many arguments.", 1));
  if (cmd->size < 2)
    return (cmd_env(info, cmd));
  if (cmd->size == 3)
    return (set_env(info->env, cmd->data[1], cmd->data[2]));
  return (set_env(info->env, cmd->data[1], ""));
}
