/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:55:36 by mgeorges          #+#    #+#             */
/*   Updated: 2024/10/23 15:18:10 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parent_process_redir_only(t_cmd *cmd, pid_t pid)
{
	int	status;

	status = 0;
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		cmd->exit_code = WEXITSTATUS(status);
}

int	print_error_msg(void)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("Error unclosed quotes\n", 2);
	return (-1);
}

int	management_input(char *input, t_liste *line, int i)
{
	if (input[i] == '<' && input[i + 1] != '<')
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
	return (i);
}
