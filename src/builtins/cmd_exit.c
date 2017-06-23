/*
** cmd_exit.c for 42sh in /home/swann/PSU_2016_42sh
**
** Made by Swann Jaunasse
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Fri Dec 16 11:08:20 2016 Swann Jaunasse
** Last update Sat May 20 01:15:24 2017 Victor LE DANTEC
*/

#include "42sh.h"

static int	exit_plz(int code)
{
  print_line("exit", 1);
  exit(code);
  return (EXIT_SUCCESS);
}

int		cmd_exit(t_shinfo *info, t_strlist *cmd)
{
  (void)info;
  if (cmd->size > 2)
    return (error_int("getenv", "Too many arguments.", 1));
  if (cmd->size < 2)
    return (exit_plz(SUCCESS_STATUS));
  if (!is_nbr(cmd->data[1]))
    return (error_int("exit", "Expression syntax.", 1));
  return (exit_plz(parse_nbr(cmd->data[1])));
}
