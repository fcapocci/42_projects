#include "get_next_line.h"

static void		concat_list(t_list *list, char **line)
{
	t_list			*tmplist;
	unsigned long	len;

	len = 0;
	tmplist = list;
	while (tmplist)
	{
		len = len + tmplist->content_size;
		tmplist = tmplist->next;
	}
}

static int		reading_line(int const fd, t_list *list, char *buff, char **line)
{
	int				ret;
	char			*tmpptr;
	char			*tmpline;
	t_list			*start;

	start = list;
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buff, BUFF_SIZE);
		buff[ret] = '\0';
		list->content = ft_strdup(buff);
		list->content_size = ret;
		list = list->next;
		if ((tmpptr = ft_strchr(buff, '\n')))
			ret = 0;
	}
	if (concat_list(start, line) == 1)
		return (1);
	if ()
		return (0);
}

static int		more_reading_line()
{
}

int				get_next_line(int const fd, char **line)
{
	static t_files	files;
	t_list			*list;

	if (fd < 0 || line == NULL)
		return (-1);
	line = NULL;
	if (files.save != fd)
	{
		files.save = fd;
		ft_memdel((void*)files.buff);
	}
	if ((void*)files.buff)
		return (more_reading_line());
	else
		return (reading_line(fd, list, files.buff, line));
}
