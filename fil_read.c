#include "fillit.h"

int		fil_read(int fd, char **line) // возвращает количество \n
{
	int		i;
	int		ret;
	int		lines_num;
	char	buf[1000 + 1];

	i = 0;
	lines_num = 0;
	ret = read(fd, buf, 1000); // ((5 * 4) + 1) * 26 + 1
	if (ret == 0 || ret == -1)
		return (-1);
	buf[ret] = '\0';
	*line = ft_strnew(ret);
	ft_memcpy(*line, buf, ret);
	while (buf[i])
		if (buf[i++] == '\n')
			lines_num++;
	return (lines_num);
}
