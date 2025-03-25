/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_pipes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:30:05 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/23 17:11:57 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_redirection_pipe(t_token *current, t_liste *line, t_cmd *cmd)
{
	t_token	*redir;

	(void)current;
	redir = line->first_node;
	while (redir)
	{
		if (redir->type == TOKEN_INPUT)
			handle_input_redirection(redir->next->str, line, cmd);
		else if (redir->type == TOKEN_TRUNCT)
			handle_output_redirection(redir->next->str, O_TRUNC, line, cmd);
		else if (redir->type == TOKEN_APPEND)
			handle_append_redirection(redir->next->str, O_APPEND, line, cmd);
		redir = redir->next;
	}
}

void	handle_redir_cmd(t_token *redir, t_cmd *cmd, t_liste *line)
{
	if (redir->type == TOKEN_INPUT)
		handle_input_redirection(redir->next->str, line, cmd);
	else if (redir->type == TOKEN_TRUNCT)
		handle_output_redirection(redir->next->str, O_TRUNC, line, cmd);
	else if (redir->type == TOKEN_APPEND)
		handle_append_redirection(redir->next->str, O_APPEND, line, cmd);
}
