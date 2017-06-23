/*
** signal_init.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Wed Apr 19 22:50:28 2017 Victor LE DANTEC
** Last update Sat May 20 17:42:59 2017 Victor LE DANTEC
*/

#include <signal.h>
#include "42sh.h"

static void		sigint_handle()
{
  static t_shinfo	*info;

  info = get_shinfo(NULL);
  info->status = 1;
  putchar('\n');
  display_prompt(info);
}

void	init_signal()
{
  if (signal(SIGQUIT, SIG_IGN) == SIG_ERR ||
      signal(SIGTTIN, SIG_IGN) == SIG_ERR ||
      signal(SIGTTOU, SIG_IGN) == SIG_ERR ||
      signal(SIGINT, sigint_handle) == SIG_ERR)
    error("[42sh]{signal_init}(init_signal)", SIGNAL_ERR);
}
