/*
** delimiter_double_less.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Wed Apr 12 18:50:19 2017 Victor LE DANTEC
** Last update Tue Apr 25 15:40:50 2017 Victor LE DANTEC
*/

#include "parser.h"

int     delimiter_double_less(t_parser *tok_info)
{
  strlist_append(tok_info->tokens, "<<");
  tok_info->cmd_count++;
  return (2);
}
