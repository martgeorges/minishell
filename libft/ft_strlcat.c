/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:36:44 by laichoun          #+#    #+#             */
/*   Updated: 2024/03/15 10:57:29 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen >= size)
		dstlen = size;
	if (dstlen == size)
		return (dstlen + srclen);
	if (size > dstlen + srclen)
		ft_memcpy(dst + dstlen, src, srclen + 1);
	else
	{
		ft_memcpy(dst + dstlen, src, size - dstlen - 1);
		dst[size - 1] = '\0';
	}
	return (dstlen + srclen);
}

/*
#include <stdio.h>

int	main(void)
{
	char	src[100] = "Luffy";
	char	dst[100] = "Monkey D Luffy";
	int		result;

	result = ft_strlcat(dst, src, 18);
	printf("the length is : %d, and the string is : %s", result, dst);
}*/
