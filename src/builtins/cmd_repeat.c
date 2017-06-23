/*
** cmd_repeat.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Thu May 18 17:21:19 2017 Victor LE DANTEC
** Last update Wed May 24 12:24:31 2017 Victor LE DANTEC
*/

#include "42sh.h"

static int	is_number(char *arg)
{
  size_t	i;

  i = 0;
  while (arg[i] != '\0')
    {
      if (arg[i] < '0' || arg[i] > '9')
	return (FAILURE_STATUS);
      i++;
    }
  return (SUCCESS_STATUS);
}

static void	cmd_repeat_launch(t_strlist *commands, t_shinfo *info,
				  int need_to_repeat)
{
  int		times;
  char		*save;

  times = 0;
  commands->data++;
  commands->size--;
  save = str_clone(commands->data[0]);
  while (times < need_to_repeat)
    {
      commands->data[0] = strdup(save);
      if (evaluator(info, commands) == FAILURE_STATUS)
	info->status = 1;
      times++;
    }
}

int	cmd_repeat(t_shinfo *info, t_strlist *commands)
{
  commands->data++;
  commands->size--;
  if (commands->size < 2)
    return (error_int("repeat", "Too few arguments.", 1));
  if (is_number(commands->data[0]) == FAILURE_STATUS)
    return (error_int("repeat", "Badly formed number.", 1));
  cmd_repeat_launch(commands, info, atoi(commands->data[0]));
  return (SUCCESS_STATUS);
}
