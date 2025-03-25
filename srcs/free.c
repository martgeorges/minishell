/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:07:05 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/11 17:58:39 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	my_ft_lstclear(t_liste **lst)
{
	t_token	*current;
	t_token	*tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	current = (*lst)->first_node;
	while (current != NULL)
	{
		tmp = current->next;
		free(current->str);
		free(current);
		current = tmp;
	}
	(*lst)->first_node = NULL;
}

void	free_liste(t_liste *pipe)
{
	my_ft_lstclear(&pipe);
	free(pipe);
}

void	free_split(char **result)
{
	int	i;

	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

void	free_tab_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->cmd_and_opt[i])
	{
		free(cmd->cmd_and_opt[i]);
		i++;
	}
	free(cmd->cmd_and_opt);
}

void	free_tab_pipe(t_cmd *cmd, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(cmd->pipe_fd[j]);
		j++;
	}
	free(cmd->pipe_fd);
}
