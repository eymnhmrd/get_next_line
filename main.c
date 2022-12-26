#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// int main()
// {
// 	char    *line;
// 	int fd = open("test.txt", O_RDWR);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		if(!line)
// 			break;
// 		free(line);
// 		// sleep(1);
// 	}
// 	return 0;
// }

// int main()
// {
// 	printf("%s", ft_strjoin("lbro", "zaml"));

// }

int main()
{
	char	*line;
	int fd = open("test.txt", O_RDWR);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	// while(1)
	// {

	// }
	return (0);
}
