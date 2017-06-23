/*
** cmd_which.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sat May 20 18:00:45 2017 Victor LE DANTEC
** Last update Sat May 20 18:19:43 2017 Victor LE DANTEC
*/

#include "42sh.h"

int		cmd_which(t_shinfo *info, t_strlist *cmds)
{
  char		error;
  char		*path;

  cmds->size--;
  cmds->data++;
  error = 0;
  if (cmds->size == 0)
    return (error_int("which", "Too few arguments.", 1));
  while (cmds->size != 0)
    {
      if (cmd_is_builtin(cmds) == TRUE && (path = NULL) == NULL)
	printf("%s: shell built-in command.\n", cmds->data[0]);
      else if ((path = search_binary(info->env, cmds->data[0])) == NULL
	       && (error = 1) == 1)
	printf("%s: Command not found.\n", cmds->data[0]);
      else
	puts(path);
      if (path != NULL)
	free(path);
      cmds->size--;
      cmds->data++;
    }
  return (error);
}
