/*
** strlist1.c for libtech in /home/swann/Projets/libtech/src
**
** Made by Swann Jaunasse
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Fri Dec 16 11:04:40 2016 Swann Jaunasse
** Last update Sat May 20 02:17:37 2017 Victor LE DANTEC
*/

#include "libtech.h"

void		strlist_remove(t_strlist *list, size_t index)
{
  size_t	count;
  char		found;
  char		**new_data;

  requires_not_null(list, "[libtech.a](strlist1.c){strlist_create}", "list");
  if (list->size > 0 && index < list->size)
    {
      if ((new_data = malloc(sizeof(char*) * (list->size + 1))) == NULL)
	exit_error("libtech", MALLOC_ERROR, 84);
      count = found = 0;
      while (count + found < list->size)
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

t_strlist	*strlist_create(char **array)
{
  t_strlist	*list;
  size_t	count;

  if ((list = malloc(sizeof(t_strlist))) == NULL)
    exit_error("[libtech.a](strlist1.c){strlist_create}",
		  MALLOC_ERROR, 84);
  count = 0;
  while (array != NULL && array[count] != NULL)
    count++;
  list->size = count;
  list->data = NULL;
  if (list->size > 0)
    {
      if ((list->data = malloc(sizeof(char*) * (count + 1))) == NULL)
	exit_error("[libtech.a](strlist1.c){strlist_create}",
		      MALLOC_ERROR, 84);
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

void		strlist_destroy(t_strlist *list, t_bool destroy_content)
{
  size_t	count;

  if (list != NULL)
    {
      if (list->data != NULL)
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
