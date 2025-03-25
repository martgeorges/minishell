/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:41:44 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/18 14:39:03 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_empty(t_liste *line)
{
	t_token	*current;

	current = line->first_node;
	if (current == NULL)
		return (1);
	return (0);
}

int	len_first(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

int	len_end(int i, char *str)
{
	while (str[i])
		i++;
	return (i);
}

int	liste_size(t_liste_env *env)
{
	int		i;
	t_env	*current;

	current = env->first_node;
	i = 0;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

int	found_slash(t_token *current)
{
	char	*result;

	result = ft_strchr(current->str, '/');
	if (result == NULL)
		return (0);
	else
		return (1);
}
