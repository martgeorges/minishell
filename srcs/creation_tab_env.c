/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_tab_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:30:34 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/23 10:05:31 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// creation of the tab for the env --> execve
char	**creation_tab_env(t_liste_env *env)
{
	char	**tab;
	int		i;
	t_env	*current;
	char	*join;
	char	*result;

	current = env->first_node;
	i = 0;
	tab = malloc((liste_size(env) + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	while (current)
	{
		join = ft_strjoin(current->name, "=");
		result = ft_strjoin(join, current->value);
		free(join);
		tab[i] = ft_strdup(result);
		free(result);
		current = current->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
