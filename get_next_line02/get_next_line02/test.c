// char	*get_next_line(int fd)
// {
// 	static char	*buffer;
// 	char		*newline;
// 	int			bytes_read;

// 	if (!buffer)
// 	{
// 		buffer = malloc(BUFFER_SIZE + 1);
// 		if (!buffer)
// 			return (NULL);
// 		buffer[0] = '\0';
// 	}
// 	newline = strchr(buffer, '\n');
// 	while (!newline)
// 	{
// 		bytes_read = read(fd, buffer + strlen(buffer), BUFFER_SIZE - strlen(buffer));
// 		if (bytes_read <= 0)
// 			break ;
// 		buffer[bytes_read] = '\0';
// 		newline = strchr(buffer, '\n');
// 	}
// 	if (!newline)
// 	{
// 		newline = buffer + strlen(buffer);
// 		if (newline == buffer)
// 			return (NULL);
// 	}
// 	*newline = '\0';
// 	char *line = strdup(buffer);
// 	if (!line)
// 		return (NULL);
// 	memmove(buffer, newline + 1, strlen(newline + 1) + 1);
// 	return (line);
// }


// char	*copy_in_static(char *buffer)
// {
// 	char	*str;
// 	int		i;
// 	int		o;

// 	i = 0;
// 	o = 0;
// 	if (!buffer[i])
// 	{
// 		free (buffer);
// 		return (NULL);
// 	}
// 	while (buffer[i] != '\n' && buffer[i])	
// 		i++;
// 	if (buffer[i] == '\0')
// 	{
// 		free(buffer);
// 		return (NULL);
// 	}
// 	i++;
// 	str = (char *)malloc(ft_strlen(buffer) - i + 1);
// 	if (!str)
// 	{
// 		free(buffer);
// 		return (NULL);
// 	}
// 	while (buffer[i])
// 	{
// 		str[o++] = buffer[i++];
// 	}
// 	str[o] = '\0';
// 	free (buffer);
// 	return (str);
// }