/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:49:27 by laichoun          #+#    #+#             */
/*   Updated: 2024/02/27 12:44:33 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	else if (((nmemb * size) / size) != nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr != NULL)
		ft_bzero(ptr, (nmemb * size));
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	int	*array;
	int	i;
	int	nmemb;

	nmemb = 4;
	i = 0;
	array = ft_calloc(nmemb, sizeof(int));
	if (array == NULL)
	{
		printf("Error during the allocation");
		return (1);
	}
	else
	{
		while (i < nmemb)
		{
			printf("%d", array[i]);
			i ++;
		}
	}
	free(array);
}*/
