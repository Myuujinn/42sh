/*
** executor.h for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Tue May  2 00:17:58 2017 Victor LE DANTEC
** Last update Fri May 19 17:27:36 2017 Victor LE DANTEC
*/

#pragma once

#include <fcntl.h>
#include "42sh.h"
#include "evaluator.h"

/*
** Shortening of the excessive commands in redirect.c
*/

#define FILE_PERMS	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

/*
** Used in the "fork phase" to know if return is parent or child
*/

#define PARENT_ID	0
#define CHILD_ID	1

/*
** Used with pipes to say to the executor to fork or not
** Because it's done by the pipes so we don't need fork sometimes
*/

#define	EXEC_FORK	0
#define EXEC_NO_FORK	1

/*
** Used with executor when checking commands to print errors or not
*/

#define INHIB_ERROR	0
#define NO_INHIB_ERROR	1

void	executor(t_evaluator *, t_shinfo *);
int	executor_fork();
int	executor_wait_for_child(t_shinfo *, pid_t);
int	executor_file_redirects(t_evaluator *);
int	executor_execute(t_evaluator *, t_shinfo *, char);
int 	executor_builtin(t_evaluator *, t_shinfo *);
int	file_stdin_redirect(t_evaluator *);
int	file_stdout_redirect(t_evaluator *);
void	executor_restore_std_fd(t_shinfo *);
int	executor_binary(t_evaluator *, t_shinfo *, char);
int	executor_pipe(t_evaluator *, t_shinfo *);
char	*executor_valid_binary(t_evaluator *, t_shinfo *, char);
int	executor_double_and_pipe(t_evaluator *, t_shinfo *);
void	executor_change_tgrp(pid_t);
