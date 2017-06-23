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

#include "char.h"
#include "string.h"
#include "strlist.h"
#include "list.h"
#include "parse.h"
#include "print.h"
#include "error.h"
#include "crash.h"
#include "contracts.h"
#include "tuple.h"

const char      *g_binary_name;

#define SUCCESS_STATUS  0
#define FAILURE_STATUS  84
#define FAILURE		FAILURE_STATUS

#define INPUT_STREAM    0
#define OUTPUT_STREAM   1
#define ERROR_STREAM    2
