/*
** contracts.h for libtech in /home/swann/projets/libtech/inc
**
** Made by Swann JAUNASSE
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Tue Feb 14 11:21:16 2017 Swann JAUNASSE
** Last update  Mon Feb 20 12:48:46 2017 Swann JAUNASSE
*/

#pragma once

#include "base.h"
#include "string.h"

void	requires(t_bool assertion, char *src);
void	requires_not_null(void *obj, char *src, char *name);
void	requires_not_zero(ssize_t nbr, char *src, char *name);
void	requires_not_empty(char *str, char *src, char *name);
void	requires_positive(ssize_t nbr, char *src, char *name);
void	requires_positive_or_zero(ssize_t, char *src, char *name);
