/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:00:09 by laichoun          #+#    #+#             */
/*   Updated: 2024/02/23 11:37:10 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i ++;
	return (i);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*str = NULL;
	int		result;

	result = ft_strlen(str);
	printf ("The result is : %d", result);
}
*/
