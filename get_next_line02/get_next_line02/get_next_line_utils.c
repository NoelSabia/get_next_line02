/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:07:12 by noel              #+#    #+#             */
/*   Updated: 2023/11/08 15:16:06 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && ((i + 1) < dstsize))
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i] != 0)
		i++;
	return (i);
}

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = s;
	b = (unsigned char *) &c;
	i = 0;
	while (i < len)
	{
		a[i] = *b;
		i++;
	}
	return (s);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	m;

	i = 0;
	m = 0;
	while (dst[i] != 0 && i < size)
		i++;
	while (src[m] != 0 && i + m + 1 < size)
	{
		dst[i + m] = src[m];
		m++;
	}
	if (i < size)
	{
		dst[i + m] = '\0';
	}
	return (ft_strlen(src) + i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	sum;

	sum = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = (char *)malloc(sum);
	if (!s3)
		return (NULL);
	ft_memset(s3, 0, sum);
	ft_strlcpy(s3, s1, sum + 1);
	ft_strlcat(s3, s2, sum + 1);
	return (s3);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
