// #include <fcntl.h>
// #include "get_next_line.h"
// #include <stdio.h>

// // int main()
// // {
// //     int fd = open("texttest.txt", O_RDONLY);
// // 	for (int i = 0; i < 2; i++)
// // 	{
// // 		printf("%s", get_next_line(fd));
// // 	}
// // 	close(fd);
// // }


// int main(void)
// {
//     char *line;
//     int fd;

//     fd = open("non_existent_file.txt", O_RDONLY);
//     line = get_next_line(fd);
//     if (line == NULL)
//     {
//         printf("Buffer is NULL as expected.\n");
//     }
//     else
//     {
//         printf("Unexpected behavior.\n");
//     }
//     close(fd);
//     return 0;
// }