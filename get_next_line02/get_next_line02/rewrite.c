#include <stdlib.h>
#include <unistd.h>

int ft_findstrind(const char *s, int c)
{
    int i;
    if (!s)
        return (-1);
    i = 0;
    while (s[i] && s[i] != (char)c)
        i++;
    if (s[i] == c)
        return (i);
    return (-1);
}

void ft_strdel(char **as)
{
    if (as)
    {
        free(*as);
        *as = NULL;
    }
}

int ft_new_line(char **s, char **line, int result)
{
    char *temp;
    int str_end;
    str_end = ft_findstrind(*s, '\n');
    if ((str_end) != -1)
    {
        *line = ft_substr(*s, 0, str_end + 1);
        temp = ft_strdup(&(*s)[str_end + 1]);
        free(*s);
        *s = temp;
        if ((*s)[0] == '\0')
            ft_strdel(s);
    }
    else if (result == 0)
    {
        *line = ft_strdup(*s);
        ft_strdel(s);
        return (0);
    }
    return (1);
}

char *read_from_file(int fd, char *s, int *result)
{
    char buffer[BUFFER_SIZE + 1];
    char *temp;
    *result = 0;
    if (ft_findstrind(s, '\n') == -1)
    {
        while (1)
        {
            *result = read(fd, buffer, BUFFER_SIZE);
            if (*result <= 0)
                break;
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
                break;
        }
    }
    return (s);
}

char *get_next_line(int fd)
{
    static char *s = NULL;
    char *line;
    int result;
    result = 0;
    s = read_from_file(fd, s, &result);
    if (result < 0)
    {
        free(s);
        s = NULL;
        return (NULL);
    }
    else if (result == 0 && s == NULL && ft_findstrind(s, '\n') == -1)
    {
        free(s);
        s = NULL;
        return (NULL);
    }
    else
        if (ft_new_line(&s, &line, result) == 1
            || (result == 0 && line != NULL))
            return (line);
    free(s);
    s = NULL;
    return (NULL);
}