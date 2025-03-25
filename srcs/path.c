/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:59:22 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/23 19:34:13 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_path_list(t_cmd *cmd);

int	nbre_opt(t_token *current)
{
	int	i;

	i = 0;
	current = current->next;
	while (current != NULL && current->type != TOKEN_PIPE)
	{
		if (current->type == TOKEN_HERE_DOC)
		{
			i ++;
			break ;
		}
		else if (current->type == TOKEN_ARG)
			i++;
		current = current->next;
	}
	return (i);
}

/*
int	nbre_opt(t_token *current)
{
	int	i;

	i = 0;
	current = current->next;
	while (current != NULL)
	{
		if (current->type != TOKEN_ARG)
			break ;
		i++;
		current = current->next;
	}
	return (i);
}
*/

char	**tab_cmd_opt(t_token *current)
{
	char	**tab_opt;
	int		i;

	tab_opt = malloc((nbre_opt(current) + 2) * sizeof(char *));
	if (tab_opt == NULL)
		return (NULL);
	i = 0;
	tab_opt[i++] = ft_strdup(current->str);
	current = current->next;
	while (current && current->type == TOKEN_ARG)
	{
		tab_opt[i++] = ft_strdup(current->str);
		current = current->next;
	}
	tab_opt[i] = NULL;
	return (tab_opt);
}

char	*give_the_path(char *str, char **result, t_cmd *cmd)
{
	char	*path;

	(void)cmd;
	path = ft_strdup(str);
	free_split(result);
	return (path);
}

char	*is_in_path(t_token *current, t_cmd *cmd)
{
	char	*path;
	char	**result;
	char	*join;
	int		i;

	i = 0;
	path = get_path_list(cmd);
	if (path == NULL)
		return (0);
	result = ft_split(path, ':');
	while (result[i])
	{
		join = ft_strjoin(result[i], "/");
		free(result[i]);
		result[i] = join;
		join = ft_strjoin(result[i], current->str);
		free(result[i]);
		result[i] = join;
		if (access(result[i], X_OK) == 0)
			return (give_the_path(result[i], result, cmd));
		i++;
	}
	free_split(result);
	return (NULL);
}

char	*get_path_list(t_cmd *cmd)
{
	t_env	*current;

	current = cmd->env->first_node;
	while (current)
	{
		if (!ft_strcmp(current->name, "PATH"))
		{
			return (current->value);
		}
		current = current->next;
	}
	return (NULL);
}
