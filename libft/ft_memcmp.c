/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:45:14 by laichoun          #+#    #+#             */
/*   Updated: 2024/02/23 13:17:36 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*str1;
	const char	*str2;

	i = 0;
	str1 = s1;
	str2 = s2;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && (i < n - 1))
		i ++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str1[100] = "Amel";
	char	str2[100] = "Asma";
	int		result;

	result = ft_memcmp(str1, str2, 5);
	if (result == 0)
		printf("S1 is equal to S2");
	else if (result < 0)
		printf("S1 is less than S2");
	else
		printf("S1 is greater than to S2");
}*/
