/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:35:52 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/23 10:32:46 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	management_export(t_token *current, t_liste *line, t_cmd *cmd)
{
	t_token	*begin;

	(void)line;
	begin = current;
	while (begin && begin->type != TOKEN_APPEND && begin->type != TOKEN_HERE_DOC
		&& begin->type != TOKEN_INPUT && begin->type != TOKEN_PIPE
		&& begin->type != TOKEN_TRUNCT)
	{
		execution_export(begin->str, cmd);
		begin = begin->next;
	}
	if (current == NULL || current->type == TOKEN_PIPE
		|| current->type == TOKEN_APPEND || current->type == TOKEN_TRUNCT)
		display_env_list(cmd->env, 1);
}

void	execution_export(char *s, t_cmd *cmd)
{
	t_env	*cur;
	int		i;
	char	*name_str;
	char	*val;

	i = 0;
	cur = cmd->env->first_node;
	if ((ft_isalpha(s[i]) || s[i] == '_'))
	{
		while (s[i] && (ft_isalnum(s[i]) || s[i] == '_'))
			i++;
		if (s[i] && (s[i] != '=' && !(ft_isalnum(s[i]) || s[i] == '_')))
			put_error_export(cmd, s);
		else
		{
			name_str = ft_substr(s, 0, i);
			val = ft_substr(s, i + 1, ft_strlen(s));
			cur = node_found(cur, name_str, val);
			is_node_null(cmd, val, s, cur);
			node_not_found(cmd, name_str, val, s);
			cmd->exit_code = 0;
		}
	}
	else
		put_error_export(cmd, s);
}

t_env	*node_found(t_env *cur, char *name_str, char *new_value)
{
	while (cur)
	{
		if (!ft_strcmp(cur->name, name_str))
		{
			free(cur->value);
			cur->value = ft_strdup(new_value);
			break ;
		}
		cur = cur->next;
	}
	return (cur);
}

void	node_not_found(t_cmd *cmd, char *name_str, char *new_value, char *str)
{
	t_env	*cur;

	cur = cmd->env->first_node;
	if (new_value == NULL && str[ft_strlen(str) - 1] == '=')
	{
		while (cur)
		{
			if (!ft_strcmp(cur->name, name_str))
				break ;
			cur = cur->next;
		}
		free(cur->value);
		cur->value = ft_strdup("");
	}
	free(name_str);
	free(new_value);
}

void	is_node_null(t_cmd *cmd, char *val, char *s, t_env *cur)
{
	if (cur == NULL)
		if (val != NULL || (val == NULL && s[ft_strlen(s) - 1] == '='))
			insert_node_env(s, cmd->env);
}
