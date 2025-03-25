/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipelines_true.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:58:39 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/23 18:20:34 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		interpretation_pipes_2(t_token *current, t_liste *line, t_cmd *cmd,
			int i);
void	on_error_cmd_pipe(t_token *current, t_cmd *cmd);

void	interpretation_pipes(t_liste *line, t_cmd *cmd)
{
	t_token	*current;
	int		i;

	creation_tab_pipe(line, cmd);
	creation_pipe(cmd, line);
	current = line->first_node;
	i = 0;
	while (current)
	{
		if (current->type == TOKEN_CMD)
		{
			interpretation_pipes_2(current, line, cmd, i);
			i++;
		}
		current = current->next;
	}
	parent_process(cmd);
	free_tab_pipe(cmd, cmd->pipe_number);
}

int	interpretation_pipes_2(t_token *current, t_liste *line, t_cmd *cmd, int i)
{
	if (is_builtins(current))
		creation_process(cmd, i, current, line);
	else
	{
		if (found_slash(current))
		{
			cmd->path = current->str;
			creation_process(cmd, i, current, line);
		}
		else
		{
			cmd->path = is_in_path(current, cmd);
			if (cmd->path != NULL)
			{
				creation_process(cmd, i, current, line);
				free(cmd->path);
			}
			else
				on_error_cmd_pipe(current, cmd);
		}
	}
	return (i);
}

/*
void	command_access_pipes(t_token *current, char *str, t_cmd *cmd)
{
	char	**result;

	result = creation_tab_env(cmd->env);
	printf("nbre d'argument : %d\n", nbre_opt(current));
	printf("commande à executer\n");
	create_tab_cmd(cmd, current);
	display_tab(cmd->cmd_and_opt);
	execve(str, cmd->cmd_and_opt, result);
	free_split(result);
	free(str);
}
*/

void	on_error_cmd_pipe(t_token *current, t_cmd *cmd)
{
	ft_putstr_fd(current->str, 2);
	ft_putstr_fd(": command not found\n", 2);
	cmd->exit_code = 127;
}
