/*
** cmd_unsetenv.c for 42sh in /home/swann/PSU_2016_42sh
**
** Made by Swann Jaunasse
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Fri Dec 16 11:08:20 2016 Swann Jaunasse
** Last update Tue May 16 21:30:24 2017 Victor LE DANTEC
*/

#include "42sh.h"

int		unset_env(t_strlist *env, char *name)
{
  ssize_t	index;

  if ((name = str_concat(name, "=")) == NULL)
    exit_error("[42sh]{cmd_unsetenv}(unset_env)", MALLOC_ERROR, FAILURE);
  index = strlist_index(env, name);
  if (index > 0)
    strlist_remove(env, index);
  free(name);
  return (SUCCESS_STATUS);
}

int		multi_unset_env(t_strlist *env, t_strlist *names)
{
  size_t	count;

  count = 0;
  while (count < names->size)
    {
      unset_env(env, names->data[count]);
      count++;
    }
  return (SUCCESS_STATUS);
}

int		cmd_unsetenv(t_shinfo *info, t_strlist *cmd)
{
  if (cmd->size < 2)
    return (error_int("unsetenv", "Too few arguments.", 1));
  if (cmd->size == 2)
    return (unset_env(info->env, cmd->data[1]));
  cmd->size--;
  cmd->data++;
  return (multi_unset_env(info->env, cmd));
}
