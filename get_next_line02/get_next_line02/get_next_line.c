/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel <noel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:07:14 by noel              #+#    #+#             */
/*   Updated: 2023/11/03 10:04:21 by noel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static int		o;
	static int		i;

	i = 0;
	//Errors abfangen
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	//buffer fuellen mit allem
	buffer = ft_read(fd);
	//nach \n suchen um i zu initialisieren
	o = i;
	while (buffer[i] != '\n' && i <= BUFFER_SIZE)
		i++;
	i++;
	//wenn sich ein \n im buffer befindet str initialisieren und entsprechendes von buffer in str kopieren
	if (i <= BUFFER_SIZE)
	{
		str = (char *)malloc(i + 1);
		if (!str)
			return (NULL);
		str = ft_substr(buffer, o,i);
		*buffer += i;
	}
	//substring damit das richtige vom buffer zurueckgegeben wird
	//wenn sich kein \n im buffer befindet wird so viel angehaengt bis man ein \n hat und an den buffer konketiniert
	if (i > BUFFER_SIZE)
	{
		temp_str = ft_read(fd);
		ft_strlcat(buffer, temp_str, ft_strlen(temp_str));
		str = (char *)malloc(i + 1 * sizeof(char));
		if (!str)
			return (NULL);
		ft_memcpy(str, buffer, i + 1);
		free (temp_str);
	}
	str[i] = '\0';
	return (str);
}
