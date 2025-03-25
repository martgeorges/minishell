/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:00:13 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/24 10:31:34 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
void	handle_input_redirection(char *filename, t_liste *line, t_cmd *cmd)
{
	int	fd;

	//(void)line;
	//(void)cmd;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		//if (cmd->is_pipe == false)
		//{
			fprintf(stdout, "PID : %d\n", getpid());
			free(cmd->path);
			free_liste(line);
			free_env_lst(&cmd->env);
			free(cmd->env);
			rl_clear_history();
			//clear_history(); // pour mac
			exit(1);
		//}
		on_error(filename);
	}
	else
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}

*/
/* working but when redirection wrong it does not work */

void	handle_input_redirection(char *filename, t_liste *line, t_cmd *cmd)
{
	int	fd;

	(void)line;
	(void)cmd;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		if (cmd->is_pipe == true)
			free_tab_pipe(cmd, cmd->pipe_number);
		on_error(filename);
		free(cmd->path);
		free_liste(line);
		free_env_lst(&cmd->env);
		free(cmd->env);
		rl_clear_history();
		exit(1);
	}
	else
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}

void	handle_output_redirection(char *filename, int flags, t_liste *line,
		t_cmd *cmd)
{
	int	outfile;

	outfile = open(filename, O_RDONLY | O_WRONLY | O_CREAT | flags, 0644);
	if (outfile < 0)
	{
		if (cmd->is_pipe == true)
			free_tab_pipe(cmd, cmd->pipe_number);
		on_error(filename);
		free(cmd->path);
		free_liste(line);
		free_env_lst(&cmd->env);
		free(cmd->env);
		rl_clear_history();
		exit(1);
	}
	else
	{
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
	}
}

void	handle_append_redirection(char *filename, int flags, t_liste *line,
		t_cmd *cmd)
{
	int	outfile;

	outfile = open(filename, O_RDONLY | O_WRONLY | O_CREAT | flags, 0644);
	if (outfile < 0)
	{
		if (cmd->is_pipe == true)
			free_tab_pipe(cmd, cmd->pipe_number);
		on_error(filename);
		free(cmd->path);
		free_liste(line);
		free_env_lst(&cmd->env);
		free(cmd->env);
		rl_clear_history();
		exit(1);
	}
	else
	{
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
	}
}

void	here_doc(t_token *current)
{
	int		outfile;
	char	*line;
	ssize_t	bytes_read;

	current = current->next;
	outfile = open("here_doc", O_RDONLY | O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		on_error(current->str);
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		bytes_read = write(outfile, line, ft_strlen(line));
		if (bytes_read < 0)
			on_error("write");
		bytes_read = write(outfile, "\n", 1);
		if (bytes_read < 0)
			on_error("write");
		if (ft_strcmp(line, current->str) == 0)
			break ;
		free(line);
	}
	close(outfile);
}

// j'ai retiré ça de la fonction du dessus juste après close 
//://unlink("here_doc");

void	handle_here_do(t_liste *line)
{
	t_token	*current;

	current = line->first_node;
	while (current)
	{
		if (current->type == TOKEN_HERE_DOC)
			here_doc(current);
		current = current->next;
	}
}
