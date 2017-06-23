/*
** strlist.h for libtech in /home/swann/projets/libtech/inc
**
** Made by Swann JAUNASSE
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Tue Dec  6 14:25:29 2016 Swann JAUNASSE
** Last update Mon Jan  9 20:43:52 2017 Swann JAUNASSE
*/

#pragma once

#include "base.h"

typedef struct	s_strlist
{
  char		**data;
  size_t	size;
}		t_strlist;

t_strlist	*strlist_create(char **array);
void		strlist_destroy(t_strlist *list, t_bool destroy_content);
void		strlist_append(t_strlist *list, char *str);
void		strlist_remove(t_strlist *list, size_t index);
t_strlist       *strlist_concat(t_strlist *list1, t_strlist *list2);
char		*strlist_find(t_strlist *list, char *str);
char		*strlist_contains(t_strlist *list, char *str);
ssize_t		strlist_index(t_strlist *list, char *str);
