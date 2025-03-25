/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:57:06 by mgeorges          #+#    #+#             */
/*   Updated: 2024/10/24 09:28:06 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_sig = 0;

void	main_execution(t_liste_env *envp, t_cmd *cmd)
{
	char		*input;

	while (1)
	{
		reset_cmd(cmd);
		signal_before();
		input = readline("minishell$ ");
		signal_after();
		if (ft_strlen(input) != 0)
			add_history(input);
		if (input == NULL)
		{
			fprintf(stderr, "exit\n");
			free_env_lst(&envp);
			free(envp);
			rl_clear_history();
			return ;
		}
		if (g_sig == SIGINT)
		{
			cmd->exit_code = 130;
			g_sig = 0;
		}
		minishell_exec(input, cmd);
	}
}

int	validate_parsing(char *input, t_liste *line, t_cmd *cmd)
{
	if (parsing_input(input, line) < 1)
	{
		cmd->exit_code = 1;
		free_liste(line);
		return (0);
	}
	return (1);
}
