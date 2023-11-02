/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel <noel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:07:14 by noel              #+#    #+#             */
/*   Updated: 2023/11/02 10:49:59 by noel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *buf_copy, size_t size_new)
{
	char		*new;
	static int	size_old;

	size_old = size_new;
	new = (char *)malloc(size_new  * sizeof(char));	
	ft_memcpy(new, buf_copy, size_new);
	return (new);
}

char	*ft_read(int fd)
{
	static char	*buf_copy;
	int			i;

	while (!ft_strchr(buf_copy, '\n'))	
	{
		if (read(fd, buf_copy, BUFFER_SIZE) == 0)
			break ;
		i = ft_strlen(buf_copy);
		buf_copy = ft_realloc(buf_copy, i);
	}
	return (buf_copy);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	int			i;

	i = 0;
	if (fd == FD_ERR || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_read(fd);
	while (buf[i] != '\n')
		i++;
	
	return (buf);
}
