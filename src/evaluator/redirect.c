/*
** redirect.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Wed Apr 26 20:45:58 2017 Victor LE DANTEC
** Last update Wed May 24 12:25:04 2017 Victor LE DANTEC
*/

#include <string.h>
#include "evaluator.h"

int	redirect_less(t_evaluator *eval, t_strlist *commands)
{
  if (eval->commands[eval->cmd_index].stdin_redir != NULL
      || (eval->cmd_index != 0 &&
	  eval->commands[eval->cmd_index - 1].next_command == PIPE_SEP))
    {
      puts("Ambiguous input redirect.");
      return (-1);
    }
  if (commands->data[eval->index + 1] == NULL ||
      is_sep_delim(commands->data[eval->index + 1]) != 0)
    {
      puts("Missing name for redirect.");
      return (-1);
    }
  eval->commands[eval->cmd_index].redir_type |= LESS_BSHIFT;
  eval->commands[eval->cmd_index].stdin_redir = str_clone
    (commands->data[eval->index + 1]);
  return (1);
}

int	redirect_greater(t_evaluator *eval, t_strlist *commands)
{
  if (eval->commands[eval->cmd_index].stdout_redir != NULL
      || eval->commands[eval->cmd_index].next_command == PIPE_SEP)
    {
      puts("Ambiguous output redirect.");
      return (-1);
    }
  if (commands->data[eval->index + 1] == NULL ||
      is_separator(commands->data[eval->index + 1]) != 0)
    {
      puts("Missing name for redirect.");
      return (-1);
    }
  eval->commands[eval->cmd_index].redir_type |= GREATER_BSHIFT;
  eval->commands[eval->cmd_index].stdout_redir = str_clone
    (commands->data[eval->index + 1]);
  return (1);
}

int	redirect_double_less(t_evaluator *eval, t_strlist *commands)
{
  if (eval->commands[eval->cmd_index].stdin_redir != NULL
      || (eval->cmd_index != 0 &&
	  eval->commands[eval->cmd_index - 1].next_command == PIPE_SEP))
    {
      puts("Ambiguous input redirect.");
      return (-1);
    }
  if (commands->data[eval->index + 1] == NULL ||
      is_sep_delim(commands->data[eval->index + 1]) != 0)
    {
      puts("Missing name for redirect.");
      return (-1);
    }
  eval->commands[eval->cmd_index].redir_type |= DOUBLE_LESS_BSHIFT;
  eval->commands[eval->cmd_index].stdin_redir = str_clone
    (commands->data[eval->index + 1]);
  return (1);
}

int	redirect_double_greater(t_evaluator *eval, t_strlist *commands)
{
  if (eval->commands[eval->cmd_index].stdout_redir != NULL
      || eval->commands[eval->cmd_index].next_command == PIPE_SEP)
    {
      puts("Ambiguous output redirect.");
      return (-1);
    }
  if (commands->data[eval->index + 1] == NULL ||
      is_sep_delim(commands->data[eval->index + 1]) != 0)
    {
      puts("Missing name for redirect.");
      return (-1);
    }
  eval->commands[eval->cmd_index].redir_type |= DOUBLE_GREATER_BSHIFT;
  eval->commands[eval->cmd_index].stdout_redir = str_clone
    (commands->data[eval->index + 1]);
  return (1);
}
