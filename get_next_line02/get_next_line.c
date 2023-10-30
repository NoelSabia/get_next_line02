/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:07:14 by noel              #+#    #+#             */
/*   Updated: 2023/10/30 12:02:56 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	buffer;

	buffer = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return ("bullshit");
	return ("hello");
}

// #include <stdio.h>

// int main()
// {
// 	printf("%s", get_next_line(1));
// }