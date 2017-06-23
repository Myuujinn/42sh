/*
** print.h for libtech in /home/swann/projets/libtech/inc
**
** Made by Swann JAUNASSE
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Tue Dec  6 14:25:29 2016 Swann JAUNASSE
** Last update Mon Jan  9 20:43:25 2017 Swann JAUNASSE
*/

#pragma once

void	print(char *str, int stream);
void	print_char(char c, int stream);
void    print_nbr(ssize_t nbr, int stream);
void	print_line(char *str, int stream);
void	print_strlist(t_strlist *list, int stream);
