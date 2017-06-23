/*
** contracts.c for libtech in /home/swann/projets/libtech/src
**
** Made by Swann JAUNASSE
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Tue Feb 14 11:21:16 2017 Swann JAUNASSE
** Last update Fri May 12 23:27:41 2017 Victor LE DANTEC
*/

#include "libtech.h"

void	requires(t_bool condition, char *src)
{
  if (!condition)
    {
      print(src, ERROR_STREAM);
      print_line(" : condition is false", ERROR_STREAM);
    }
}

void	requires_not_null(void *ptr, char *src, char *name)
{
  if (ptr == NULL)
    {
      print(src, ERROR_STREAM);
      print(" : ", ERROR_STREAM);
      print(name, ERROR_STREAM);
      print_line(" must not be null", ERROR_STREAM);
    }
}
