/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:14:20 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/17 15:22:50 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_kind_quotes(char c, t_cmd *cmd)
{
	if (c == '"')
		cmd->double_first = true;
	else if (c == '\'')
		cmd->single_first = true;
}

void	handle_remove_quotes(t_liste *line, t_cmd *cmd)
{
	t_token	*current;
	int		i;

	current = line->first_node;
	while (current)
	{
		i = 0;
		if (current->type == TOKEN_ARG || current->type == TOKEN_CMD)
		{
			while (current->str[i])
			{
				if (current->str[i] == '"' || current->str[i] == '\'')
				{
					check_kind_quotes(current->str[i], cmd);
					current->str = remove_quotes(current->str);
					cmd->double_first = false;
					cmd->single_first = false;
					break ;
				}
				i++;
			}
		}
		current = current->next;
	}
}

// step 1 : increment the i to parse the str before the " or '
// step 2 : q is the kind of quote found after leaving the loop
// step 3 : increment i to go to the first letter after the quote
// step 4 : write each letter in between the quotes in the index
//	-1 (décaler de 1)

// ex : input coucou"Hello"'HAllo'
// step1 : coucou
// step2 : " i = 6
// step3 : H
// step4 : write H on " etc..
// step5 : décaler le ' sur l'ancien o

char	*shift_inside_quotes(char *str, int *j, char q)
{
	int	i;

	i = *j;
	while (str[i] && str[i] != q)
	{
		str[i - 1] = str[i];
		i++;
	}
	*j = i;
	return (str);
}

// step 5 : check si fin de chaine
// step 6 : write each letter by moving them -2

char	*shift_after_quotes(char *str, int *i)
{
	int	j;

	j = *i;
	while (str[j])
	{
		str[j - 2] = str[j];
		j++;
	}
	*i = j;
	return (str);
}

char	*remove_quotes(char *str)
{
	int		i;
	char	q;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && (str[i] != '"' && str[i] != '\''))
			i++;
		if (!str[i])
			break ;
		q = str[i];
		i++;
		str = shift_inside_quotes(str, &i, q);
		if (!str[i])
			break ;
		j = i + 1;
		str = shift_after_quotes(str, &j);
		str[j - 2] = '\0';
		i--;
	}
	return (str);
}
