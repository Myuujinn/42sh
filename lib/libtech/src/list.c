/*
** list.c for libtech in /home/swann/projets/libtech/src
**
** Made by Swann JAUNASSE
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Fri Dec 16 11:04:40 2016 Swann JAUNASSE
** Last update Wed Dec 28 17:06:29 2016 Swann JAUNASSE
*/

#include "libtech.h"

void		list_remove(t_list *list, size_t index)
{
  size_t	count;
  char		found;
  void		**new_data;

  requires_not_null(list, "[libtech.a](list.c){list_remove}", "list");
  if (list->size > 0 && index < list->size)
    {
      if ((new_data = malloc(sizeof(void *) * (list->size + 1))) == NULL)
	error("[libtech.a](list.c){list_remove}", MALLOC_ERROR);
      count = found = 0;
      while (count + found < list->size - 1)
	{
	  if (count == index && !found)
	    found = 1;
	  else
	    {
	      new_data[count] = list->data[count + found];
	      count++;
	    }
	}
      new_data[count] = NULL;
      free(list->data);
      list->data = new_data;
      list->size--;
    }
}

t_list		*list_create(void **array)
{
  t_list	*list;
  size_t	count;

  if ((list = malloc(sizeof(t_list))) == NULL)
    return (error_ptr("[libtech.a](list.c){list_create}", MALLOC_ERROR, NULL));
  count = 0;
  while (array != NULL && array[count] != NULL)
    count++;
  list->size = count;
  list->data = NULL;
  if (list->size > 0)
    {
      if ((list->data = malloc(sizeof(void *) * (count + 1))) == NULL)
	return (error_ptr("[libtech.a](list.c){list_create}", MALLOC_ERROR, NULL));
      count = 0;
      while (count < list->size)
	{
	  list->data[count] = array[count];
	  count++;
	}
      list->data[count] = NULL;
    }
  return (list);
}

void		list_destroy(t_list *list, t_bool destroy_content)
{
  size_t	count;

  if (list != NULL)
    {
      if (list->data)
	{
	  if (destroy_content)
	    {
	      count = 0;
	      while (count < list->size)
		free(list->data[count]);
	    }
	  free(list->data);
	}
      free(list);
    }
}

void            list_append(t_list *list, void *str)
{
  size_t        count;
  void	        **new_data;

  requires_not_null(list, "[libtech.a](list.c){list_append}", "list");
  requires_not_null(str, "[libtech.a](list.c){list_append}", "str");
  if ((new_data = malloc(sizeof(void *) * (list->size + 2))) == NULL)
    error("[libtech.a](list.c){list_append}", MALLOC_ERROR);
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

t_list       *list_concat(t_list *list1, t_list *list2)
{
  t_list     *new_list;
  size_t        count;

  requires_not_null(list1, "[libtech.a](list.c){list_concat}", "list1");
  requires_not_null(list2, "[libtech.a](list.c){list_concat}", "list2");
  if ((new_list = list_create(NULL)) == NULL)
    return (error_ptr("[libtech.a](list.c){list_concat}",
		  "list creation failed", NULL));
  count = 0;
  while (count < list1->size)
      list_append(new_list, list1->data[count++]);
  count = 0;
  while (count < list2->size)
      list_append(new_list, list2->data[count++]);
  return (new_list);
}
