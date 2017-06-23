/*
** change_tgrp.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Fri May 19 16:17:52 2017 Victor LE DANTEC
** Last update Fri May 19 17:22:48 2017 Victor LE DANTEC
*/

#include <unistd.h>

void	executor_change_tgrp(pid_t pid)
{
  if (isatty(STDIN_FILENO))
    {
      tcsetpgrp(STDIN_FILENO, pid);
      tcsetpgrp(STDERR_FILENO, pid);
      tcsetpgrp(STDOUT_FILENO, pid);
    }
}
