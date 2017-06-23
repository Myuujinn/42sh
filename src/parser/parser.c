/*
** parser.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Wed Apr 12 10:57:46 2017 Victor LE DANTEC
** Last update Sat May 20 02:58:13 2017 Victor LE DANTEC
*/

#include "42sh.h"
#include "parser.h"

static int      (*g_delimiter_array[11])(t_parser *) =
{
  &delimiter_empty,
  &delimiter_dot_comma,
  &delimiter_pipe,
  &delimiter_double_and,
  &delimiter_double_pipe,
  &delimiter_greater,
  &delimiter_less,
  &delimiter_double_greater,
  &delimiter_double_less,
  &delimiter_double_quotes,
  &delimiter_single_quote
};

static int	init_parser(t_parser *tok_info, char *input)
{
  if (strlen(input) == 0)
    return (1);
  tok_info->tokens = strlist_create(NULL);
  tok_info->input = input;
  if (g_debug == 1)
    printf("Input is [%s]\n", input);
  tok_info->index = tok_info->cmd_count = 0;
  return (SUCCESS_STATUS);
}

/*
** La variable i sert uniquement à voir si il y a eu erreur.
** C'est un peu horrible mais désolé.
*/

static int	process_token(t_parser *tok_info)
{
  ssize_t	i;

  i = tok_info->index;
  tok_info->index += parse_word(tok_info);
  if (i > tok_info->index)
    return (-1);
  i = tok_info->index;
  tok_info->index += g_delimiter_array
    [is_delimiter(tok_info->input + tok_info->index)](tok_info);
  if (i > tok_info->index)
    return (-1);
  return (SUCCESS_STATUS);
}

/*
** Tout ce qui rentre dans l'input vient ici.
*/

t_strlist	*parse_input(char *input)
{
  t_parser	tok_info;

  if (init_parser(&tok_info, input) == 1)
    return (NULL);
  while (input[tok_info.index] != '\0')
    {
      if (input[tok_info.index] != ' ' && input[tok_info.index] != '\t')
	{
	  tok_info.cmd_count++;
	  while (input[tok_info.index] != '\0' && input[tok_info.index] != ' '
		 && input[tok_info.index] != '\t')
	    if (process_token(&tok_info) == -1)
	      return (NULL);
	}
      else
	tok_info.index++;
    }
  return (tok_info.tokens);
}
