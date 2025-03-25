/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:34:23 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/23 14:22:59 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	**creation_tab_pipe(t_liste *line, t_cmd *cmd)
{
	int	i;

	i = 0;
	cmd->is_pipe = true;
	cmd->pipe_number = nbr_pipe(line);
	cmd->pipe_fd = malloc((nbr_pipe(line) + 1) * sizeof(int *));
	if (cmd->pipe_fd == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	while (i < cmd->pipe_number)
	{
		cmd->pipe_fd[i] = malloc(2 * sizeof(int));
		if (cmd->pipe_fd[i] == NULL)
		{
			free_tab_pipe(cmd, i);
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (cmd->pipe_fd);
}

void	creation_pipe(t_cmd *cmd, t_liste *line)
{
	int	i;

	i = 0;
	while (i < nbr_pipe(line))
	{
		if (pipe(cmd->pipe_fd[i]) < 0)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	creation_process(t_cmd *cmd, int i, t_token *current, t_liste *line)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		handle_redirection_pipe(current, line, cmd);
		if (i > 0)
			dup2(cmd->pipe_fd[i - 1][0], STDIN_FILENO);
		if (i < cmd->pipe_number)
			dup2(cmd->pipe_fd[i][1], STDOUT_FILENO);
		close_fd_pipe(cmd);
		if (is_builtins(current))
		{
			exec_builtins(current, cmd, line);
			free_exit(line, cmd);
			exit(cmd->exit_code);
		}
		else
			command_access(line, current, cmd->path, cmd);
	}
}

void	close_fd_pipe(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i < cmd->pipe_number)
	{
		close(cmd->pipe_fd[i][0]);
		close(cmd->pipe_fd[i][1]);
		i++;
	}
}

void	parent_process(t_cmd *cmd)
{
	int	i;
	int	status;

	close_fd_pipe(cmd);
	i = 0;
	while (i <= cmd->pipe_number)
	{
		wait(&status);
		if (WIFEXITED(status))
			cmd->exit_code = WEXITSTATUS(status);
		i++;
	}
}
