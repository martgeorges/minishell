/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:04:19 by Asma              #+#    #+#             */
/*   Updated: 2024/10/23 10:37:02 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	management_unset(t_cmd *cmd, t_token *current)
{
	t_token	*begin;

	current = current->next;
	begin = current;
	while (begin && begin->type != TOKEN_APPEND && begin->type != TOKEN_HERE_DOC
		&& begin->type != TOKEN_INPUT && begin->type != TOKEN_PIPE
		&& begin->type != TOKEN_TRUNCT)
	{
		execution_unset(cmd, begin);
		begin = begin->next;
	}
	cmd->exit_code = 0;
}

void	execution_unset(t_cmd *cmd, t_token *current)
{
	t_env	*cur;
	t_env	*prev;
	t_env	*del;
	t_env	*last;

	prev = NULL;
	del = NULL;
	if (!cmd->env || !cmd->env->first_node || !current || !current->str)
		return ;
	cur = cmd->env->first_node;
	last = last_node(cmd);
	while (cur)
	{
		if (!ft_strcmp(cur->name, current->str))
		{
			del = cur;
			remove_arg(prev, last, cur, cmd);
			free_unset(del);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}

t_env	*last_node(t_cmd *cmd)
{
	t_env	*last;

	last = cmd->env->first_node;
	while (last->next)
		last = last->next;
	return (last);
}

void	remove_arg(t_env *prev, t_env *last, t_env *cur, t_cmd *cmd)
{
	if (prev == NULL)
		cmd->env->first_node = cur->next;
	else
		prev->next = cur->next;
	if (cur == last)
		last = prev;
}
