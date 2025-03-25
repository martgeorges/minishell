/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:47:51 by laichoun          #+#    #+#             */
/*   Updated: 2024/02/28 15:19:46 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = ft_strlen(s1);
	i = 0;
	if (s1 == NULL && set == NULL)
		return (NULL);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i ++;
	while (s1[j - 1] != '\0' && ft_strchr(set, s1[j - 1]) && j > i)
		j --;
	str = (char *)malloc((j - i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	else
		ft_strlcpy(str, &s1[i], j - i + 1);
	return (str);
}
