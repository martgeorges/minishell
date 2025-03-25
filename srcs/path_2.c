/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:32:58 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/16 14:39:23 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_tab(char **result)
{
	int	i;

	i = 0;
	while (result[i] != NULL)
	{
		printf("result[%d] : %s\n", i, result[i]);
		i++;
	}
}
