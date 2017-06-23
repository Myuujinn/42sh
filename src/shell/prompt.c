/*
** prompt.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Tue Apr 11 15:28:04 2017 Victor LE DANTEC
** Last update Fri May 12 23:26:24 2017 Victor LE DANTEC
*/

#include <linux/limits.h>
#include <time.h>
#include "42sh.h"

static char	*get_directory(char *dir)
{
  ssize_t	i;

  if (str_compare(dir, "/") == 0)
    return ("/");
  i = str_size(dir) - 1;
  while (i != -1 && dir[i] != '/')
    i--;
  if (i == -1)
    return (dir);
  return (dir + i + 1);
}

static char	*get_current_time()
{
  time_t	cur_time;
  char		*time_str;

  if ((cur_time = time(NULL)) == (time_t)-1)
    return (NULL);
  if ((time_str = ctime(&cur_time)) == NULL)
    return (NULL);
  time_str += 11;
  return (time_str);
}

void	display_prompt(t_shinfo *info)
{
  char	*time;
  char	cwd[PATH_MAX];

  if (isatty(STDIN_FILENO) != 0)
    {
      if ((time = get_current_time()) != NULL)
	printf("\x1b[35m [%.5s] \033[0m", time);
      if (getcwd(cwd, PATH_MAX) != NULL)
	printf("\x1b[34m [%s] \033[0m", get_directory(cwd));
      if (info->status != 0)
	printf("\x1b[31m [%d] \033[0m", info->status);
      printf("\033[0;32m $> \033[0m");
      fflush(stdout);
    }
}
