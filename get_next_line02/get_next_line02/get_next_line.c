/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:07:14 by noel              #+#    #+#             */
/*   Updated: 2023/11/04 19:04:51 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)(s + i));
	}
	return (NULL);
}

char	*ft_get_line(char *buffer)
{
	char	*str;
	int		i;

	i = 0;
	if (!buffer[i])
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	while (buffer[i] != '\n' && buffer[i])
		i++;
	str = (char *)malloc(i + 2);
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

//muss mich um read kuemmern wenn es -1 zurueckgibt soll auch der buffer von davor fregegeben werden
// beispiel: Error in test 4: get_next_line(5: "read_error.txt"): expected: "aaaaaaaaaa\n", got: "ccccccccaaaaaaaaaa\n"
//Probable reason: You should clear the static buffer when a call to read returns -1
char	*read_in_buf(char *buffer, int fd)
{
	char	*str;
	char	*temp;
	int		counter;

	counter = 1;
	if (!buffer)
		return (NULL);
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
		free (str);
		return (NULL);
	}
	while (buffer[i])
		str[o++] = buffer[i++];
	str[o] = '\0';
	free (buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	if (!buffer || read(fd, buffer, 0) < 0)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
		{
			free(buffer);
			return (NULL);
		}
		buffer[0] = '\0';
	}
	buffer = read_in_buf(buffer, fd);
	result = ft_get_line(buffer);
	if (!result)
		return (NULL);
	buffer = copy_in_static(buffer);
	return (result);
}
