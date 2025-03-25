/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_export_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:55:26 by Asma              #+#    #+#             */
/*   Updated: 2024/10/23 10:31:23 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// link list for the env
t_liste_export	*initialisation_export(void)
{
	t_liste_export	*liste;

	liste = malloc(sizeof(*liste));
	if (liste == NULL)
	{
		printf("Error memory allocation\n");
		exit(1);
	}
	liste->first_node = NULL;
	return (liste);
}

void	creation_export(char **env, t_liste_export *export)
{
	int	i;

	i = 0;
	while (env[i])
	{
		insert_node_export(env[i], export);
		i++;
	}
}

void	insert_node_export(char *str, t_liste_export *export)
{
	t_export	*new;
	t_export	*current;
	int			bef_equal;
	int			aft_equal;

	current = NULL;
	bef_equal = len_first(str);
	aft_equal = len_end(bef_equal + 1, str);
	new = malloc(sizeof(*new));
	if (export == NULL || new == NULL)
		exit(1);
	new->name = ft_substr(str, 0, bef_equal);
	new->value = ft_substr(str, bef_equal + 1, aft_equal);
	if (!new->value)
		new->value = ft_strdup("");
	new->next = NULL;
	if (export->first_node != NULL)
	{
		current = export->first_node;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	else
		export->first_node = new;
}

void	display_export_list(t_liste_export *export)
{
	t_export	*actuel;

	actuel = export->first_node;
	while (actuel)
	{
		printf("export %s=\"%s\"\n", actuel->name, actuel->value);
		actuel = actuel->next;
	}
}

void	management_export_list(char **env, t_liste_export *export)
{
	creation_export(env, export);
}
