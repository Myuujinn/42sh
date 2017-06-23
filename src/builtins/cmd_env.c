/*
** cmd_env.c for 42sh in /home/swann/PSU_2016_42sh
**
** Made by Swann Jaunasse
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Fri Dec 16 11:08:20 2016 Swann Jaunasse
** Last update Tue Apr 11 20:01:36 2017 Victor LE DANTEC
*/

#include "42sh.h"

int	cmd_env(t_shinfo *info, t_strlist *cmd)
{
  (void)cmd;
  print_strlist(info->env, 1);
  return (SUCCESS_STATUS);
}
