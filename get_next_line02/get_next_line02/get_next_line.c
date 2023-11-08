/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:07:14 by noel              #+#    #+#             */
/*   Updated: 2023/11/08 14:23:41 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
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

char	*ft_get_line(char *buffer, int *m)
{
	char	*str;
	int		i;

	i = 0;
	if (!buffer[i])
	{
		if (m == 0)
		{
			free(buffer);
			buffer = NULL;
		}
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

char	*read_in_buf(char *buffer, int fd, int *i)
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
	while (counter && !ft_strchr(buffer, '\n'))
	{
		counter = read (fd, str, BUFFER_SIZE);
		if (counter == -1)
		{
			free (str);
			free (buffer);
			buffer = NULL;
			return (NULL);
		}
		if (counter == 0)
		{
			*i = 1;
			if (ft_strlen(buffer) > 0)
				return (buffer);
			else
			{
				free (str);
				free (buffer);
				buffer = NULL;
				return (NULL);

			}
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
	str = (char *)malloc(ft_strlen(buffer) - i + 1); // Leak 1
	if (!str)
	{
		free(buffer);
		free (str);
		return (NULL);
	}
	while (buffer[i])
		str[o++] = buffer[i++];
	str[o] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer = 0;
	char		*temp_buffer;
	char		*result;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	if (buffer == NULL)
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		buffer[0] = '\0';
	}
	buffer = read_in_buf(buffer, fd, &i);
	if (!buffer)
	{
		return (NULL);
	}
	result = ft_get_line(buffer, &i);
	if (!result)
		return (NULL);
	temp_buffer = copy_in_static(buffer);
	if (temp_buffer)
	{
		ft_strlcpy(buffer, temp_buffer, ft_strlen(temp_buffer) + 1);
		free(temp_buffer);
	}
	return (result);
}
