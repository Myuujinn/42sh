/*
** cmd_exec.c for 42sh in /home/swann/PSU_2016_42sh
**
** Made by Swann Jaunasse
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Fri Dec 16 11:08:20 2016 Swann Jaunasse
** Last update Sat May 20 16:55:53 2017 Victor LE DANTEC
*/

#include <sys/time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "42sh.h"

static char	*g_signal_message[31] =
  {
    "Hangup",
    "",
    "Quit",
    "Illegal instruction",
    "Trace trap",
    "Abort",
    "Bus error",
    "Floating exception",
    "Killed",
    "User defined signal 1",
    "Segmentation fault",
    "User defined signal 2",
    "Broken pipe",
    "Alarm clock",
    "Terminated",
    "Stack fault",
    "Child process has stopped or exited, changed",
    "Continue executing, if stopped",
    "Stopped",
    "Terminal stop signal",
    "Background process trying to read, from TTY",
    "Background process trying to write, to TTY",
    "Urgent condition on socket",
    "CPU limit exceeded",
    "File size limit exceeded",
    "Virtual alarm clock",
    "Profiling alarm clock",
    "Window size change",
    "I/O now possible",
    "Power failure restart",
    "Unused signal"
  };

int		handle_status(int status)
{
  char		*message;
  int		ssignal;

  ssignal = 0;
  if (WIFEXITED(status))
    return (WEXITSTATUS(status));
  else if (WIFSIGNALED(status))
    ssignal = WTERMSIG(status);
  else if (WIFSTOPPED(status))
    ssignal = WSTOPSIG(status);
  message = g_signal_message[ssignal - 1];
  if (WCOREDUMP(status))
    message = str_concat(message, " (core dumped)");
  print_line(message, 2);
  return ((ssignal != 3) ? ssignal + 128 : 1);
}
