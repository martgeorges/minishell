/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:40:11 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/11 17:47:07 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] >= 48 && nptr[i] <= 57)
	{
		result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[100] = "      \n\t\r\v--+-+-17081996asma-17081996asma";
	int		result;

	result = ft_atoi(str);
	printf("The int is : %d", result);
}*/
