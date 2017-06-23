/*
** delimiter_single_quote.c for 42sh in /home/victor/PSU/PSU_2016_42sh
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Mon Apr 17 17:54:38 2017 Victor LE DANTEC
** Last update Mon Apr 17 17:57:20 2017 Victor LE DANTEC
*/

#include "parser.h"

static int	get_word_length(char *input)
{
  int		i;

  i = 0;
  while (input[i] != '\0' && is_delimiter(input + i) != 10)
    i++;
  if (input[i] == '\0')
    {
      puts("Unmatched '\''.");
      return (-1);
    }
  return (i);
}

static char	*get_word_in_quotes(char *input, int length)
{
  char		*word;
  size_t	i;

  if ((word = malloc(sizeof(char) * (length + 1))) == NULL)
    exit_error("[42sh]{delimiter_double_quotes}(get_word_in_quotes)",
               MALLOC_ERROR, FAILURE);
  i = 0;
  while (i < (size_t)length)
    {
      word[i] = input[i];
      i++;
    }
  word[i] = '\0';
  return (word);
}

int	delimiter_single_quote(t_parser *tok_info)
{
  int	length;
  char	*word;

  if ((length = get_word_length(tok_info->input + tok_info->index + 1)) == -1)
    return (-1);
  word = get_word_in_quotes(tok_info->input + tok_info->index + 1, length);
  if (tok_info->cmd_count == tok_info->tokens->size)
    tok_info->tokens->data[tok_info->cmd_count - 1] = str_concat
      (tok_info->tokens->data[tok_info->cmd_count - 1], word);
  else
    strlist_append(tok_info->tokens, word);
  return (length + 2);
}
