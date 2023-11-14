char    *read_from_file(int fd, char *s, int *result)
{
    char    buffer[BUFFER_SIZE + 1];
    char    *temp;
    *result = 0;
    if (ft_findstrind(s, '\n') == -1)
    {
        while (1)
        {
            *result = read(fd, buffer, BUFFER_SIZE);
            if (*result <= 0)
                break ;
            buffer[*result] = '\0';
            if (s == NULL)
                s = ft_strdup(buffer);
            else
            {
                temp = ft_strjoin(s, buffer);
                free(s);
                s = temp;
            }
            if (ft_findstrind(buffer, '\n') > -1)
                break ;
        }
    }
    return (s);
}


char *ft_read_in_buf(int fd, char *str, int *read_bytes)
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
                break ;
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
                break ;
        }
    }
    return (str);
}