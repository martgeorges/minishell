/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:39:35 by laichoun          #+#    #+#             */
/*   Updated: 2024/02/23 12:42:09 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	int	result;

	result = 0;
	if (c >= 97 && c <= 122)
		result = c - 32;
	else
		result = c;
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	int	c;
	int	result;

	c = 100;
	result = ft_toupper(c);
	printf("Mon nouveau caractère est : %d", result);
}*/
