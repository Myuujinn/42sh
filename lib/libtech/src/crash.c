/*
** crash.c for libtech in /home/swann/projets/libtech/src
**
** Made by Swann JAUNASSE
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Fri Dec  9 14:18:57 2016 Swann JAUNASSE
** Last update Mon Apr 10 20:15:54 2017 Victor LE DANTEC
*/

#include <signal.h>
#include "libtech.h"

void	crashed()
{
  exit_error((char *)g_binary_name, APP_CRASHED, FAILURE_STATUS);
}

void	handle_crash()
{
  signal(SIGFPE, crashed);
  signal(SIGSEGV, crashed);
}

void    exit_error(char *src, char *msg, int ret)
{
  requires_not_empty(src, "[libtech.a](error.c){exit_error}", "src");
  requires_not_empty(msg, "[libtech.a](error.c){exit_error}", "msg");
  print(src, ERROR_STREAM);
  print(": error: ", ERROR_STREAM);
  print_line(msg, ERROR_STREAM);
  exit(ret);
}
