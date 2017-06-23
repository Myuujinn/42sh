/*
** delimiter.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Tue Apr 25 23:32:44 2017 Victor LE DANTEC
** Last update Sat May 20 01:04:54 2017 Victor LE DANTEC
*/

#include "evaluator.h"
#include "parser.h"

int	is_separator(char *string)
{
  if (string == NULL)
    return (FAILURE_STATUS);
  if (strcmp(string, ";") == 0)
    return (DOT_COMMA_SEP);
  if (strcmp(string, DOUBLE_AND) == 0)
    return (DOUBLE_AND_SEP);
  if (strcmp(string, DOUBLE_PIPE) == 0)
    return (DOUBLE_PIPE_SEP);
  if (strcmp(string, "|") == 0)
    return (PIPE_SEP);
  return (SUCCESS_STATUS);
}

int	is_sep_delim(char *string)
{
  if (string == NULL)
    return (FAILURE_STATUS);
  if (strcmp(string, ">>") == 0)
    return (1);
  if (strcmp(string, "<<") == 0)
    return (2);
  if (strcmp(string, ">") == 0)
    return (3);
  if (strcmp(string, "<") == 0)
    return (4);
  if (strcmp(string, ";") == 0)
    return (5);
  if (strcmp(string, DOUBLE_AND) == 0)
    return (6);
  if (strcmp(string, DOUBLE_PIPE) == 0)
    return (7);
  if (strcmp(string, "|") == 0)
    return (8);
  return (SUCCESS_STATUS);
}
