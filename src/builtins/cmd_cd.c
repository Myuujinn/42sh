/*
** cmd_cd.c for 42sh in /home/swann/PSU_2016_42sh
**
** Made by Swann Jaunasse
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Fri Dec 16 11:08:20 2016 Swann Jaunasse
** Last update Thu Apr 13 00:51:18 2017 Victor LE DANTEC
*/

#include <sys/stat.h>
#include "42sh.h"

char		*file_name(char *path)
{
  while (str_contains(path, '/'))
    path++;
  return (path);
}

char	*get_home(t_strlist *env)
{
  char	*home;

  if ((home = strlist_find(env, "HOME=")) == NULL)
    return ("/");
  return (home + 5);
}

int		change_dir(t_shinfo *info, char *path)
{
  char		*cwd;
  char		*old_pwd;
  struct stat	file_info;

  if (access(path, F_OK) != 0)
    return (error_int(path, "No such file or directory.", 1));
  if (stat(path, &file_info) == -1)
    exit_error("[42sh]{cmd_cd}(change_dir)", STAT_ERR, FAILURE);
  if (!S_ISDIR(file_info.st_mode))
    return (error_int(path, "Not a directory.", 1));
  if ((old_pwd = malloc(sizeof(char) * 1024)) == NULL)
    return (error_int("[42sh]{cmd_cd}(change_dir)", MALLOC_ERROR, 1));
  if (getcwd(old_pwd, 1024) == NULL)
    exit_error("[42sh]{cmd_cd}(change_dir)", GETCWD_ERR, FAILURE);
  info->old_pwd = old_pwd;
  if ((cwd = malloc(sizeof(char) * 1024)) == NULL)
    return (error_int("[42sh]{cmd_cd}(change_dir)", MALLOC_ERROR, 1));
  if (chdir(path) < 0)
    return (error_int(path, "Permission denied.", 1));
  if (getcwd(cwd, 1024) == NULL)
    exit_error("[42sh]{cmd_cd}(change_dir)", GETCWD_ERR, FAILURE);
  set_env(info->env, "PWD", cwd);
  return (SUCCESS_STATUS);
}

int		cmd_cd(t_shinfo *info, t_strlist *cmd)
{
  char		*path;

  if (cmd->size > 2)
    return (error_int("cd", "Too many arguments.", 1));
  if (cmd->size < 2)
    path = get_home(info->env);
  else
    {
      if (str_compare(cmd->data[1], "-") == 0)
	path = info->old_pwd;
      else
	path = cmd->data[1];
    }
  return (change_dir(info, path));
}
