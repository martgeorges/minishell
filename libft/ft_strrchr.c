/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:15:45 by laichoun          #+#    #+#             */
/*   Updated: 2024/02/26 15:12:38 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i ++;
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i --;
	}
	if (c == '\0' && s[i] == '\0')
		return ((char *)s + i);
	return (NULL);
}
/*
#include <stdio.h>

int     main(void)
{
	char    str[100] = "Hello World";
	char    c = 'H';
	char    *result;

	result = ft_strrchr(str, c);
	if (result != NULL)
		printf("TROUVÉ À L'INDICE %ld", result - str);
	else
		printf("Pas trouvé");
}*/
