/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:38:57 by laichoun          #+#    #+#             */
/*   Updated: 2024/06/05 12:17:04 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
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

	c = 6 + '0';
	result = ft_isdigit(c);
	if (result == 1)
		printf ("The value is a digit\n");
	else
		printf ("The value is not a digit\n");
	printf("%d", c);
}
*/