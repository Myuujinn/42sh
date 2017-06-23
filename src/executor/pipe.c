/*
** pipe.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sun May  7 17:27:34 2017 Victor LE DANTEC
** Last update Wed May 24 12:23:42 2017 Victor LE DANTEC
*/

#include "executor.h"

static void	executor_pipe_forker(t_evaluator *eval, t_shinfo *info,
				     int fd_save, int fd)
{
  if (fd_save != 0)
    {
      if (dup2(fd_save, STDIN_FILENO) == -1)
	exit_error("[42sh]{pipe}(executor_pipe_forker)", DUP2_ERR, FAILURE);
      if (close(fd_save) == -1)
	exit_error("[42sh]{pipe}(executor_pipe_forker)", CLOSE_ERR, FAILURE);
    }
  if (fd != 1)
    {
      if (dup2(fd, STDOUT_FILENO) == -1)
	exit_error("[42sh]{pipe}(executor_pipe_forker)", DUP2_ERR, FAILURE);
      if (close(fd) == -1)
	exit_error("[42sh]{pipe}(executor_pipe_forker)", CLOSE_ERR, FAILURE);
    }
  exit(executor_execute(eval, info, EXEC_NO_FORK));
}

static void	executor_pipe_last_one(t_evaluator *eval, t_shinfo *info,
				       int fd_save)
{
  if (fd_save != 0 && dup2(fd_save, STDIN_FILENO) == -1)
    exit_error("[42sh]{pipe}(executor_pipe)", DUP2_ERR, FAILURE);
  exit(executor_execute(eval, info, EXEC_NO_FORK));
}

static void	executor_pipe_exec(t_evaluator *eval, t_shinfo *info)
{
  int		fd[2];
  int		fd_save;

  fd_save = 0;
  while (eval->index != eval->size - 1
	 && eval->commands[eval->index].next_command == PIPE_SEP)
    {
      if (pipe(fd) == -1)
	exit_error("[42sh]{pipe}(executor_pipe)", PIPE_ERR, FAILURE);
      if (executor_fork() == 0)
	executor_pipe_forker(eval, info, fd_save, fd[1]);
      if (close(fd[1]) == -1)
	exit_error("[42sh]{pipe}(executor_pipe)", CLOSE_ERR, FAILURE);
      fd_save = fd[0];
      eval->index++;
    }
  executor_pipe_last_one(eval, info, fd_save);
}

static int	executor_pipe_check_fail(t_evaluator *eval, t_shinfo *info,
					 int begin)
{
  int		save_end;

  save_end = eval->index;
  eval->index = begin;
  while (save_end != eval->index)
    {
      if (cmd_is_builtin(eval->commands[eval->index].cmd) == FALSE
	  && executor_valid_binary(eval, info, INHIB_ERROR) == NULL)
	begin = -1;
      eval->index++;
    }
  if (begin == -1)
    return (FAILURE_STATUS);
  return (SUCCESS_STATUS);
}

int	executor_pipe(t_evaluator *eval, t_shinfo *info)
{
  pid_t	child_pid;
  int	save;
  int	status;

  if ((child_pid = executor_fork()) == 0)
    executor_pipe_exec(eval, info);
  save = eval->index;
  while (eval->index != eval->size - 1
	 && eval->commands[eval->index].next_command == PIPE_SEP)
    eval->index++;
  status = executor_wait_for_child(info, child_pid);
  if (executor_pipe_check_fail(eval, info, save) == FAILURE_STATUS)
    return (1);
  return (status);
}
