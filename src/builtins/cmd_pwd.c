/*
** cmd_pwd.c for 42sh in /home/swann/PSU_2016_42sh
**
** Made by Swann Jaunasse
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Fri Dec 16 11:08:20 2016 Swann Jaunasse
** Last update Tue Apr 11 20:03:19 2017 Victor LE DANTEC
*/

#include "42sh.h"

char	*get_pwd(t_strlist *env)
{
  char	*pwd;

  if ((pwd = strlist_find(env, "PWD=")) == NULL)
    return (".");
  return (pwd + 4);
}

int	cmd_pwd(t_strlist *env, t_strlist *cmd)
{
  (void)cmd;
  print_line(get_pwd(env), 1);
  return (SUCCESS_STATUS);
}
