/*
** debug_mode.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Mon Apr 24 17:19:23 2017 Victor LE DANTEC
** Last update Sun May 21 22:52:18 2017 Victor LE DANTEC
*/

#include <stdio.h>
#include "libtech.h"
#include "evaluator.h"

static void	display_next_command(t_evaluator *eval, ssize_t i)
{
  if (eval->commands[i].next_command == DOUBLE_AND_SEP)
    puts("Next command will be executed if this one succeeds.");
  else if (eval->commands[i].next_command == DOUBLE_PIPE_SEP)
    puts("Next command will be executed if this one fails.");
  else if (eval->commands[i].next_command == PIPE_SEP)
    puts("Redirecting output to next command.");
}

static void	display_redirection(t_evaluator *eval, ssize_t i)
{
  if ((eval->commands[i].redir_type & GREATER_BSHIFT) == GREATER_BSHIFT)
    printf("Redirecting output to [%s].\n", eval->commands[i].stdout_redir);
  if ((eval->commands[i].redir_type & LESS_BSHIFT) == LESS_BSHIFT)
    printf("Redirecting input from [%s] to command.\n",
	   eval->commands[i].stdin_redir);
  if ((eval->commands[i].redir_type & DOUBLE_GREATER_BSHIFT)
      == DOUBLE_GREATER_BSHIFT)
    printf("Redirecting output to the end of file [%s].\n",
	   eval->commands[i].stdout_redir);
  if ((eval->commands[i].redir_type & DOUBLE_LESS_BSHIFT)
      == DOUBLE_LESS_BSHIFT)
    printf("Redirecting input from [%s] to command.\n",
	   eval->commands[i].stdin_redir);
}

void		display_commands(t_evaluator *eval)
{
  ssize_t	i;
  int		j;

  i = -1;
  if (eval == NULL)
    puts("Evaluator returned NULL.");
  else
    while (++i != (ssize_t)eval->size)
      {
	j = -1;
	printf("Command n°%ld: ", i + 1);
	while (++j != (int)eval->commands[i].cmd->size)
	  printf("[%s] ", eval->commands[i].cmd->data[j]);
	putchar('\n');
	display_redirection(eval, i);
	display_next_command(eval, i);
    }
}

void		display_tokens(t_strlist *cmds)
{
  ssize_t	i;

  i = -1;
  printf("------ Tokenizer Output ------\n");
  if (cmds == NULL)
    puts("Tokenizer returned NULL.");
  else
    while (++i != (ssize_t)cmds->size)
      printf("Token n°%zu: [%s]\n", i + 1, cmds->data[i]);
}
