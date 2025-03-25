/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:16:26 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/18 14:14:28 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (s == NULL || start >= ft_strlen(s))
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
			str[j++] = s[i];
		i ++;
	}
	str[j] = '\0';
	return (str);
}

/*
#include <stdio.h>
int	main(void)
{
	char str[100] = "ls";
	char *result;

	result = ft_substr(str, 0, ft_strlen(str));
	char *result_2 = ft_substr(str, ft_strlen(str) + 1, ft_strlen(str));
	if (result_2 == NULL)
		printf("c'est null\n");
	printf("the result is : %s\n", result);
	printf("the result_2 is : %s\n", result_2);
	return (0);
	
}
*/
