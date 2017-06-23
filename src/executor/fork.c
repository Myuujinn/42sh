/*
** fork.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Tue May  2 00:14:05 2017 Victor LE DANTEC
** Last update Fri May 19 17:43:12 2017 Victor LE DANTEC
*/

#include <sys/wait.h>
#include "executor.h"

int	executor_wait_for_child(t_shinfo *info, pid_t child_pid)
{
  int	status;

  executor_change_tgrp(child_pid);
  if (waitpid(child_pid, &status, 0) == -1)
    exit_error("[42sh]{fork}(wait_for_child)", WAITPID_ERR, FAILURE);
  executor_change_tgrp(info->pid);
  return (handle_status(status));
}

int	executor_fork()
{
  pid_t	pid;

  if ((pid = fork()) == -1)
    exit_error("[42sh]{fork}(executor_fork)", FORK_ERR, FAILURE);
  return (pid);
}
