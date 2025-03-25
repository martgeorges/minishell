/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:14:57 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/23 15:39:59 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*creation_str(int i, int j, char *input)
{
	int		k;
	char	*result;

	k = 0;
	result = malloc(((j - i) + 2) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (i <= j)
	{
		result[k] = input[i];
		i++;
		k++;
	}
	result[k] = '\0';
	return (result);
}

void	change_token_word(t_liste *line)
{
	t_token	*current;

	current = line->first_node;
	while (current)
	{
		if (((current->type == TOKEN_INPUT) || (current->type == TOKEN_HERE_DOC)
				|| (current->type == TOKEN_APPEND)
				|| (current->type == TOKEN_TRUNCT)) && current->next != NULL
			&& current->next->type == TOKEN_WORD)
			current->next->type = TOKEN_ARG;
		else if (line->first_node->type == TOKEN_WORD)
			current->type = TOKEN_CMD;
		else if (current->type == TOKEN_WORD
			&& ((current->previous->type == TOKEN_ARG
					&& current->previous->previous->type == TOKEN_INPUT)
				|| current->previous->type == TOKEN_PIPE))
			current->type = TOKEN_CMD;
		else
			help_change_token(current);
		current = current->next;
	}
}

void	help_change_token(t_token *current)
{
	if (current->type == TOKEN_WORD
		&& (current->previous->type == TOKEN_ARG
			&& current->previous->previous->type == TOKEN_HERE_DOC))
		current->type = TOKEN_CMD;
	else if (current->type == TOKEN_WORD
		&& (current->previous->type == TOKEN_CMD
			|| current->previous->type == TOKEN_ARG))
		current->type = TOKEN_ARG;
}

int	split_token_word(int i, char *input, t_liste *line)
{
	int		j;
	char	*result;
	char	quote;

	j = i;
	while (input[j] && input[j] != '|' && input[j] != '>' && input[j] != '<'
		&& input[j] != ' ')
	{
		if (input[j] == '"' || input[j] == '\'')
		{
			quote = input[j++];
			while (input[j] && input[j] != quote)
				j++;
			if (input[j] == '\0')
			{
				return (print_error_msg());
			}
		}
		j++;
	}
	result = creation_str(i, --j, input);
	insertion(line, result, TOKEN_WORD);
	free(result);
	i = j;
	return (i);
}

/*int	parsing_input(char *input, t_liste *line)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		while (input[i] == ' ' || input[i] == '\t')
			i++;
		if (input[i] == '\0')
			break ;
		if (input[i] != '<' && input[i] != '>' && input[i] != '|')
		{
			i = split_token_word(i, input, line);
			if (i < 0)
				return (free(input), -1);
		}
		else if (input[i] == '<' && input[i + 1] != '<')
			insertion(line, "<", TOKEN_INPUT);
		else if (input[i] == '<' && input[i + 1] == '<')
		{
			insertion(line, "<<", TOKEN_HERE_DOC);
			i++;
		}
		else if (input[i] == '>' && input[i + 1] != '>')
			insertion(line, ">", TOKEN_TRUNCT);
		else if (input[i] == '>' && input[i + 1] == '>')
		{
			insertion(line, ">>", TOKEN_APPEND);
			i++;
		}
		else if (input[i] == '|')
			insertion(line, "|", TOKEN_PIPE);
	}
	return (free(input), 1);
}*/

int	parsing_input(char *input, t_liste *line)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		while (input[i] == ' ' || input[i] == '\t')
			i++;
		if (input[i] == '\0')
			break ;
		if (input[i] != '<' && input[i] != '>' && input[i] != '|')
		{
			i = split_token_word(i, input, line);
			if (i < 0)
				return (free(input), -1);
		}
		else
			i = management_input(input, line, i);
	}
	return (free(input), 1);
}
