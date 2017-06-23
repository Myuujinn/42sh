/*
** commands.c for 42sh in /home/swann/PSU_2016_42sh
**
** Made by Swann Jaunasse
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Fri Dec 16 11:08:20 2016 Swann Jaunasse
** Last update Sat May 20 23:18:49 2017 Victor LE DANTEC
*/

#include "42sh.h"

char	*g_cmd_names[NB_BUILTINS] =
  {
    "alias",
    "builtins",
    "cd",
    "echo",
    "env",
    "exit",
    "repeat",
    "setenv",
    "unsetenv",
    "which"
  };

int	(*g_cmd_funcs[NB_BUILTINS])(t_shinfo *, t_strlist *) =
{
  &cmd_alias,
  &cmd_builtins,
  &cmd_cd,
  &cmd_echo,
  &cmd_env,
  &cmd_exit,
  &cmd_repeat,
  &cmd_setenv,
  &cmd_unsetenv,
  &cmd_which
};

t_bool		cmd_is_builtin(t_strlist *cmd)
{
  size_t	count;

  if (cmd->size > 0)
    {
      count = 0;
      while (count < NB_BUILTINS)
	{
	  if (str_compare(cmd->data[0], g_cmd_names[count]) == 0)
	    return (TRUE);
	  count++;
	}
    }
  return (FALSE);
}
