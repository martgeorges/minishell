/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:00:45 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/24 10:30:58 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_liste	*initialisation(void)
{
	t_liste	*liste;

	liste = malloc(sizeof(*liste));
	if (liste == NULL)
	{
		printf("Error memory allocation\n");
		exit(1);
	}
	liste->first_node = NULL;
	return (liste);
}

void	insertion(t_liste *liste, char *content, t_token_type type)
{
	t_token	*new;
	t_token	*current;

	new = malloc(sizeof(*new));
	if (liste == NULL || new == NULL)
	{
		exit(EXIT_FAILURE);
	}
	new->str = ft_strdup(content);
	new->next = NULL;
	new->previous = NULL;
	new->type = type;
	if (liste->first_node != NULL)
	{
		current = liste->first_node;
		while (current->next)
			current = current->next;
		current->next = new;
		new->previous = current;
	}
	else
		liste->first_node = new;
}

void	display_liste(t_liste *liste)
{
	t_token	*actuel;

	if (liste == NULL)
	{
		exit(EXIT_FAILURE);
	}
	actuel = liste->first_node;
	while (actuel != NULL)
	{
		printf("%s token: %d -> ", actuel->str, actuel->type);
		actuel = actuel->next;
	}
	printf("NULL\n");
}
