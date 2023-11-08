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

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_strchr(const char *s, int c, int counter)
{
	int	i;

	i = 0;
	if (counter == 0)
		return (NULL);
	if (!s)
		return (NULL);
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
	while (counter && !ft_strchr(buffer, '\n', counter))
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
	str = (char *)malloc(ft_strlen(buffer) - i + 1);
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

#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main()
{
    int fd = open("texttest.txt", O_RDONLY);
	char *str =get_next_line(fd); 
	while (str)
	{
		printf("str: %s\n", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}