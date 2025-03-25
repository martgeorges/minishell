/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:32:36 by Asma              #+#    #+#             */
/*   Updated: 2024/10/24 10:24:22 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		change_directory(const char *path, t_liste_env *env);
//void	management_cd(t_cmd *cmd, t_token *current);
t_env	*find_env_variable(t_liste_env *env, char *name);

int	change_directory(const char *path, t_liste_env *env)
{
	t_env	*current;
	t_env	*var_home;

	current = env->first_node;
	if (!path || ft_strcmp((char *)path, "") == 0)
	{
		var_home = find_env_variable(env, "HOME");
		if (!var_home || !var_home->value)
		{
			ft_putstr_fd("minishell : cd: HOME not set\n", 2);
			return (1);
		}
		path = var_home->value;
	}
	if (chdir(path) != 0)
	{
		perror("cd");
		return (1);
	}
	while (current && !ft_strcmp(current->name, "PWD"))
		current = current->next;
	free(current->value);
	current->value = getcwd(NULL, 0);
	return (0);
}

//void	management_cd(t_cmd *cmd, t_token *current)
int	management_cd(t_cmd *cmd, t_token *current)
{
	t_env	*cur_env;

	cur_env = cmd->env->first_node;
	if (current->next)
	{
		while (current && !ft_strcmp(cur_env->name, "OLDPWD"))
			cur_env = cur_env->next;
		free(cur_env->value);
		cur_env->value = getcwd(NULL, 0);
		return (change_directory(current->next->str, cmd->env));
	}
	else
	{
		while (current && !ft_strcmp(cur_env->name, "OLDPWD"))
			cur_env = cur_env->next;
		free(cur_env->value);
		cur_env->value = getcwd(NULL, 0);
		return (change_directory(NULL, cmd->env));
	}
}

t_env	*find_env_variable(t_liste_env *env, char *name)
{
	t_env	*current;

	current = env->first_node;
	while (current)
	{
		if (ft_strcmp(current->name, name) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}
