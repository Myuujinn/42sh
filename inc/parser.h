/*
** parser.h for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Wed Apr 12 10:56:30 2017 Victor LE DANTEC
** Last update Fri May 19 14:38:17 2017 Victor LE DANTEC
*/

#pragma once

#include "libtech.h"
#include <string.h>
#include <stddef.h>

/*
** Treat it as enum. DOT_COMMA = 1, PIPE = 2 etc...
*/

#define DOT_COMMA	';'
#define PIPE		'|'
#define DOUBLE_AND	"&&"
#define DOUBLE_PIPE	"||"
#define GREATER		'>'
#define LESS		'<'
#define DOUBLE_GREATER	">>"
#define DOUBLE_LESS	"<<"
#define DOUBLE_QUOTES	'\"'
#define SINGLE_QUOTE	'\''

/*
** Magic quotes functions
*/

#define REQUEST_QUOTES	0
#define ADD_QUOTES	1
#define RESET_QUOTES	2

typedef struct		s_parser
{
  char			*input;
  t_strlist		*tokens;
  ssize_t		index;
  size_t		cmd_count;
}			t_parser;

char	*str_trunc(char *, size_t, size_t);
int	is_delimiter(char *);
int	delimiter_empty(t_parser *);
int	delimiter_dot_comma(t_parser *);
int	delimiter_pipe(t_parser *);
int	delimiter_double_and(t_parser *);
int	delimiter_double_pipe(t_parser *);
int	delimiter_greater(t_parser *);
int	delimiter_less(t_parser *);
int	delimiter_double_greater(t_parser *);
int	delimiter_double_less(t_parser *);
int	delimiter_double_quotes(t_parser *);
int	delimiter_single_quote(t_parser *);
int	parse_word(t_parser *);
char	toggle_magic_quotes(char);
