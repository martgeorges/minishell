/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:06:50 by laichoun          #+#    #+#             */
/*   Updated: 2024/03/15 08:16:01 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*d;
	const char		*s;
	unsigned long	i;

	d = dest;
	s = src;
	i = 0;
	if (s == NULL && d == NULL)
		return (d);
	if (n == 0)
		return (d);
	while (i < n)
	{
		d[i] = s[i];
		i ++;
	}
	return (d);
}
/*
#include <stdio.h>

int	main(void)
{
	char	src[100] = "Monkey D Luffy";
	char	dest[100] = "";

	ft_memcpy(dest, src, 5);
	printf ("The result after the function is : %s", dest);
}*/
