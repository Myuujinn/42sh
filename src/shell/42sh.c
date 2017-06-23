/*
** minishell.c for 42sh in /home/swann/PSU_2016_42sh
**
** Made by Swann Jaunasse
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Thu Dec  8 15:17:00 2016 Swann Jaunasse
** Last update Wed May 24 12:41:49 2017 Victor LE DANTEC
*/

#include "evaluator.h"
#include "42sh.h"

/*
** Global debug variable so every function in the shell can access it.
** Theorically not needed, but we want to keep the code as clean as possible.
*/

char	g_debug = 0;

/*
** Where the magic happens.
** Calls the tokenizer, pre-evaluator and evaluator.
** Sets the status too.
*/

void		process_command(t_shinfo *info, char *line)
{
  t_strlist	*cmds;

  alias_swap(info, &line);
  if ((cmds = parse_input(line)) == NULL)
    info->status = 1;
  if (cmds != NULL && pre_eval(info, cmds) == FAILURE_STATUS)
    cmds = NULL;
  if (g_debug % 2 == 1)
    display_tokens(cmds);
  if (cmds != NULL)
    if (evaluator(info, cmds) == FAILURE_STATUS)
      info->status = 1;
}

/*
** Display prompt. Process command. Return status. Repeat.
*/

static int	shell(t_shinfo *info)
{
  char		*line;
  get_shinfo(info);
  load_42shrc(info);
  display_prompt(info);
  while ((line = get_input(stdin)) != NULL)
    {
      if (line[0] != '\0')
	process_command(info, line);
      display_prompt(info);
    }
  if (isatty(STDIN_FILENO))
    print_line("exit", STDOUT_FILENO);
  return (info->status);
}

static void	process_args(int argc, char **argv)
{
  int		i;

  i = 0;
  while (i < argc)
    {
      if ((g_debug == 0 || g_debug == 2)
	  && str_compare(argv[i], "-d") == 0)
	g_debug++;
      else if (g_debug <= 1 && str_compare(argv[i], "-i") == 0)
	g_debug += 2;
      i++;
    }
}

/*
** It begins.
** Basically just initialization of globals and structures.
** And the signal catching too.
** And the environment. Always think about the environment.
** Sort your waste. And put it in the correct trashcans.
*/

int	main(int argc, char **argv, char **env)
{
  process_args(argc, argv);
  g_binary_name = argv[0];
  init_signal();
  if (env == NULL || env[0] == NULL)
    return (shell(shinfo_create(default_env())));
  return (shell(shinfo_create(strlist_create(env))));
}
