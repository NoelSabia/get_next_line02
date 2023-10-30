/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:07:14 by noel              #+#    #+#             */
/*   Updated: 2023/10/30 18:43:55 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int *start, int end, int fd)
{
	int		i;
	char	*s1;
	char	c;

	i = 0;
	s1 = (char *)ft_calloc(end - *start, sizeof(char));
	if (!s1)
		return (NULL);
	while (i < end - *start && read (fd, &c, BUFFER_SIZE) > '\0')
	{
		s1[i] = c;
		if (c == '\n' || c == '\0')
			break ;
		i++;
		(*start)++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*get_next_line(int fd)
{
	static int	start_len;
	static int	*start;
	static int	end;
	static char	*str;

	start_len = 0;
	start = &start_len;
	end = BUFFER_SIZE;
	if ((fd < 0 || fd > 2) || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(start, end, fd);
	free (str);
	return (str);
}
