/*
** contracts.c for libtech in /home/swann/projets/libtech/src
**
** Made by Swann JAUNASSE
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Tue Feb 14 11:21:16 2017 Swann JAUNASSE
** Last update Fri May 12 23:27:49 2017 Victor LE DANTEC
*/

#include "libtech.h"

void	requires_not_zero(ssize_t nbr, char *src, char *name)
{
  if (nbr == 0)
    {
      print(src, ERROR_STREAM);
      print(" : ", ERROR_STREAM);
      print(name, ERROR_STREAM);
      print_line(" must not be zero", ERROR_STREAM);
    }
}

void	requires_not_empty(char *str, char *src, char *name)
{
  if (str_size(str) == 0)
    {
      print(src, ERROR_STREAM);
      print(" : ", ERROR_STREAM);
      print(name, ERROR_STREAM);
      print_line(" must not be empty", ERROR_STREAM);
    }
}

void    requires_positive(ssize_t number, char *src, char *name)
{
  if (number <= 0)
    {
      print(src, ERROR_STREAM);
      print(" : ", ERROR_STREAM);
      print(name, ERROR_STREAM);
      print_line(" must be positive", ERROR_STREAM);
    }
}

void    requires_positive_or_zero(ssize_t number, char *src, char *name)
{
  if (number < 0)
    {
      print(src, ERROR_STREAM);
      print(" : ", ERROR_STREAM);
      print(name, ERROR_STREAM);
      print_line(" must not be positive or zero", ERROR_STREAM);
    }
}
