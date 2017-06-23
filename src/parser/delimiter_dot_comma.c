/*
** delimiter_dot_comma.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Wed Apr 12 17:34:47 2017 Victor LE DANTEC
** Last update Sat Apr 15 14:49:17 2017 Victor LE DANTEC
*/

#include "parser.h"

int	delimiter_dot_comma(t_parser *tok_info)
{
  strlist_append(tok_info->tokens, ";");
  tok_info->cmd_count++;
  return (1);
}
