/*
** evaluator_word.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Thu Apr 27 00:49:06 2017 Victor LE DANTEC
** Last update Thu Apr 27 01:18:03 2017 Victor LE DANTEC
*/

#include "evaluator.h"

int      evaluator_word(t_evaluator *eval, t_strlist *cmds)
{
  strlist_append(eval->commands[eval->cmd_index].cmd, cmds->data[eval->index]);
  return (SUCCESS_STATUS);
}
