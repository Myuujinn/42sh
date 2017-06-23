/*
** separator.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Thu Apr 27 01:02:49 2017 Victor LE DANTEC
** Last update Wed May 24 12:22:46 2017 Victor LE DANTEC
*/

#include "evaluator.h"

static int	if_last_separator(t_evaluator *eval, t_strlist *commands)
{
  int		index;

  index = eval->index;
  if (index == 0)
    return (SUCCESS_STATUS);
  while (index > 0)
    {
      if (is_separator(commands->data[index]) == 0)
	return (SUCCESS_STATUS);
      index--;
    }
  return (FAILURE_STATUS);
}

int	separator_dot_comma(t_evaluator *eval, t_strlist *commands)
{
  eval->commands[eval->cmd_index].next_command = DOT_COMMA_SEP;
  if (is_separator(commands->data[eval->index + 1]) == 0
      && eval->index != 0 && if_last_separator(eval, commands) == 0)
    eval->cmd_index++;
  return (SUCCESS_STATUS);
  (void)commands;
}

int	separator_double_and(t_evaluator *eval, t_strlist *commands)
{
  eval->commands[eval->cmd_index].next_command = DOUBLE_AND_SEP;
  if (is_separator(commands->data[eval->index + 1]) == 0
      && eval->index != 0 && if_last_separator(eval, commands) == 0)
    eval->cmd_index++;
  return (SUCCESS_STATUS);
  (void)commands;
}

int	separator_double_pipe(t_evaluator *eval, t_strlist *commands)
{
  eval->commands[eval->cmd_index].next_command = DOUBLE_PIPE_SEP;
  if (is_separator(commands->data[eval->index + 1]) == 0)
    eval->cmd_index++;
  return (SUCCESS_STATUS);
  (void)commands;
}

int	separator_pipe(t_evaluator *eval, t_strlist *commands)
{
  if (eval->commands[eval->cmd_index].stdout_redir != NULL)
    {
      puts("Ambiguous output redirect.");
      return (-1);
    }
  eval->commands[eval->cmd_index].next_command = PIPE_SEP;
  if (is_separator(commands->data[eval->index + 1]) == 0)
    eval->cmd_index++;
  return (SUCCESS_STATUS);
  (void)commands;
}
