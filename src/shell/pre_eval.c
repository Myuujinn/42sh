/*
** pre_eval.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Fri Apr 21 13:41:37 2017 Victor LE DANTEC
** Last update Sat May 20 02:54:45 2017 Victor LE DANTEC
*/

#include "42sh.h"

static int	is_illegal(char *var)
{
  size_t	i;

  i = 0;
  while (var[++i] != '\0')
    if (ch_isalphanum(var[i]) == FALSE)
      return (FAILURE_STATUS);
  return (SUCCESS_STATUS);
}

static int	replace_with_var(t_shinfo *info, t_strlist *cmds, size_t i)
{
  char		*env_variable;

  if (is_illegal(cmds->data[i]) == FAILURE_STATUS)
    {
      printf("Illegal variable name.\n");
      info->status = 1;
      return (FAILURE_STATUS);
    }
  if ((env_variable = get_env(info->env, cmds->data[i] + 1)) == NULL)
    {
      printf("%s: Undefined variable.\n", cmds->data[i] + 1);
      info->status = 1;
      return (FAILURE_STATUS);
    }
  free(cmds->data[i]);
  cmds->data[i] = str_clone(env_variable);
  return (SUCCESS_STATUS);
}

int		pre_eval(t_shinfo *info, t_strlist *cmds)
{
  size_t	i;

  i = 0;
  while (i != cmds->size)
    {
      if (cmds->data[i][0] == '$' && cmds->data[i][1] != '\0'
	  && replace_with_var(info, cmds, i) == FAILURE_STATUS)
	return (FAILURE_STATUS);
      i++;
    }
  return (SUCCESS_STATUS);
}
