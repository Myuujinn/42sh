/*
** default_env.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Wed Apr 12 10:32:59 2017 Victor LE DANTEC
** Last update Wed Apr 12 10:34:01 2017 Victor LE DANTEC
*/

#include <linux/limits.h>
#include "42sh.h"

t_strlist	*default_env()
{
  t_strlist	*env;
  char		pwd[PATH_MAX];

  if ((env = malloc(sizeof(t_strlist))) == NULL)
    exit_error("[42sh]{42sh}(default_env)",
               MALLOC_ERROR, FAILURE_STATUS);
  if ((env->data = malloc(sizeof(char *) * 4)) == NULL)
    exit_error("[42sh]{42sh}(default_env)",
               MALLOC_ERROR, FAILURE_STATUS);
  if (getcwd(pwd, sizeof(pwd)) == NULL)
    exit_error("[42sh]{42sh}(default_env)", GETCWD_ERR, FAILURE);
  env->size = 3;
  env->data[0] = str_concat("PWD=", pwd);
  env->data[1] = str_concat("HOME=", "/");
  env->data[2] = str_concat("PATH=", "/usr/bin");
  env->data[3] = NULL;
  return (env);
}
