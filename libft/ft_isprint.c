/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:26:37 by laichoun          #+#    #+#             */
/*   Updated: 2024/02/23 11:35:11 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	int	c;
	int	result;

	c = 56;
	result = ft_isprint(c);
	if (result == 1)
		printf("The value is printable");
	else
		printf("The value is not printable");
}*/
