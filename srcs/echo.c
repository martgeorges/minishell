/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:22:37 by mgeorges          #+#    #+#             */
/*   Updated: 2024/10/24 10:31:01 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_args(t_token *arg)
{
	char	*str;

	while (arg)
	{
		str = arg->str;
		printf("%s", str);
		if (arg->next)
			printf(" ");
		arg = arg->next;
	}
}

int	ft_echo(t_token *current)
{
	int		newline;
	t_token	*arg;
	int		i;

	newline = 1;
	arg = current->next;
	while (arg && arg->str[0] == '-' && arg->str[1] == 'n')
	{
		i = 2;
		while (arg->str[i] && arg->str[i] == 'n')
			i++;
		if (arg->str[i] == '\0')
		{
			newline = 0;
			arg = arg->next;
		}
		else
			break ;
	}
	print_args(arg);
	if (newline)
		printf("\n");
	return (0);
}
