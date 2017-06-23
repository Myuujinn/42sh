/*
** list.h for libtech in /home/swann/projets/libtech/inc
**
** Made by Swann Jaunasse
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Tue Dec  6 14:25:29 2016 Swann Jaunasse
** Last update Mon Jan  9 20:43:52 2017 Swann Jaunasse
*/

#pragma once

#include "base.h"

typedef struct	s_list
{
  void		**data;
  size_t	size;
}		t_list;

t_list		*list_create(void **array);
void		list_destroy(t_list *list, t_bool destroy_content);
void		list_append(t_list *list, void *item);
void		list_remove(t_list *list, size_t index);
t_list		*list_concat(t_list *list1, t_list *list2);
