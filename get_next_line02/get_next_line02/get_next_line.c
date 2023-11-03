/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:07:14 by noel              #+#    #+#             */
/*   Updated: 2023/11/03 18:06:53 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_line(char *buffer)
{
	char	*str;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*read_in_buf(char *buffer, int fd)
{
	char	*str;
	char	*temp;
	int		counter;

	counter = 1;
	str = (char *)malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && counter)
	{
		counter = read (fd, str, BUFFER_SIZE);
		if (counter == -1)
		{
			free (str);
			return (NULL);
		}
		str[counter] = '\0';
		temp = ft_strjoin(buffer, str);
		free(buffer);
		buffer = temp;
	}
	free(str);
	return (buffer);
}

char	*copy_in_static(char *buffer)
{
	char	*str;
	int		i;
	int		o;

	i = 0;
	o = 0;
	while (buffer[i] != '\n' && buffer[i])	
        i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	i++;
	str = (char *)malloc(ft_strlen(buffer) - i + 1);
	if (!str)
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[i])
	{
		str[o++] = buffer[i++];
	}
	str[o] = '\0';
	free (buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*result;
	
	if (!buffer)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_in_buf(buffer, fd);
	if (!buffer)
		return (NULL);
	result = get_line(buffer);
	if (!result)
		return (NULL);
	buffer = copy_in_static(buffer);
	return (result);
}
