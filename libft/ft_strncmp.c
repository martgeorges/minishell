/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:40:50 by laichoun          #+#    #+#             */
/*   Updated: 2024/02/29 09:54:38 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[i] == (unsigned char)s2[i]
		&& s1[i] != '\0' && i < (n - 1))
	{
		i ++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s1[100] = "Aaaa";
	char	s2[100] = "Aaal";
	int		result;

	result = ft_strncmp(s1, s2, 4);
	printf("La valeur de resultat est : %s, %s, %d\n", s1, s2, result);
	if (result == 0)
		printf("S1 is equal to S2");
	else if (result < 0)
		printf("S1 is less than S2");
	else
		printf("S1 is greater than to S2");
}*/
