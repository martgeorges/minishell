/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir_only.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:58:00 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/24 10:31:20 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	only_is_redir(t_liste *line, t_cmd *cmd)
{
	t_token	*current;

	current = line->first_node;
	while (current)
	{
		if (current->type == TOKEN_CMD || current->type == TOKEN_HERE_DOC)
			return (0);
		current = current->next;
	}
	handle_only_redir(line, cmd);
	return (1);
}

// fork to
// avant ://open_fd_only_redir(redir->type, redir->next->str, cmd);
void	handle_only_redir(t_liste *line, t_cmd *cmd)
{
	t_token	*redir;
	pid_t	pid;

	pid = fork();
	error_on_fork(pid);
	if (pid == 0)
	{
		redir = line->first_node;
		while (redir)
		{
			if (redir->type == TOKEN_INPUT)
				open_fd_only_redir(redir->type, redir->next->str, cmd, line);
			else if (redir->type == TOKEN_TRUNCT)
				open_fd_only_redir(redir->type, redir->next->str, cmd, line);
			else if (redir->type == TOKEN_APPEND)
				open_fd_only_redir(redir->type, redir->next->str, cmd, line);
			redir = redir->next;
		}
	}
	else
		parent_process_redir_only(cmd, pid);
}

// avant :
// error_on_fd(filename, fd, cmd);
// void	open_fd_only_redir(int type, char *filename, t_cmd *cmd)
void	open_fd_only_redir(int type, char *filename, t_cmd *cmd, t_liste *line)
{
	int	fd;

	if (type == 2)
	{
		fd = open(filename, O_RDONLY | O_WRONLY | O_CREAT | O_TRUNC, 0644);
		error_on_fd(filename, fd, cmd, line);
	}
	if (type == 0)
	{
		fd = open(filename, O_RDONLY);
		error_on_fd(filename, fd, cmd, line);
	}
	if (type == 3)
	{
		fd = open(filename, O_RDONLY | O_WRONLY | O_CREAT | O_APPEND, 0644);
		error_on_fd(filename, fd, cmd, line);
	}
}

// void	error_on_fd(char *filename, int fd, t_cmd *cmd)
void	error_on_fd(char *filename, int fd, t_cmd *cmd, t_liste *line)
{
	(void)cmd;
	if (fd < 0)
	{
		on_error(filename);
		free_liste(line);
		free_env_lst(&cmd->env);
		free(cmd->env);
		rl_clear_history();
		exit(1);
	}
	else
		close(fd);
}

void	error_on_fork(pid_t pid)
{
	if (pid == -1)
	{
		perror("fork");
		return ;
	}
}
