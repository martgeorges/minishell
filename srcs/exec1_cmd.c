/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec1_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:47:57 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/24 10:00:10 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_1_cmd(t_token *current, t_cmd *cmd, t_liste *line)
{
	pid_t	parent;
	int		status;
	t_token	*redir;

	status = 0;
	parent = fork();
	if (parent == -1)
	{
		perror("fork");
		return (1);
	}
	if (parent == 0)
	{
		redir = line->first_node;
		while (redir)
		{
			handle_redir_cmd(redir, cmd, line);
			redir = redir->next;
		}
		command_access(line, current, cmd->path, cmd);
	}
	else
		waitpid(parent, &status, 0);
	return (WEXITSTATUS(status));
}

void	interpretation(t_liste *line, t_cmd *cmd)
{
	t_token	*current;

	current = line->first_node;
	while (current)
	{
		if (current->type == TOKEN_CMD)
		{
			if (is_builtins(current))
				exec_builtins(current, cmd, line);
			else
			{
				if (found_slash(current))
				{
					cmd->path = current->str;
					cmd->exit_code = exec_1_cmd(current, cmd, line);
				}
				else
					handle_binaries(current, cmd, line);
			}
		}
		current = current->next;
	}
}

void	handle_binaries(t_token *current, t_cmd *cmd, t_liste *line)
{
	cmd->path = is_in_path(current, cmd);
	if (cmd->path != NULL)
	{
		cmd->exit_code = exec_1_cmd(current, cmd, line);
		free(cmd->path);
	}
	else
	{
		ft_putstr_fd(current->str, 2);
		ft_putstr_fd(": command not found\n", 2);
		cmd->exit_code = 127;
	}
}

void	command_access(t_liste *line, t_token *current, char *str, t_cmd *cmd)
{
	char	**result;

	create_tab_cmd(cmd, current);
	result = creation_tab_env(cmd->env);
	execve(str, cmd->cmd_and_opt, result);
	free_split(result);
	if (cmd->is_pipe == true)
		free_tab_pipe(cmd, cmd->pipe_number);
	if (errno == EACCES && access(str, X_OK) == 0)
		error_cmd_access(line, str, cmd, 1);
	else if (access(str, F_OK) == 0)
		error_cmd_access(line, str, cmd, 2);
	else
		error_cmd_access(line, str, cmd, 3);
}

void	error_cmd_access(t_liste *line, char *str, t_cmd *cmd, int i)
{
	ft_putstr_fd(str, 2);
	free_all(line, cmd);
	if (i == 1)
	{
		ft_putstr_fd(":  Is a directory\n", 2);
		exit(126);
	}
	else if (i == 2)
	{
		ft_putstr_fd(":  Permission denied\n", 2);
		exit(126);
	}
	else if (i == 3)
	{
		ft_putstr_fd(":  no such file or directory\n", 2);
		exit(127);
	}
}
