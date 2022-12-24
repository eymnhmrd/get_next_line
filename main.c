#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	char    *line;
	int fd = open("test.txt", O_RDWR);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	// line = get_next_line(fd);
	// printf("%s", line);
	// free(line);
	// line = get_next_line(fd);
	// printf("%s", line);
	// free(line);
	return 0;
}
