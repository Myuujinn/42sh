/*
** 42shrc.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sat May 20 17:03:16 2017 Victor LE DANTEC
** Last update Sat May 20 18:41:13 2017 Victor LE DANTEC
*/

#include <sys/stat.h>
#include "42sh.h"

static int	check_file()
{
  struct stat	stats;

  stat(".42shrc", &stats);
  return (S_ISREG(stats.st_mode));
}

void	load_42shrc(t_shinfo *info)
{
  FILE	*fp;
  char	*line;

  if (g_debug >= 2)
    return ;
  if ((check_file() == 0) || (fp = fopen(".42shrc", "r")) == NULL)
    return ;
  (g_debug % 2 == 1) ? puts("Loading 42shrc..") : 0;
  while ((line = get_input(fp)) != NULL)
    if (line[0] != '\0')
      process_command(info, line);
  if (fclose(fp) == -1)
    error("[42sh]{42shrc}(load_42shrc)", FCLOSE_ERR);
}
