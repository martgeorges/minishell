/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:55:42 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/23 10:52:11 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	jump_next_quote(int i, char *str)
{
	int	j;

	i++;
	while (str[i] != '\'')
	{
		j = i;
		while (str[j] != '\'')
			j++;
		i = j;
	}
	return (i);
}

void	free_var_sub(char *name, char *str, char *value)
{
	free(str);
	free(name);
	free(value);
}

// pour sub var
int	len_tot(char *str, char *name, int k)
{
	return (ft_strlen(str) - ft_strlen(name) + k);
}

char	*set_new_str(char *str, t_cmd *cmd, int *i, int j)
{
	char	*name;
	char	*value;
	size_t	k;
	char	*new_str;

	name = ft_substr(str, *i, j - *i);
	value = get_value(name, cmd);
	new_str = malloc((ft_strlen(str) - (ft_strlen(name) + 1) + ft_strlen(value)
				+ 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	k = 0;
	j = (*i)--;
	ft_strlcpy(new_str, str, *i + 1);
	while (value[k] != '\0')
		new_str[(*i)++] = value[k++];
	new_str[*i] = 0;
	ft_strlcat(new_str, str + j + ft_strlen(name), len_tot(str, name, k));
	free_var_sub(name, str, value);
	return (new_str);
}

// char	*var_substitution(char *str, t_cmd *cmd, int *i)
char	*var_substitution(char *str, t_cmd *cmd, int *i, bool is_status)
{
	int	j;

	if (is_status)
		str = set_new_str(str, cmd, i, *i + 1);
	else if (ft_isalpha(str[*i]) || str[*i] == '_')
	{
		j = *i;
		while (str[j] && (ft_isalnum(str[j]) || str[j] == '_'))
			j++;
		str = set_new_str(str, cmd, i, j);
	}
	(*i)--;
	return (str);
}
