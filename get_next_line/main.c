#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	char	*line;
	int		fd;
	int		ret;

	if (argc >= 2)
	{
		fd = open(argv[1], O_RDONLY);
		printf("fd return value --> %d\n", fd);
		ret = 1;
		while (ret != 0)
		{
			ft_putstr("--GNL--\n");
			ret = get_next_line(fd, &line);
			printf("line = %s\n", line);
			printf("ret = %d\n\n", ret);
		}
		//close(fd);
		if (argc >= 3)
		{
			fd = open(argv[2], O_RDONLY);
			printf("fd return value --> %d\n", fd);
			ret = 1;
			while (ret != 0)
			{
				ft_putstr("--GNL--\n");
				ret = get_next_line(fd, &line);
				printf("line = %s\n", line);
				printf("ret = %d\n\n", ret);
			}
			//close(fd);
		}
	}
	return (0);
}
