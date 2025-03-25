/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:54:57 by laichoun          #+#    #+#             */
/*   Updated: 2024/06/05 12:16:36 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
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

	c = 'c';
	result = ft_isalpha(c);
	if (result == 1)
		printf("The value is a letter");
	else
		printf("the value is not a letter");
}
*/