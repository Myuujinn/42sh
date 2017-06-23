/*
** cmd_pwd.c for 42sh in /home/swann/PSU_2016_42sh
**
** Made by Swann Jaunasse
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Fri Dec 16 11:08:20 2016 Swann Jaunasse
** Last update Tue Apr 11 20:02:19 2017 Victor LE DANTEC
*/

#include "42sh.h"

t_strlist	*get_path(t_strlist *env)
{
  char		*path;

  if ((path = strlist_find(env, "PATH=")) == NULL)
    return (NULL);
  return (str_split(path + 5, ":"));
}

char		*path_join(char *path1, char *path2)
{
  return (str_concat(str_concat(path1, "/"), path2));
}

char		*search_path(t_strlist *env, char *binary)
{
  char		*join;
  size_t	count;
  t_strlist	*paths;

  paths = get_path(env);
  count = 0;
  while (count < paths->size)
    {
      join = path_join(paths->data[count], binary);
      if (access(join, F_OK) == 0)
	return (join);
      count++;
    }
  return (NULL);
}

char		*search_binary(t_strlist *env, char *binary)
{
  char		*path;
  char		*join;

  path = get_env(env, "PATH=");
  if (str_contains(binary, '/'))
    {
      if (access(binary, F_OK) == 0)
        return (binary);
    }
  else if (path == NULL)
    {
      join = path_join("/usr/bin", binary);
      if (access(join, F_OK) == 0)
        return (join);
    }
  else
    return (search_path(env, binary));
  return (NULL);
}

int		cmd_path(t_shinfo *info, t_strlist *cmd)
{
  (void)cmd;
  print_strlist(get_path(info->env), 1);
  return (SUCCESS_STATUS);
}
