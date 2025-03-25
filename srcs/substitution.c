/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:57:09 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/23 18:36:14 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

char	*management_exit_code(t_cmd *cmd, char *str, int *i);

char	*management_exit_code(t_cmd *cmd, char *str, int *i)
{
	t_token	t;
	char	*exit_status;
	char	*temp;

	temp = ft_itoa(cmd->exit_code);
	exit_status = ft_strjoin("?=", temp);
	free(temp);
	insert_node_env(exit_status, cmd->env);
	str = var_substitution(str, cmd, i, 1);
	t.str = "?";
	execution_unset(cmd, &t);
	free(exit_status);
	return (str);
}

char	*management_sub(char *str, t_cmd *cmd)
{
	int		i;
	int		is_quote;

	i = 0;
	is_quote = 0;
	while (str[i])
	{
		if (str[i] == '"')
			is_quote = !is_quote;
		if (str[i] == '\'' && is_quote == 0)
			i = jump_next_quote(i, str);
		else if (str[i] == '$')
		{
			if (str[++i] == '?')
				str = management_exit_code(cmd, str, &i);
			else if (str[i] == '\0')
				break ;
			else
				str = var_substitution(str, cmd, &i, 0);
		}
		i++;
	}
	return (str);
}

char	*get_value(char *name, t_cmd *cmd)
{
	t_env	*current;

	current = cmd->env->first_node;
	while (current)
	{
		if (!ft_strcmp(name, current->name))
			return (ft_strdup(current->value));
		current = current->next;
	}
	return (ft_strdup(""));
}

void	substitution(t_liste *line, t_cmd *cmd)
{
	t_token	*current;

	current = line->first_node;
	while (current)
	{
		if (current->type == TOKEN_ARG || current->type == TOKEN_CMD)
		{
			current->str = management_sub(current->str, cmd);
		}
		current = current->next;
	}
}
