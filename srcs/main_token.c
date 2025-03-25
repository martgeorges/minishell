/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:28:16 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/24 09:16:58 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell_exec(char *input, t_cmd *cmd)
{
	t_liste	*line;

	line = initialisation();
	if (!validate_parsing(input, line, cmd))
		return ;
	if (!is_empty(line))
	{
		change_token_word(line);
		substitution(line, cmd);
		handle_remove_quotes(line, cmd);
		if (check_error_syntax(line, cmd))
		{
			handle_here_do(line);
			if (!only_is_redir(line, cmd))
			{
				if (nbr_commands(line) == 1)
					interpretation(line, cmd);
				else
					interpretation_pipes(line, cmd);
			}
		}
		my_ft_lstclear(&line);
	}
	free(line);
}

void	reset_cmd(t_cmd *cmd)
{
	cmd->cmd_and_opt = NULL;
	cmd->path = NULL;
	cmd->pipe_number = 0;
	cmd->is_pipe = false;
	cmd->double_first = false;
	cmd->single_first = false;
}

void	initialization_cmd(t_cmd *cmd, t_liste_env *envp)
{
	cmd->cmd_and_opt = NULL;
	cmd->path = NULL;
	cmd->pipe_number = 0;
	cmd->env = envp;
	cmd->exit_code = 0;
	cmd->is_pipe = false;
	cmd->double_first = false;
	cmd->single_first = false;
}

void	affichage_cmd_list_env(t_cmd *cmd)
{
	t_env	*current;
	int		i;

	i = 0;
	current = cmd->env->first_node;
	while (current)
	{
		printf("aff_cmd_env[%d] :%s\n", i, current->name);
		current = current->next;
		i++;
	}
}

int	main(int ac, char **av, char **env)
{
	t_liste_env	*envp;
	t_cmd		cmd;

	(void)ac;
	(void)av;
	envp = initialisation_env();
	management_env(env, envp);
	initialization_cmd(&cmd, envp);
	signal(SIGPIPE, signal_ignore);
	main_execution(envp, &cmd);
	return (0);
}
