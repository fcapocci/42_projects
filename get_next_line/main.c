#include "get_next_line.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char	*line;
	int		fd;
	int		ret;

	if (argc >= 2)
	{
		fd = open(argv[1], O_RDONLY);
		ft_putstr("fd return value --> ");
		ft_putnbr(fd);
		ft_putchar('\n');
		ret = 1;
		while (ret != 0)
		{
			ft_putstr("--GNL");
			ft_putstr("--\n");
			ret = get_next_line(fd, &line);
			ft_putstr("ret = ");
			ft_putnbr(ret);
			ft_putstr("\n\n");
		}
		close(fd);
	}
	return (0);
}
