/*
** delimiter.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Wed Apr 12 16:28:34 2017 Victor LE DANTEC
** Last update Tue Apr 25 15:25:23 2017 Victor LE DANTEC
*/

#include "42sh.h"
#include "parser.h"

int	delimiter_empty(t_parser *tok_info)
{
  return (0);
  (void)tok_info;
}

int	is_delimiter(char *string)
{
  if (*string == DOT_COMMA)
    return (1);
  if (strncmp(string, DOUBLE_PIPE, 2) == 0)
    return (4);
  if (*string == PIPE)
    return (2);
  if (strncmp(string, DOUBLE_AND, 2) == 0)
    return (3);
  if (strncmp(string, DOUBLE_GREATER, 2) == 0)
    return (7);
  if (strncmp(string, DOUBLE_LESS, 2) == 0)
    return (8);
  if (*string == GREATER)
    return (5);
  if (*string == LESS)
    return (6);
  if (*string == DOUBLE_QUOTES)
    return (9);
  if (*string == SINGLE_QUOTE)
    return (10);
  return (0);
}
