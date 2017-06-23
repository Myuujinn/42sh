/*
** error.h for libtech in /home/swann/projets/libtech/inc
**
** Made by Swann Jaunasse
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Tue Dec  6 14:25:29 2016 Swann Jaunasse
** Last update Tue Dec 20 20:37:45 2016 Swann Jaunasse
*/

#pragma once

#define APP_CRASHED	"An internal error occured. The program crashed."

void	crashed();
void	handle_crash();
void	exit_error(char *src, char *msg, int ret);
