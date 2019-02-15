#include "fillit.h"

int		fil_read(int fd)
{
	int		i;
	int		ret;
	int		flag_sn;
	char	*line;
	char	buf[21 + 1];	// ((5 * 4) + 1)

	i = 0;
	flag_sn = 0;
	line = NULL;
	while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
		line = ft_strnew(ret);
		ft_memcpy(line, buf, ret);
		if (fil_valid(line, &flag_sn) == -1)
			return (-1);
	}
	if (ret == -1 || flag_sn == 1)
		return (-1);
	return (1);
}
