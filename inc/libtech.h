/*
** libtech.h for libtech in /home/swann/Projets/LibTech
**
** Made by Swann JAUNASSE
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Tue Feb 14 11:21:16 2017 Swann JAUNASSE
** Last update	Mon Feb 20 12:48:46 2017 Swann JAUNASSE
*/

#pragma once

#include "../lib/libtech/inc/char.h"
#include "../lib/libtech/inc/string.h"
#include "../lib/libtech/inc/strlist.h"
#include "../lib/libtech/inc/parse.h"
#include "../lib/libtech/inc/print.h"
#include "../lib/libtech/inc/error.h"
#include "../lib/libtech/inc/crash.h"
#include "../lib/libtech/inc/contracts.h"
#include "../lib/libtech/inc/tuple.h"

const char		*g_binary_name;

#define SUCCESS_STATUS  0
#define FAILURE_STATUS  84
#define FAILURE		FAILURE_STATUS

#define INPUT_STREAM    STDIN_FILENO
#define OUTPUT_STREAM   STDOUT_FILENO
#define ERROR_STREAM    STDERR_FILENO
