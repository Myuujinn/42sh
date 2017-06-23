/*
** base.h for libtech in /home/swann/projets/libtech/inc
**
** Made by Swann Jaunasse
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Tue Dec  6 14:25:29 2016 Swann Jaunasse
** Last update Mon Jan  9 20:43:52 2017 Swann Jaunasse
*/

#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef unsigned char t_byte;
typedef unsigned char t_bool;

#define TRUE	1
#define FALSE	0

typedef struct	s_mem
{
  size_t	count;
  size_t	size;
  void		**data;
}		t_mem;

t_mem		*memory();
void		*create(size_t size);
void		fill(char *ptr, char ch, size_t times);
void		wipe();
void		destroy(void *ptr);
