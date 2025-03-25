/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:58:53 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/24 09:18:40 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtins(t_token *current)
{
	if (!ft_strcmp(current->str, "echo") || !ft_strcmp(current->str, "cd")
		|| !ft_strcmp(current->str, "pwd") || !ft_strcmp(current->str, "export")
		|| !ft_strcmp(current->str, "unset") || !ft_strcmp(current->str, "env")
		|| !ft_strcmp(current->str, "exit"))
		return (1);
	return (0);
}

int	exec_builtins(t_token *current, t_cmd *cmd, t_liste *line)
{
	if (!ft_strcmp(current->str, "pwd"))
		cmd->exit_code = get_pwd();
	else if (!ft_strcmp(current->str, "exit"))
	{
		exit_shell(current, line, cmd);
		cmd->exit_code = 1;
	}
	else if (!ft_strcmp(current->str, "export"))
		management_export(current->next, line, cmd);
	else if (!ft_strcmp(current->str, "env"))
		cmd->exit_code = display_env_list(cmd->env, 0);
	else if (!ft_strcmp(current->str, "unset"))
		management_unset(cmd, current);
	else
		(exec_builtins_2(current, cmd));
	return (0);
}

int	exec_builtins_2(t_token *current, t_cmd *cmd)
{
	if (!ft_strcmp(current->str, "cd"))
		cmd->exit_code = management_cd(cmd, current);
	else if (!ft_strcmp(current->str, "echo"))
		cmd->exit_code = ft_echo(current);
	return (0);
}
