/*
** print.c for libtech in /home/swann/projets/libtech/src
** 
** Made by Swann JAUNASSE
** Login   <swann.jaunasse@epitech.eu>
** 
** Started on  Fri Dec 16 11:08:20 2016 Swann JAUNASSE
** Last update Fri Dec 16 11:27:06 2016 Swann JAUNASSE
*/

#include "libtech.h"

void		print_char(char c, int stream)
{
  requires_positive_or_zero(stream,
			    "[libtech.a](print.c){print_char}", "stream");
  write(stream, &c, 1);
}

void		print(char *str, int stream)
{
  requires_not_null(str, "[libtech.a](print.c){print}", "str");
  requires_positive_or_zero(stream,
			    "[libtech.a](print.c){print}", "stream");
  write(stream, str, str_size(str));
}

void		print_line(char *str, int stream)
{
  requires_not_null(str,
		     "[libtech.a](print.c){print_line}", "str");
  requires_positive_or_zero(stream,
			    "[libtech.a](print.c){print_line}", "stream");
  print(str, stream);
  print_char('\n', stream);
}

void		print_nbr(ssize_t nbr, int stream)
{
  requires_positive_or_zero(stream,
			    "[libtech.a](print.c){print_nbr}", "stream");
  if (nbr < 0)
    {
      nbr = -nbr;
      print_char('-', stream);
    }
  if (nbr >= 10)
    print_nbr(nbr / 10, stream);
  print_char(nbr % 10 + '0', stream);
}

void		print_strlist(t_strlist *list, int stream)
{
  size_t	count;

  requires_not_null(list, "[libtech.a](print.c){print_strlist}", "list");
  requires_positive_or_zero(stream,
			    "[libtech.a](print.c){print_strlist}", "stream");
  count = 0;
  while (count < list->size)
    {
      if (list->data[count] != NULL)
	print_line(list->data[count], stream);
      count++;
    }
}
