/*
** evaluator.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Tue Apr 25 14:58:26 2017 Victor LE DANTEC
** Last update Sat May 20 17:54:27 2017 Victor LE DANTEC
*/

#include "executor.h"

static int	(*g_evaluator_array[9])(t_evaluator *, t_strlist *) =
{
  &evaluator_word,
  &redirect_double_greater,
  &redirect_double_less,
  &redirect_greater,
  &redirect_less,
  &separator_dot_comma,
  &separator_double_and,
  &separator_double_pipe,
  &separator_pipe
};

static int	null_commands(int separator, int counter, t_strlist *cmds)
{
  if ((separator >= DOUBLE_PIPE_SEP &&
       (counter == 0 || is_separator(cmds->data[counter - 1]) != 0
	|| is_separator(cmds->data[counter + 1]) != 0))
      || (separator >= DOUBLE_AND_SEP &&
	  is_separator(cmds->data[counter + 1]) != 0))
    {
      puts("Invalid null command.");
      return (FAILURE_STATUS);
    }
  return (SUCCESS_STATUS);
}

static int	nb_commands(t_strlist *cmds)
{
  int		counter;
  int		commands;
  int		separator;

  counter = -1;
  commands = 0;
  while (++counter != (int)cmds->size)
    if ((separator = is_separator(cmds->data[counter])) != 0)
      {
	if (null_commands(separator, counter, cmds) == FAILURE_STATUS)
	  return (-1);
	else if (is_separator(cmds->data[counter + 1]) == 0)
	  commands++;
      }
  if (is_separator(cmds->data[0]) == 0)
    commands++;
  (g_debug % 2 == 1) ? printf("Number of commands : %d\n", commands) : 0;
  return (commands);
}

static int	init_evaluator(t_evaluator *eval, t_strlist *commands)
{
  int		counter;

  (g_debug % 2 == 1) ? puts("------ Evaluator Output ------") : 0;
  if ((eval->size = nb_commands(commands)) < 0)
    {
      (g_debug % 2 == 1) ? puts("Bad input. Aborting.") : 0;
      return (FAILURE_STATUS);
    }
  if ((eval->commands = malloc(sizeof(t_command) * (eval->size + 1))) == NULL)
    exit_error("[42sh]{evaluator.c}(init_evaluator)", MALLOC_ERROR, FAILURE);
  eval->index = counter = -1;
  eval->cmd_index = 0;
  while (++counter != eval->size)
    {
      eval->commands[counter].cmd = strlist_create(NULL);
      eval->commands[counter].redir_type =
	eval->commands[counter].next_command = 0;
      eval->commands[counter].stdout_redir =
	eval->commands[counter].stdin_redir =
	eval->commands[counter].binary_name = NULL;
    }
  return (SUCCESS_STATUS);
}

static int	process_tokens(t_evaluator *eval, t_strlist *commands)
{
  int		i;

  i = eval->index;
  eval->index += g_evaluator_array[is_sep_delim(commands->data[eval->index])]
    (eval, commands);
  if (i > eval->index)
    return (FAILURE_STATUS);
  return (SUCCESS_STATUS);
}

int		evaluator(t_shinfo *info, t_strlist *commands)
{
  t_evaluator	eval;

  if (init_evaluator(&eval, commands) == FAILURE_STATUS)
    return (FAILURE_STATUS);
  while (++eval.index < (ssize_t)commands->size)
    if (process_tokens(&eval, commands) == FAILURE_STATUS)
      return (FAILURE_STATUS);
  if (check_null_commands(&eval) == FAILURE_STATUS)
    return (FAILURE_STATUS);
  if (g_debug % 2 == 1)
    display_commands(&eval);
  executor(&eval, info);
  return (SUCCESS_STATUS);
}
