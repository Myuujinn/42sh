/*
** cmd_echo.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Thu May 18 15:44:45 2017 Victor LE DANTEC
** Last update Sat May 20 16:01:41 2017 Victor LE DANTEC
*/

#include "42sh.h"

int		cmd_echo(t_shinfo *info, t_strlist *commands)
{
  size_t	i;
  char		newline;

  newline = 0;
  if (commands->size > 1 && str_compare(commands->data[1], "-n") == 0)
    newline++;
  i = newline + 1;
  while (i < commands->size)
    {
      print(commands->data[i++], STDOUT_FILENO);
      if (i < commands->size)
	write(STDOUT_FILENO, " ", 1);
    }
  if (newline == 0)
    write(STDOUT_FILENO, "\n", 1);
  return (SUCCESS_STATUS);
  (void)info;
}
