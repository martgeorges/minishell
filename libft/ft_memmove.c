/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:09:21 by laichoun          #+#    #+#             */
/*   Updated: 2024/03/15 09:14:39 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*d;
	const char		*s;

	d = dest;
	s = src;
	if (s == NULL && d == NULL)
		return (dest);
	if (s < d && s + n > d)
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n --;
		}
	}
	else
	{
		while (n --)
			*d++ = *s++;
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[100] = "Hello World";
	char	dest[100] = "";

	ft_memmove(dest, str, 8);
	printf("The src is : %s\n", str);
	printf("The dest is : %s\n", dest);
}*/
