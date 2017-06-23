/*
** execute.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Tue May  2 13:39:31 2017 Victor LE DANTEC
** Last update Fri May 19 15:39:12 2017 Victor LE DANTEC
*/

#include <sys/stat.h>
#include "executor.h"

char		*executor_valid_binary(t_evaluator *eval, t_shinfo *info,
				       char mode)
{
  char		*path;
  struct stat	file_info;

  if ((path = search_binary
       (info->env, eval->commands[eval->index].cmd->data[0])) == NULL)
    return ((mode == NO_INHIB_ERROR)
	    ? error_ptr(eval->commands[eval->index].cmd->data[0],
			"Command not found.", NULL) : NULL);
  if (stat(path, &file_info) == -1)
    exit_error("[42sh]{execute}(executor_get_binary)",
	       STAT_ERR, FAILURE_STATUS);
  if (access(path, X_OK) != 0 || !S_ISREG(file_info.st_mode))
    return ((mode == NO_INHIB_ERROR)
	    ? error_ptr(eval->commands[eval->index].cmd->data[0],
			"Permission denied.", NULL) : NULL);
  return (str_clone(path));
}

static int	executor_get_binary(t_evaluator *eval, t_shinfo *info)
{
  char		*path;

  if ((path = executor_valid_binary(eval, info, NO_INHIB_ERROR)) == NULL)
    return (1);
  eval->commands[eval->index].binary_name = str_clone
    (eval->commands[eval->index].cmd->data[0]);
  if (eval->commands[eval->index].cmd->data[0] != NULL)
    free(eval->commands[eval->index].cmd->data[0]);
  eval->commands[eval->index].cmd->data[0] = path;
  return (SUCCESS_STATUS);
}

static int	executor_valid_command(t_evaluator *eval, t_shinfo *info)
{
  if (eval->index == eval->size)
    return (SUCCESS_STATUS);
  if (cmd_is_builtin(eval->commands[eval->index].cmd) == TRUE)
    return (1);
  if (executor_get_binary(eval, info) == 0)
    return (2);
  return (SUCCESS_STATUS);
}

int	executor_execute(t_evaluator *eval, t_shinfo *info, char mode)
{
  int	type;

  if ((type = executor_valid_command(eval, info)) == 0)
    return (1);
  if (type == 1)
    return (executor_builtin(eval, info));
  else if (type == 2)
    return (executor_binary(eval, info, mode));
  return (SUCCESS_STATUS);
}
