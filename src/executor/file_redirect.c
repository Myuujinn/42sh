/*
** file_redirect.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Tue May  2 00:41:42 2017 Victor LE DANTEC
** Last update Sat May 20 00:10:53 2017 Victor LE DANTEC
*/

#include "executor.h"

static int	has_stdin_redir(char redirection)
{
  if ((redirection & LESS_BSHIFT) == LESS_BSHIFT)
    return (LESS_BSHIFT);
  if ((redirection & DOUBLE_LESS_BSHIFT) == DOUBLE_LESS_BSHIFT)
    return (DOUBLE_LESS_BSHIFT);
  return (SUCCESS_STATUS);
}

static int	has_stdout_redir(char redirection)
{
  if ((redirection & GREATER_BSHIFT) == GREATER_BSHIFT)
    return (GREATER_BSHIFT);
  if ((redirection & DOUBLE_GREATER_BSHIFT) == DOUBLE_GREATER_BSHIFT)
    return (DOUBLE_GREATER_BSHIFT);
  return (SUCCESS_STATUS);
}

static void	double_stdin_redir(t_evaluator *eval)
{
  int		stdin_pipes[2];
  char		buffer[READ_SIZE];

  if (pipe(stdin_pipes) == -1)
    exit_error("[42sh]{file_redirect}(double_stdin_redir)", PIPE_ERR, FAILURE);
  buffer[0] = '\0';
  while (str_compare(remove_newline(buffer),
		     eval->commands[eval->index].stdin_redir) != 0)
    {
      write(stdin_pipes[1], buffer, strlen(buffer));
      if (buffer[0] != '\0')
	write(stdin_pipes[1], "\n", 1);
      write(STDOUT_FILENO, "? ", 2);
      if (fgets(buffer, READ_SIZE, stdin) == NULL)
	break;
    }
  if (close(STDIN_FILENO) == -1 || close(stdin_pipes[1]) == -1)
    exit_error("[42sh]{file_redirect}(double_stdin_redirect)",
	       CLOSE_ERR, FAILURE);
  if (dup(stdin_pipes[0]) == -1)
    exit_error("[42sh]{file_redirect}(double_stdin_redirect)",
	       DUP_ERR, FAILURE);
}

int	file_stdin_redirect(t_evaluator *eval)
{
  int	fd;

  if (has_stdin_redir(eval->commands[eval->index].redir_type) == LESS_BSHIFT)
    {
      if ((fd = open(eval->commands[eval->index].stdin_redir, O_RDONLY)) == -1)
	return (error_int(eval->commands[eval->index].stdin_redir,
			  "Permission denied.", 1));
      if (close(STDIN_FILENO) == -1)
	exit_error("[42sh]{file_redirect}(file_stdin_redirect)",
		   CLOSE_ERR, FAILURE);
      if (dup(fd) == -1)
	exit_error("[42sh]{file_redirect}(file_stdin_redirect)",
		   DUP_ERR, FAILURE);
    }
  else if (has_stdin_redir(eval->commands[eval->index].redir_type) ==
	   DOUBLE_LESS_BSHIFT)
    double_stdin_redir(eval);
  return (SUCCESS_STATUS);
}

int	file_stdout_redirect(t_evaluator *eval)
{
  int	fd;
  int	redir;

  if ((redir = has_stdout_redir
       (eval->commands[eval->index].redir_type)) > 0)
    {
      if (redir == DOUBLE_GREATER_BSHIFT)
	{
	  if ((fd = open(eval->commands[eval->index].stdout_redir,
			 O_APPEND | O_CREAT | O_RDWR, FILE_PERMS)) == -1)
	    return (error_int(eval->commands[eval->index].stdout_redir,
			      "Permission denied.", 1));
	}
      else if ((fd = open(eval->commands[eval->index].stdout_redir,
			  O_CREAT | O_RDWR | O_TRUNC, FILE_PERMS)) == -1)
	return (error_int(eval->commands[eval->index].stdout_redir,
			  "Permission denied.", 1));
      if (close(OUTPUT_STREAM) == -1)
	exit_error("[42sh]{file_redirect}(file_stdout_redirect)",
		   CLOSE_ERR, FAILURE);
      if (dup(fd) == -1)
	exit_error("[42sh]{file_redirect}(file_stdout_redirect)",
		   DUP_ERR, FAILURE);
    }
  return (SUCCESS_STATUS);
}
