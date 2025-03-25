/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:07:55 by laichoun          #+#    #+#             */
/*   Updated: 2024/03/15 10:16:11 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[j])
		{
			while (little[j] != '\0' && (big[i + j] != '\0')
				&& big[i + j] == little[j] && (i + j < len))
				j ++;
			if (little[j] == '\0')
				return ((char *)big + (i));
		}
		i ++;
		j = 0;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	big[100] = "Luffy Zoro Sanji";
	char	little[100] = "Sanji";
	char	*result;

	result = ft_strnstr(big, little, 0);
	if (result != NULL)
		printf("FOUND in index %ld", result - big);
	else
		printf("La valeur n'a pas éte trouvée");
}*/
