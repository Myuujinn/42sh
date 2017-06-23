/*
** executor.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sun Apr 30 19:02:50 2017 Victor LE DANTEC
** Last update Sat May 20 17:53:25 2017 Victor LE DANTEC
*/

#include "executor.h"

static void	executor_init(t_evaluator *eval)
{
  eval->index = eval->cmd_index = 0;
}

static void	executor_condition(t_evaluator *eval, t_shinfo *info)
{
  if (eval->commands[eval->index - 1].next_command == DOUBLE_AND_SEP &&
      info->status == 0)
    info->status = (unsigned char)executor_execute(eval, info, EXEC_FORK);
  else if (eval->commands[eval->index - 1].next_command == DOUBLE_PIPE_SEP &&
      info->status != 0)
    info->status = (unsigned char)executor_execute(eval, info, EXEC_FORK);
}

static void	executor_loop(t_evaluator *eval, t_shinfo *info)
{
  while (eval->index != eval->size)
    {
      if (eval->commands[eval->index].next_command == PIPE_SEP)
	info->status = (unsigned char)executor_pipe(eval, info);
      else if (eval->index != 0 &&
	       (eval->commands[eval->index - 1].next_command == DOUBLE_AND_SEP
		|| eval->commands[eval->index - 1].next_command ==
		DOUBLE_PIPE_SEP))
	executor_condition(eval, info);
      else
	info->status = (unsigned char)executor_execute(eval, info, EXEC_FORK);
      eval->index++;
    }
}

void	executor(t_evaluator *eval, t_shinfo *info)
{
  executor_init(eval);
  if (g_debug % 2 == 1)
    puts("------ Executor Output ------");
  executor_loop(eval, info);
}
