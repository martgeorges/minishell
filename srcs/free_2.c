/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:53:14 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/24 10:31:14 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env_lst(t_liste_env **lst)
{
	t_env	*current;
	t_env	*tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	current = (*lst)->first_node;
	while (current != NULL)
	{
		tmp = current->next;
		free(current->name);
		free(current->value);
		free(current);
		current = tmp;
	}
	(*lst)->first_node = NULL;
}

void	free_all(t_liste *line, t_cmd *cmd)
{
	free_tab_cmd(cmd);
	free_liste(line);
	free_env_lst(&cmd->env);
	free(cmd->env);
	rl_clear_history();
}

void	free_exit(t_liste *line, t_cmd *cmd)
{
	if (cmd->is_pipe == true)
		free_tab_pipe(cmd, cmd->pipe_number);
	free_liste(line);
	free_env_lst(&cmd->env);
	free(cmd->env);
	rl_clear_history();
}

void	free_unset(t_env *del)
{
	free(del->name);
	free(del->value);
	free(del);
}
