/*
** cmd_builtins.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sat May 20 23:11:17 2017 Victor LE DANTEC
** Last update Sat May 20 23:16:25 2017 Victor LE DANTEC
*/

#include "42sh.h"

int	cmd_builtins(t_shinfo *info, t_strlist *commands)
{
  int	i;

  i = 0;
  while (i < NB_BUILTINS)
    puts(g_cmd_names[i++]);
  return (SUCCESS_STATUS);
  (void)info;
  (void)commands;
}
