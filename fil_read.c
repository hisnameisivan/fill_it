#include "fillit.h"

int		fil_read(int fd)
{
	int		i;
	int		ret;
	char	*line;
	char	buf[21 + 1];	// ((5 * 4) + 1)

	i = 0;
	while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
		line = ft_strnew(ret);
		ft_memcpy(line, buf, ret);
		if (fil_valid(line) == -1)
			return (-1);
	}
	if (ret == -1)
		return (-1);
	return (1);
}
