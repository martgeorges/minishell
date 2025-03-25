/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:46:46 by laichoun          #+#    #+#             */
/*   Updated: 2024/02/23 11:29:08 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) || (c >= 48 && c <= 57))
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

	c = 122;
	result = ft_isalnum(c);
	if (result == 1)
		printf("The value is alphanumerical");
	else
		printf("The value is not alpha numerical");
}*/
