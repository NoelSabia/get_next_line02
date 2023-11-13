/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:07:14 by noel              #+#    #+#             */
/*   Updated: 2023/11/13 20:31:42 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_find_string(const char *s, int c)
{
	int	i;

	i = 0;
	if (s[0] == 0)
		return (-1);
	while (s[i] != '\0' && s[i] != (char)c)
	{
		i++;
	}
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

void ft_free(char **str)
{
	if (**str != '\0')
	{
		free(*str);
		*str = NULL;
	}
}

int ft_new_newline(char **str, char **result, int i)
{
	char	*temp;
	int		end_of_str;

	end_of_str = ft_find_string(*str, '\n');
	if (end_of_str != -1)
	{
		*result = ft_substr(*str, 0, end_of_str + 1);
		temp = ft_strdup(&(*str)[end_of_str + 1]);
		free (*str);
		*str = temp;
		if (!(*str))
			ft_free(str);
	}
	else if (i == 0)
	{
		*result = ft_strdup(*str);
		ft_free(str);
		str = NULL;
		return (0);
	}
	return (1);
}

char *read_in_buf(char *str, int fd, int *i)
{
	char	*temp;
	char	buffer[BUFFER_SIZE + 1];
	
	*i = 0;
	if (ft_find_string(str, '\n') == -1)
	{
		while (1)
		{
			*i = read(fd, buffer, BUFFER_SIZE);
			if (*i <= 0)
				break;
			buffer[*i] = '\0';
			if (!str)
				str = ft_strdup(buffer);
			else
			{
				temp = ft_strjoin(str, buffer);
				free (str);
				str = NULL;
				str = temp;
			}
			if (ft_find_string(buffer, '\n') > -1)
				break;
		}
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*buffer = NULL;
	char			*result;
	int				i;

	i = 0;
	buffer = read_in_buf(buffer, fd, &i);
	if (result < 0)
	{
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	else if (result == 0 && buffer == NULL && ft_find_string(buffer, '\n') == -1)
	{
		free (buffer);
		buffer = NULL;
		return (NULL);		
	}
	else
		if (ft_new_newline(&buffer, &result, i) == 1
			|| (result == 0 && result != NULL))
			return (result);
	free (buffer);
	buffer = NULL;
	return (NULL);
}
