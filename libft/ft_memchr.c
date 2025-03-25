/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:02:06 by laichoun          #+#    #+#             */
/*   Updated: 2024/02/26 15:03:39 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char) c)
			return ((char *)str + i);
		i ++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[100] = {0, 1, 2 ,3 ,4 ,5};
	char	c = 4;
	char	*result;

	result = ft_memchr(str, c, 10);
	if (result != NULL)
		printf("TROUVÉ À L'INDICE %ld", result - str);
	else
		printf("Pas trouvé");
}*/
