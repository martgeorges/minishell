/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:58:40 by laichoun          #+#    #+#             */
/*   Updated: 2024/03/29 15:59:24 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_from_file(int fd, char *remain, char *buffer)
{
	ssize_t		bytes_read;
	char		*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(remain), NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (remain == NULL)
			remain = ft_strdup("");
		tmp = remain;
		remain = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (remain);
}

static char	*clean_remain(char *line_buffer)
{
	char	*remain;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\0' && line_buffer[i] != '\n')
		i ++;
	if (line_buffer[i] == '\0')
		return (NULL);
	remain = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*remain == '\0')
	{
		free(remain);
		remain = NULL;
	}
	line_buffer[i + 1] = '\0';
	return (remain);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remain;
	char		*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(remain);
		free(buffer);
		remain = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (buffer == NULL)
		return (NULL);
	line = read_from_file(fd, remain, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	remain = clean_remain(line);
	return (line);
}

/*
int	main(void)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open("example.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error on the file");
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		printf("[%d] : %s\n", count, line);
		free(line);
		line = NULL;
	}
	close(fd);
	return (0);
}
*/
