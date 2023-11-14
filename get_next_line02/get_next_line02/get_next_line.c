/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:07:14 by noel              #+#    #+#             */
/*   Updated: 2023/11/14 11:28:22 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int ft_find_newline(const char *s, int c)
{
    int m;

	m = 0;
    if (s == NULL)
        return (-1);
    while (s[m] != '\0' && s[m] != (char)c)
	{
        m++;
	}
    if (s[m] == c)
        return (m);
    return (-1);
}

void ft_free_buf(char **buf)
{
    if (buf != NULL)
    {
        free(*buf);
        *buf = NULL;
    }
}

char *read_from_file(int fd, char *str, int *read_bytes)
{
    char buffer[BUFFER_SIZE + 1];
    char *temp;
    *read_bytes = 0;
    if (ft_find_newline(str, '\n') == -1)
    {
        while (true)
        {
            *read_bytes = read(fd, buffer, BUFFER_SIZE);
            if (*read_bytes == 0 || *read_bytes < 0)
                break;
            buffer[*read_bytes] = '\0';
            if (!str)
                str = ft_strdup(buffer);
            else
            {
                temp = ft_strjoin(str, buffer);
                free(str);
                str = temp;
            }
            if (ft_find_newline(buffer, '\n') > -1)
                break;
        }
    }
    return (str);
}

int ft_copy(char **str, char **result, int i)
{
	int eos;
	char *temp;
	
	eos = ft_find_newline(*str, '\n');
	if (eos != -1)
	{
		*result = ft_substr(*str, 0, eos + 1);
		temp = ft_strdup(&(*str)[eos + 1]);
		free(*str);
		*str = temp;
		if ((*str)[0] == '\0')
		{
			ft_free_buf(str);
		}
	}
	else
	{
		if (i == 0)
		{
			*result = ft_strdup(*str);
			ft_free_buf(str);
			return (0);
		}
	}
	return (1);
}


char *get_next_line(int fd)
{
    static char *s = NULL;
    char *line;
    int result;
    result = 0;
    s = read_from_file(fd, s, &result);
    if (result < 0)
    {
        free(s);
        s = NULL;
        return (NULL);
    }
    else if (result == 0 && s == NULL && ft_find_newline(s, '\n') == -1)
    {
        free(s);
        s = NULL;
        return (NULL);
    }
    else
        if (ft_copy(&s, &line, result) == 1 || (result == 0 && line != NULL))
            return (line);
    free(s);
    s = NULL;
    return (NULL);
}
