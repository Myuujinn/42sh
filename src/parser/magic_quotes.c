/*
** magic_quotes.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Mon Apr 24 14:04:51 2017 Victor LE DANTEC
** Last update Mon Apr 24 15:04:41 2017 Victor LE DANTEC
*/

#include "parser.h"

char		toggle_magic_quotes(char toggle)
{
  static char	magic;

  if (toggle == ADD_QUOTES)
    {
      if (magic == 1)
	magic = 0;
      else
	magic = 1;
    }
  else if (toggle == RESET_QUOTES)
    magic = 0;
  return (magic);
}
