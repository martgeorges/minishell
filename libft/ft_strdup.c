/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:54:56 by laichoun          #+#    #+#             */
/*   Updated: 2024/02/23 15:46:51 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	const char	*str;
	char		*duplicate;
	int			i;
	int			len;

	str = s;
	i = 0;
	len = 0;
	while (str[len] != '\0')
		len ++;
	duplicate = (char *)malloc((len + 1) * sizeof(char));
	if (duplicate != NULL)
	{
		while (len > 0)
		{
			duplicate[i] = str[i];
			len --;
			i ++;
		}
		duplicate[i] = '\0';
	}
	return (duplicate);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[100] = "Le ONE PIECE existe";
	char	*duplicate = ft_strdup(str);

	if (duplicate != NULL)
	{
		printf("la chaine de caractère dupliquée est : %s", duplicate);
		free(duplicate);
	}
	else
		fprintf(stderr, "ALlocation de mémoire echouée");
}*/
