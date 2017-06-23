/*
** delimiter_greater.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Wed Apr 12 18:49:25 2017 Victor LE DANTEC
** Last update Sat Apr 15 14:50:20 2017 Victor LE DANTEC
*/

#include "parser.h"

int	delimiter_greater(t_parser *tok_info)
{
  strlist_append(tok_info->tokens, ">");
  tok_info->cmd_count++;
  return (1);
}
