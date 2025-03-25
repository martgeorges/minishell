/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:18:05 by laichoun          #+#    #+#             */
/*   Updated: 2024/02/26 15:22:36 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i ++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
#include <stdio.h>

int	main(void)
{
	char	src[100] = "Monkey D Luffy";
	char	dst[100] = "";
	int		result;

	result = ft_strlcpy(dst, src, 16);
	printf("La valeur est : %d et la chaine devient : %s", result, dst);
}*/
