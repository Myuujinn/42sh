/*
** builtins.c for 42sh in /home/victor/PSU_2016_42sh/src/builtins.c
**
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
**
** Started on  Wed May 03 23:35:05 2017 Victor LE DANTEC
** Last update Fri May 19 16:08:37 2017 Victor LE DANTEC
*/

#include "executor.h"

static int	executor_exec_builtin(t_evaluator *eval, t_shinfo *info)
{
  int		count;

  count = 0;
  if (executor_file_redirects(eval) != 0)
    return (1);
  while (count < NB_BUILTINS)
    {
      if (str_compare(eval->commands[eval->index].cmd->data[0],
		      g_cmd_names[count]) == 0)
	return (g_cmd_funcs[count](info,
				   eval->commands[eval->index].cmd));
      count++;
    }
  return (FAILURE_STATUS);
}

int		executor_builtin(t_evaluator *eval, t_shinfo *info)
{
  int		status;

  status = executor_exec_builtin(eval, info);
  executor_restore_std_fd(info);
  return (status);
}
