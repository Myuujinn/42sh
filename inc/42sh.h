/*
** 42sh.h for 42sh in /home/swann/PSU_2016_42sh
**
** Made by Swann Jaunasse
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Tue Dec  6 14:25:29 2016 Swann Jaunasse
** Last update Sat May 20 23:44:17 2017 Victor LE DANTEC
*/

/*
** Prevents multiples inclusions.
** Real men use #pragma once. Not standard but nearly all C compilers have it.
*/

#pragma once

/*
** I don't know why but this is needed everywhere.
** So it's included in here.
*/

#include <string.h>

/*
** Library includes here because they're overused everywhere (again).
** So useful though.
*/

#include "error.h"
#include "libtech.h"

/*
** In case we don't have POSIX sources, we're covered by these macros.
*/

#ifdef _POSIX_SOURCE
# define	_W_INT(i)		(i)
#else
# define	_W_INT(w)		(*(int *)&(w))
# define	WCOREFLAG		0200
#endif

#ifndef _POSIX_SOURCE
# define	WCOREDUMP(x)		(_W_INT(x) & WCOREFLAG)
# define	W_EXITCODE(ret, sig)	((ret) << 8 | (sig))
# define	W_STOPCODE(sig)		((sig) << 8 | _WSTOPPED)
#endif

/*
** Easier manipulation of the number of builtins
*/

#define NB_BUILTINS	10

/*
** Universal macro for all syscall to get input from user.
** Why is it limited? Go to "man gets" to find out.
** Hint : Input overflow is a major security flaw sorry.
*/

#define READ_SIZE	50000

/*
** Debug variable that gets turned on if ./42sh -d
*/

extern char	g_debug;

/*
** Shell info structure that has useful info for the shell
*/

typedef struct	s_alias
{
  t_strlist	*name;
  t_strlist	*value;
  size_t	size;
}		t_alias;

typedef struct	s_shinfo
{
  t_strlist	*env;
  t_alias	alias;
  unsigned char	status;
  char		*old_pwd;
  t_strlist	*history;
  int		std_save[2];
  int		pid;
}		t_shinfo;

/*
** Just the names and function pointers to the builtins
*/

extern char 	*g_cmd_names[NB_BUILTINS];
extern int 	(*g_cmd_funcs[NB_BUILTINS])(t_shinfo *, t_strlist *);

/*
** Shell related functions (parsing, evaluator, environment..)
*/

t_strlist	*get_path(t_strlist *);
char		*path_join(char *, char *);
char		*search_binary(t_strlist *, char *);
char		*file_name(char *);
void		display_prompt();
t_shinfo	*shinfo_create(t_strlist *);
t_strlist	*default_env();
void		init_signal();
t_shinfo	*get_shinfo(t_shinfo *);
int		pre_eval(t_shinfo *, t_strlist *);
void		display_tokens(t_strlist *);
void		load_42shrc(t_shinfo *);

void		process_command(t_shinfo *, char *);
int		evaluator(t_shinfo *, t_strlist *);
t_strlist	*parse_input(char *);
char		*get_input(FILE *);
int		handle_status(int);
char		*remove_newline(char *);

/*
** Builtins.
*/

t_bool          cmd_is_builtin(t_strlist *);

int		cmd_alias(t_shinfo *, t_strlist *);
ssize_t		is_alias(t_shinfo *, char *);
void		alias_swap(t_shinfo *, char **);

int		set_env(t_strlist *, char *, char *);
int		unset_env(t_strlist *, char *);
char		*get_env(t_strlist *, char *);
int		cmd_getenv(t_shinfo *, t_strlist *);
int		cmd_env(t_shinfo *, t_strlist *);
int		cmd_setenv(t_shinfo *, t_strlist *);
int		cmd_unsetenv(t_shinfo *, t_strlist *);

int		change_dir(t_shinfo *, char *);
int		cmd_cd(t_shinfo *, t_strlist *);

int		cmd_path(t_shinfo *, t_strlist *);
int		cmd_echo(t_shinfo *, t_strlist *);
int		cmd_repeat(t_shinfo *, t_strlist *);
int		cmd_which(t_shinfo *, t_strlist *);
int		cmd_exit(t_shinfo *, t_strlist *);
int		cmd_builtins(t_shinfo *, t_strlist *);
