/*
** strlist2.c for libtech in /home/swann/Projets/libtech/src
**
** Made by Swann JAUNASSE
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Fri Dec 16 11:04:40 2016 Swann JAUNASSE
** Last update Sat May 20 02:18:15 2017 Victor LE DANTEC
*/

#include "libtech.h"

char		*strlist_find(t_strlist *list, char *str)
{
  size_t	count;

  requires_not_null(list, "[libtech.a](strlist2.c){strlist_find}", "list");
  requires_not_empty(str, "[libtech.a](strlist2.c){strlist_find}", "str");
  count = 0;
  while (count < list->size)
    {
      if (str_start_with(list->data[count], str))
	return (list->data[count]);
      count++;
    }
  return (NULL);
}

char            *strlist_contains(t_strlist *list, char *str)
{
  size_t        count;

  requires_not_null(list, "[libtech.a](strlist2.c){strlist_contains}", "list");
  requires_not_empty(str, "[libtech.a](strlist2.c){strlist_contains}", "str");
  count = 0;
  while (count < list->size)
    {
      if (str_compare(list->data[count], str) == 0)
        return (list->data[count]);
      count++;
    }
  return (NULL);
}

ssize_t		strlist_index(t_strlist *list, char *str)
{
  size_t	count;

  requires_not_null(list, "[libtech.a](strlist2.c){strlist_index}", "list");
  requires_not_empty(str, "[libtech.a](strlist2.c){strlist_index}", "str");
  count = 0;
  while (count < list->size)
    {
      if (str_start_with(list->data[count], str))
        return (count);
      count++;
    }
  return (-1);
}

void		strlist_append(t_strlist *list, char *str)
{
  size_t	count;
  char		**new_data;

  requires_not_null(list, "[libtech.a](strlist2.c){strlist_append}", "list");
  if ((new_data = malloc(sizeof(char *) * (list->size + 2))) == NULL)
    exit_error("[libtech.a](strlist2.c){strlist_append}", MALLOC_ERROR, 84);
  count = 0;
  while (count < list->size)
    {
      new_data[count] = list->data[count];
      count++;
    }
  new_data[count++] = str;
  new_data[count] = NULL;
  free(list->data);
  list->data = new_data;
  list->size++;
}

t_strlist	*strlist_concat(t_strlist *list1, t_strlist *list2)
{
  t_strlist	*newlist;
  size_t	count;

  requires_not_null(list1, "[libtech.a](strlist2.c){strlist_concat}", "list1");
  requires_not_null(list2, "[libtech.a](strlist2.c){strlist_concat}", "list2");
  if ((newlist = strlist_create(NULL)) == NULL)
    exit_error("[libtech.a](strlist2.c){strlist_concat}",
	       "strlist creation failed", 84);
  count = 0;
  while (count < list1->size)
    strlist_append(newlist, list1->data[count++]);
  count = 0;
  while (count < list2->size)
    strlist_append(newlist, list2->data[count++]);
  return (newlist);
}
