/*
** parse_word.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Wed Apr 12 23:59:42 2017 Victor LE DANTEC
** Last update Tue Apr 25 15:38:45 2017 Victor LE DANTEC
*/

#include "parser.h"

/*
** I fucking assure you the code was clean before inhibitors were implemented.
*/

static int	get_word_length(char *input)
{
  int		i;

  i = 0;
  toggle_magic_quotes(RESET_QUOTES);
  while (input[i] != '\0')
    {
      if (input[i] == '\\' && input[i + 1] != '\0')
	i += 2;
      else if (input[i] == '`')
	{
	  toggle_magic_quotes(ADD_QUOTES);
	  i++;
	}
      else if (input[i] != ' ' && input[i] != '\t'
	       && is_delimiter(input + i) == 0)
	i++;
      else
	break;
    }
  if (toggle_magic_quotes(REQUEST_QUOTES) == 1 && (i = -1) == -1)
    puts("Unmatched '`'.");
  return (i);
}

static char	*get_word(char *input, int length)
{
  char		*word;
  char		inhib;
  size_t	i;
  size_t	j;

  if ((word = malloc(sizeof(char) * (length + 1))) == NULL)
    exit_error("[42sh]{parse_word}(get_word)", MALLOC_ERROR, FAILURE);
  i = inhib = j = 0;
  while (i < (size_t)length)
    {
      if (inhib == 1)
	{
	  word[j++] = input[i];
	  inhib = 0;
	}
      else if (input[i] == '\\')
	inhib = 1;
      else
	word[j++] = input[i];
      i++;
    }
  word[j] = '\0';
  return (word);
}

/*
** If we're in a string already, we concatenate it, else we create a new token
*/

int	parse_word(t_parser *tok_info)
{
  int	length_word;

  if ((length_word = get_word_length(tok_info->input + tok_info->index)) > 0)
    {
      if (tok_info->cmd_count == tok_info->tokens->size)
	tok_info->tokens->data[tok_info->cmd_count - 1] = str_concat
	  (tok_info->tokens->data[tok_info->cmd_count - 1],
	   get_word(tok_info->input + tok_info->index, length_word));
      else
	strlist_append(tok_info->tokens, get_word
		       (tok_info->input + tok_info->index, length_word));
    }
  if (is_delimiter(tok_info->input + tok_info->index + length_word) != 0)
    tok_info->cmd_count++;
  return (length_word);
}
