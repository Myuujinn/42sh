/*
** char.h for libtech in /home/swann/projets/libtech/inc
**
** Made by Swann Jaunasse
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Tue Dec  6 14:25:29 2016 Swann Jaunasse
** Last update Mon Jan  9 20:43:52 2017 Swann Jaunasse
*/

#pragma once

#include "base.h"

t_bool	ch_isupper(char ch);
t_bool	ch_islower(char ch);
t_bool	ch_isletter(char ch);
t_bool	ch_isalphanum(char ch);
t_bool	ch_iseol(char ch);
t_bool	ch_isdigit(char ch);
t_bool	ch_iswhitespace(char ch);
t_bool	ch_ispunctuation(char ch);
t_bool	ch_isidentifier(char ch);
