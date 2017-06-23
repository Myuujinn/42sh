/*
** error.c for libtech in /home/swann/projets/libtech/src
**
** Made by Swann JAUNASSE
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Fri Dec  9 14:18:57 2016 Swann JAUNASSE
** Last update Tue Dec 20 20:36:13 2016 Swann JAUNASSE
*/

#include <signal.h>
#include "libtech.h"

void	error(char *src, char *msg)
{
  requires_not_empty(msg, "[libtech.a](error.c){error}", "msg");
  print(src, ERROR_STREAM);
  print(": ", ERROR_STREAM);
  print_line(msg, ERROR_STREAM);
}

int	error_int(char *src, char *msg, int ret)
{
  requires_not_empty(msg, "[libtech.a](error.c){error}", "msg");
  if (str_size(src))
    {
      print(src, ERROR_STREAM);
      print(": ", ERROR_STREAM);
    }
  print_line(msg, ERROR_STREAM);
  return (ret);
}

void	*error_ptr(char *src, char *msg, void *ret)
{

  requires_not_empty(msg, "[libtech.a](error.c){error}", "msg");
  if (str_size(src))
    {
      print(src, ERROR_STREAM);
      print(": ", ERROR_STREAM);
    }
  print_line(msg, ERROR_STREAM);
  return (ret);
}

void    warning(char *src, char *msg)
{
  requires_not_empty(msg, "[libtech.a](error.c){warning}", "msg");
  if (str_size(src))
    {
      print(src, ERROR_STREAM);
      print(": warning: ", ERROR_STREAM);
    }
  print_line(msg, ERROR_STREAM);
}
