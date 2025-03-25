/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:40:30 by laichoun          #+#    #+#             */
/*   Updated: 2024/02/23 11:39:00 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned long	i;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i ++;
	}
	return (s);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[50] = "1256595Hello, world!";

	printf("Before memset: %s\n", str);
	ft_memset(str, 'A', 5);
	printf("After memset: %s\n", str);
	return (0);
}*/
