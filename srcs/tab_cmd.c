/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:16:39 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/23 19:37:07 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redir(t_token *current)
{
	if (current->type == TOKEN_APPEND || current->type == TOKEN_INPUT
		|| current->type == TOKEN_TRUNCT)
		return (1);
	return (0);
}

char	**create_tab_cmd(t_cmd *cmd, t_token *current)
{
	int	i;

	i = 0;
	cmd->cmd_and_opt = malloc((nbre_opt(current) + 2) * sizeof(char *));
	cmd->cmd_and_opt[i++] = ft_strdup(current->str);
	current = current->next;
	while (current && current->type != TOKEN_PIPE)
	{
		if (is_redir(current))
			current = current->next;
		else if (current->type == TOKEN_HERE_DOC)
		{
			cmd->cmd_and_opt[i++] = ft_strdup("here_doc");
			break ;
		}
		else
			cmd->cmd_and_opt[i++] = ft_strdup(current->str);
		current = current->next;
	}
	cmd->cmd_and_opt[i] = NULL;
	return (NULL);
}

int	nbr_commands(t_liste *line)
{
	t_token	*current;
	int		i;

	i = 1;
	current = line->first_node;
	while (current)
	{
		if (current->type == TOKEN_PIPE)
			i++;
		current = current->next;
	}
	return (i);
}

int	nbr_pipe(t_liste *line)
{
	t_token	*current;
	int		i;

	i = 0;
	current = line->first_node;
	while (current)
	{
		if (current->type == TOKEN_PIPE)
			i++;
		current = current->next;
	}
	return (i);
}
