#include "get_next_line.h"

static int		reading_line(int const fd, char *buff, char ***line)
{
	int				ret;
	char			*tmpptr;
	char			*tmpline;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buff, BUFF_SIZE);
		buff[ret] = '\0';
		if ((tmpptr = ft_strchr(buff, '\n')))
		{

			ret = 0;
		}
		tmpline = ft_strjoin((**line), );
	}
}

static int		more_reading_line()
{
}

int				get_next_line(int const fd, char **line)
{
	static t_files	files;

	if (fd < 0 || line == NULL)
		return (-1);
	if (files.save != fd)
	{
		files.save = fd;
		ft_memdel((void*)files.buff);
	}
	if ((void*)files.buff)
		return (more_reading_line());
	else
		return (reading_line(fd, files.buff, &line));
}
