/*
** check_commands.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Fri May 19 14:11:27 2017 Victor LE DANTEC
** Last update Fri May 19 14:18:35 2017 Victor LE DANTEC
*/

#include "evaluator.h"

int		check_null_commands(t_evaluator *eval)
{
  int		i;

  i = 0;
  while (i < eval->size)
    if (eval->commands[i++].cmd->size == 0)
      {
	puts("Invalid null command.");
	return (FAILURE_STATUS);
      }
  return (SUCCESS_STATUS);
}
