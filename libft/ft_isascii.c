/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:13:23 by laichoun          #+#    #+#             */
/*   Updated: 2024/02/23 11:32:58 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
	result = ft_isascii(c);
	if (result == 1)
		printf("The value is an ascii value");
	else
		printf("The value is not an ascii value");
}*/
