/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:00:26 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/23 14:09:12 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	on_error(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	perror(" ");
}

void	error_message_tok(t_liste *line, int i)
{
	(void)line;
	ft_putstr_fd("minishell: ", 2);
	if (i == 1)
		ft_putstr_fd("syntax error near unexpected token \'|\'\n", 2);
	else if (i == 2)
		ft_putstr_fd("syntax error near unexpected token `newline'\n", 2);
}

int	check_error_syntax(t_liste *line, t_cmd *cmd)
{
	t_token	*cur;

	cur = line->first_node;
	if (cur->type == TOKEN_PIPE)
		return (ret_error(line, cmd, 1));
	else if (cur->next == NULL && ((cur->type == 0) || (cur->type == 2)
			|| (cur->type == 3) || (cur->type == 1)))
		return (ret_error(line, cmd, 2));
	else if (cur->type == 0 && cur->next->type == 2)
		return (ret_error(line, cmd, 2));
	else
	{
		while (cur->next != NULL)
		{
			if (cur->type == 4 && cur->next->type == 4)
				break ;
			cur = cur->next;
		}
		if (cur->type == 4 || (cur->next == NULL && ((cur->type == 0)
					|| (cur->type == 2) || (cur->type == 3)
					|| (cur->type == 1))))
			return (ret_error(line, cmd, 2));
	}
	return (1);
}

/*
int	check_error_syntax(t_liste *line, t_cmd *cmd)
{
	t_token	*cur;

	cur = line->first_node;
	if (cur->type == TOKEN_PIPE)
	{
		error_message_tok(line, 1);
		cmd->exit_code = 2;
		return (0);
	}
	else if (cur->next == NULL && ((cur->type == 0) || (cur->type == 2)
			|| (cur->type == 3) || (cur->type == 1)))
	{
		error_message_tok(line, 2);
		cmd->exit_code = 2;
		return (0);
	}
	else if (cur->type == 0 && cur->next->type == 2)
	{
		error_message_tok(line, 2);
		cmd->exit_code = 2;
		return (0);
	}
	else
	{
		while (cur->next != NULL)
		{
			if (cur->type == 4 && cur->next->type == 4)
				break ;
			cur = cur->next;
		}
		if (cur->type == 4 || (cur->next == NULL && ((cur->type == 0)
					|| (cur->type == 2) || (cur->type == 3)
					|| (cur->type == 1))))
		{
			error_message_tok(line, 2);
			cmd->exit_code = 2;
			return (0);
		}
	}
	return (1);
}

*/

void	put_error_export(t_cmd *cmd, char *str)
{
	ft_putstr_fd("minishell: export: ", 2);
	ft_putstr_fd("\'", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\'", 2);
	ft_putstr_fd(": not a valid identifier\n", 2);
	cmd->exit_code = 1;
}

int	ret_error(t_liste *line, t_cmd *cmd, int i)
{
	if (i == 2)
	{
		error_message_tok(line, 2);
		cmd->exit_code = 2;
		return (0);
	}
	else if (i == 1)
	{
		error_message_tok(line, 1);
		cmd->exit_code = 2;
		return (0);
	}
	return (-1);
}
