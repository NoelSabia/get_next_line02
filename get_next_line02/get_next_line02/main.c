#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
    int fd = open("texttest.txt", O_RDONLY);
	for (int i = 0; i < 2; i++)
	{
		printf("%s", get_next_line(fd));
	}
	close(fd);
}
