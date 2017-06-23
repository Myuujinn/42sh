/*
** string.h for libtech in /home/swann/projets/libtech/inc
**
** Made by Swann Jaunasse
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Tue Dec  6 14:25:29 2016 Swann JAUNASSE
** Last update Sun Mar 19 15:28:17 2017 Swann JAUNASSE
*/

#pragma once

#include "base.h"
#include "strlist.h"

size_t		str_size(char *str);
char		str_compare(char *s1, char *s2);
char		*str_upper(char *str);
char		*str_lower(char *str);
char		*str_truncate(char *str, size_t start, size_t len);
char		*str_reverse(char *str);
char		*str_concat(char *s1, char *s2);
char            *str_clone(char *str);
char		*str_append(char *str, char c);
void 		str_copy(char *src, char *dest, size_t size);
t_bool		str_isalphanum(char *str);
t_bool		str_contains(char *str, char ch);
t_bool		str_start_with(char *str, char *pattern);
t_bool          str_end_with(char *str, char *pattern);
t_strlist	*str_split(char *str, char *sep);
ssize_t		str_first(char *str, char ch);
size_t          str_count(char *str, char ch);
char		*str_replace(char *str, char old, char new);
