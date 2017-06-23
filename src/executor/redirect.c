/*
** redirect.c for 42sh in /home/victor/PSU_2016_42sh/src/executor
**
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
**
** Started on  Thu May 04 00:06:09 2017 Victor LE DANTEC
** Last update Fri May 19 16:08:31 2017 Victor LE DANTEC
*/

#include "executor.h"

void	executor_restore_std_fd(t_shinfo *info)
{
  if (close(STDIN_FILENO) == -1)
    exit_error("[42sh]{redirect}(executor_restore_std_fd)",
	       CLOSE_ERR, FAILURE);
  if (dup(info->std_save[0]) == -1)
    exit_error("[42sh]{redirect}(executor_restore_std_fd)",
	       DUP_ERR, FAILURE);
  if (close(STDOUT_FILENO) == -1)
    exit_error("[42sh]{redirect}(executor_restore_std_fd)",
	       CLOSE_ERR, FAILURE);
  if (dup(info->std_save[1]) == -1)
    exit_error("[42sh]{redirect}(executor_restore_std_fd)",
	       DUP_ERR, FAILURE);
}

int	executor_file_redirects(t_evaluator *eval)
{
  int	return_status;

  if ((return_status = file_stdin_redirect(eval)) > 0)
    return (return_status);
  if ((return_status = file_stdout_redirect(eval)) > 0)
    return (return_status);
  return (SUCCESS_STATUS);
}
