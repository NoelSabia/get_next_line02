/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:07:14 by noel              #+#    #+#             */
/*   Updated: 2023/11/02 17:24:57 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readone(int fd)
{
	char	*str;
	int		i;

	i = 0;
	
	while (1)
	{
		if (str[i] == '\n')
			return (str);
		else
		{
			if (read(fd, str, 1) < 0)
				return (NULL);
			i++;
		}
	}
}

char	*ft_read(int fd)
{
	char	*str;

	str = (char *)malloc(BUFFER_SIZE);
	if (read (fd, str, BUFFER_SIZE) < 0)
		return (NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*str;
	char			*temp_str;
	static int		i;

	i = 0;
	//Errors abfangen
	if (fd < 0 || BUFFER_SIZE < 1)
		return ("hi");
	//buffer fuellen mit allem
	buffer = ft_read(fd);
	printf("%s", buffer);
	//nach \n suchen um i zu initialisieren
	while (buffer[i] != '\n' && i <= BUFFER_SIZE)
		i++;
	//wenn sich ein \n im buffer befindet str initialisieren und entsprechendes von buffer in str kopieren
	if (i <= BUFFER_SIZE)
	{
		str = (char *)malloc(i + 1 * sizeof(char));
		if (!str)
			return (NULL);
		ft_memcpy(str, buffer, i + 1);
	}
	//wenn sich kein \n im buffer befindet wird so viel angehaengt bis man ein \n hat und an den buffer konketiniert
	while (i > BUFFER_SIZE)
	{
		temp_str = ft_readone(fd);
		ft_strlcat(buffer, temp_str, ft_strlen(temp_str));
		str = (char *)malloc(i + 1 * sizeof(char));
		if (!str)
			return (NULL);
		ft_memcpy(str, buffer, i + 1);
	}
	str[i] = '\0';
	return (str);
}
