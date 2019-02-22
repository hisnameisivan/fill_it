#include "fillit.h"

int		fil_read(int fd, t_flist **begin)
{
	int		ret;
	int		flag_sn;
	char	letter;
	char	buf[21 + 1];	// ((5 * 4) + 1)
	t_flist	*temp;

	flag_sn = 0;
	letter = 'A';
	temp = NULL;
	while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
		if ((temp = fil_valid(buf, &flag_sn, letter)) == NULL)
			return (-1);
		if (!(*begin))
			*begin = temp;
		else
			fil_add_struct(begin, temp);
		//fil_print_one_struct(temp);	// DEMO
		//ft_putstr("\n");			// DEMO
		letter++;
	}
	if (ret == -1 || flag_sn == 1 || (*buf == '\0' && ret == 0))
		return (-1);
	return (1);
}
