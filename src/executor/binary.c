/*
** binary.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sun May  7 14:49:36 2017 Victor LE DANTEC
** Last update Wed May 24 12:24:12 2017 Victor LE DANTEC
*/

#include "executor.h"

static void	executor_execve(t_evaluator *eval, t_shinfo *info)
{
  char		*name;

  name = str_clone(eval->commands[eval->index].cmd->data[0]);
  eval->commands[eval->index].cmd->data[0] =
    eval->commands[eval->index].binary_name;
  if (execve(name,
	     eval->commands[eval->index].cmd->data,
	     info->env->data) < 0)
    {
      fprintf(stderr, "%s: Exec format error. Binary file not executable.\n",
	      eval->commands[eval->index].binary_name);
      exit(1);
    }
}

static void	executor_process_group()
{
  if (setpgid(getpid(), getpid()) == -1)
    exit_error("[42sh]{binary}(executor_binary)", SETPGID_ERR, FAILURE);
}

static void	executor_binary_exec(t_evaluator *eval, t_shinfo *info)
{
  if (executor_file_redirects(eval) != 0)
    exit(1);
  executor_process_group();
  executor_execve(eval, info);
}

int	executor_binary(t_evaluator *eval, t_shinfo *info, char mode)
{
  pid_t	child_pid;

  if (mode == EXEC_FORK)
    {
      if ((child_pid = executor_fork()) == 0)
        executor_binary_exec(eval, info);
      return (executor_wait_for_child(info, child_pid));
    }
  executor_binary_exec(eval, info);
  return (SUCCESS_STATUS);
}
