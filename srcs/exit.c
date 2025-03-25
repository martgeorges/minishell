/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:53:41 by mgeorges          #+#    #+#             */
/*   Updated: 2024/10/24 09:34:50 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_atoll(const char *str, long long *result)
{
	int			i;
	int			sign;
	long long	number;

	i = 0;
	sign = 1;
	number = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		if (number > (LLONG_MAX / 10) || (number == LLONG_MAX / 10 && (str[i]
					- '0') > LLONG_MAX % 10))
			return (0);
		number = number * 10 + (str[i] - '0');
		i++;
	}
	*result = number * sign;
	return (1);
}

static int	is_valid_number(const char *str, long long *result)
{
	if (!ft_atoll(str, result))
		return (0);
	if ((*result < LLONG_MIN) || (*result > LLONG_MAX))
		return (0);
	return (1);
}

void	exit_shell(t_token *current, t_liste *line, t_cmd *cmd)
{
	long long	exit_code;

	printf("exit\n");
	if (current->next != NULL)
	{
		if (!is_valid_number(current->next->str, &exit_code))
		{
			ft_putstr_fd("minishell: exit: numeric argument required\n", 2);
			free_exit(line, cmd);
			exit(2);
		}
		if (current->next->next != NULL)
		{
			ft_putstr_fd("minishell: exit: too many arguments.\n", 2);
			return ;
		}
		free_exit(line, cmd);
		exit(exit_code);
	}
	free_exit(line, cmd);
	exit(0);
}
