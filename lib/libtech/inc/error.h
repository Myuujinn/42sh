/*
** error.h for libtech in /home/swann/projets/libtech/inc
**
** Made by Swann Jaunasse
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Tue Dec  6 14:25:29 2016 Swann Jaunasse
** Last update Mon Apr 10 20:50:33 2017 Victor LE DANTEC
*/

#pragma once

#define MALLOC_ERROR	"Cannot allocate space in memory. Maybe RAM is full."

void    warning(char *src, char *msg);
void    error(char *src, char *msg);
int     error_int(char *src, char *msg, int ret);
void    *error_ptr(char *src, char *msg, void *ret);
