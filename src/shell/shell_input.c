/*
** shell_input.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Tue Apr 11 15:41:52 2017 Victor LE DANTEC
** Last update Wed May 24 12:29:07 2017 Victor LE DANTEC
*/

#include <string.h>
#include "42sh.h"

char	*remove_newline(char *line)
{
  if (line != NULL && strlen(line) != 0 && line[strlen(line) - 1] == '\n')
    line[strlen(line) - 1] = '\0';
  while (line != NULL && (*line == ' ' || *line == '\t'))
    line++;
  return (line);
}

char	*get_input(FILE *fp)
{
  char	*input;

  if ((input = malloc(sizeof(char) * READ_SIZE)) == NULL)
    exit_error("[42sh]{shell_input}(get_input)", MALLOC_ERROR, FAILURE);
  return (remove_newline(fgets(input, READ_SIZE, fp)));
}
