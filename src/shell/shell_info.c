/*
** shell_info.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Tue Apr 11 19:57:05 2017 Victor LE DANTEC
** Last update Sat May 20 17:24:44 2017 Victor LE DANTEC
*/

#include "42sh.h"

t_shinfo	*get_shinfo(t_shinfo *info)
{
  static t_shinfo	*shinfo;

  if (info == NULL)
    return (shinfo);
  shinfo = info;
  return (NULL);
}

static void	alias_create(t_shinfo *info)
{
  if ((info->alias.name = strlist_create(NULL)) == NULL)
    exit_error("[42sh]{shell_info}(alias_create)", MALLOC_ERROR, FAILURE);
  if ((info->alias.value = strlist_create(NULL)) == NULL)
    exit_error("[42sh]{shell_info}(alias_create)", MALLOC_ERROR, FAILURE);
  info->alias.size = 0;
}

t_shinfo	*shinfo_create(t_strlist *environment)
{
  t_shinfo	*info;

  if ((info = malloc(sizeof(t_shinfo))) == NULL)
    exit_error("[42sh]{shell_info}(shinfo_create)",
               MALLOC_ERROR, FAILURE_STATUS);
  if ((info->std_save[0] = dup(STDIN_FILENO)) == -1
      || (info->std_save[1] = dup(STDOUT_FILENO)) == -1)
    exit_error("[42sh]{shell_info}(shinfo_create)", DUP_ERR, FAILURE);
  info->env = environment;
  info->status = 0;
  info->old_pwd = NULL;
  info->pid = getpid();
  alias_create(info);
  return (info);
}
