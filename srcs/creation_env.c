/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:26:18 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/23 10:04:48 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// link list for the env
t_liste_env	*initialisation_env(void)
{
	t_liste_env	*liste;

	liste = malloc(sizeof(*liste));
	if (liste == NULL)
	{
		printf("Error memory allocation\n");
		exit(1);
	}
	liste->first_node = NULL;
	return (liste);
}

void	creation_env(char **env, t_liste_env *envp)
{
	int	i;

	i = 0;
	while (env[i])
	{
		insert_node_env(env[i], envp);
		i++;
	}
}

void	insert_node_env(char *str, t_liste_env *env)
{
	t_env	*new;
	t_env	*current;
	int		bef_equal;
	int		aft_equal;

	current = NULL;
	bef_equal = len_first(str);
	aft_equal = len_end(bef_equal + 1, str);
	new = malloc(sizeof(*new));
	if (env == NULL || new == NULL)
		exit(1);
	new->name = ft_substr(str, 0, bef_equal);
	new->value = ft_substr(str, bef_equal + 1, aft_equal);
	if (!new->value)
		new->value = ft_strdup("");
	new->next = NULL;
	if (env->first_node != NULL)
	{
		current = env->first_node;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	else
		env->first_node = new;
}

//void	display_env_list(t_liste_env *env)
int	display_env_list(t_liste_env *env, int flag)
{
	t_env	*actuel;

	actuel = env->first_node;
	while (actuel)
	{
		if (flag == 0)
			printf("%s=%s\n", actuel->name, actuel->value);
		else if (flag == 1)
			printf("export %s=\"%s\"\n", actuel->name, actuel->value);
		actuel = actuel->next;
	}
	return (0);
}

void	management_env(char **env, t_liste_env *envp)
{
	creation_env(env, envp);
}
