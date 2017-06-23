/*
** evaluator.h for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Tue Apr 25 14:59:38 2017 Victor LE DANTEC
** Last update Fri May 19 14:18:16 2017 Victor LE DANTEC
*/

/*
** See 42sh.h for explanation.
*/

#pragma once

/*
** Needed for strlists.
*/

#include "libtech.h"

/*
** Bitshift macros to keep things clean for redirects.
** Used in redirect.c
*/

#define GREATER_BSHIFT		1
#define LESS_BSHIFT		2
#define DOUBLE_GREATER_BSHIFT	4
#define DOUBLE_LESS_BSHIFT	8

/*
** Order is a bit funky but needed to correctly sort importance.
*/

#define DOT_COMMA_SEP		1
#define DOUBLE_AND_SEP		2
#define DOUBLE_PIPE_SEP		10
#define	PIPE_SEP		11

/*
** Overloaded structure? Useless variables? Shhhh....
** It's useful. Don't worry.
*/

typedef struct	s_command
{
  t_strlist	*cmd;
  char		redir_type;
  char		*binary_name;
  char		*stdout_redir;
  char		*stdin_redir;
  char		next_command;
}		t_command;

typedef struct	s_evaluator
{
  t_command	*commands;
  int		size;
  int		index;
  int		cmd_index;
  int		std_save[2];
}		t_evaluator;

int	is_separator(char *);
int	is_sep_delim(char *);

int	evaluator_word(t_evaluator *, t_strlist *);
int	redirect_less(t_evaluator *, t_strlist *);
int	redirect_greater(t_evaluator *, t_strlist *);
int	redirect_double_less(t_evaluator *, t_strlist *);
int	redirect_double_greater(t_evaluator *, t_strlist *);
int	separator_dot_comma(t_evaluator *, t_strlist *);
int	separator_double_and(t_evaluator *, t_strlist *);
int	separator_double_pipe(t_evaluator *, t_strlist *);
int	separator_pipe(t_evaluator *, t_strlist *);

void	display_commands(t_evaluator *);

int	check_null_commands(t_evaluator *);
