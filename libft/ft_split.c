/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:22:11 by laichoun          #+#    #+#             */
/*   Updated: 2024/07/08 11:14:20 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i ++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i ++;
	return (i);
}
*/

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count ++;
			while (s[i] != '\0' && s[i] != c)
				i ++;
		}
		else
			i ++;
	}
	return (count);
}

static char	*ft_copy_word(const char *s, char c)
{
	char	*str;
	int		len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len ++;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, len + 1);
	return (str);
}

static void	ft_free_array(char **array, int j)
{
	while (j > 0)
		free(array[--j]);
	free(array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		j;

	j = 0;
	array = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (array == NULL || s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			array[j++] = ft_copy_word(s, c);
			if (!array[j - 1])
			{
				ft_free_array(array, j);
				return (NULL);
			}
			while (*s && *s != c)
				s ++;
		}
		else
			s ++;
	}
	array[j] = NULL;
	return (array);
}

/*
#include <stdio.h>

int	main(void)
{
	char str[100] = " ";
	char **result;
	int	i;

	i = 0;
	result = ft_split(str, ' ');
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		printf("C'est vide");
		free(result[i]);
		i ++;
	}
	if (result[0] == NULL)
		printf("ici");
	free(result);
	return (0);
}
*/