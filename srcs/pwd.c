/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:43:14 by mgeorges          #+#    #+#             */
/*   Updated: 2024/10/16 14:26:06 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		printf("%s\n", pwd);
		free(pwd);
	}
	else
		perror("getcwd");
	return (0);
}

/*
int	get_pwd(t_cmd *cmd)
{
	t_env	*current;
	char	*pwd;

	current = cmd->env->first_node;
	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		printf("%s\n", pwd);
		while (current && ft_strcmp(current->name))
		free(pwd);
	}
	else
		perror("getcwd");
	return (0);
}

*/