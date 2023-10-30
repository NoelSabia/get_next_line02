/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:07:14 by noel              #+#    #+#             */
/*   Updated: 2023/10/30 12:35:58 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int start, int )
{

}

char	*get_next_line(int fd)
{
	static int	start;
	static char	*str;

	start = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(start, BUFFER_SIZE);

	return (str);
}
