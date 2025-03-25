/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:48:37 by laichoun          #+#    #+#             */
/*   Updated: 2024/02/23 12:51:59 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	int	result;

	result = 0;
	if (c >= 65 && c <= 90)
		result = c + 32;
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

	c = 69;
	result = ft_tolower(c);
	printf("La nouvelle valeur de la lettre est : %d", result);
}*/
