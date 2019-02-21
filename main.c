#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_flist	*begin;

	begin = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fil_read(fd, &begin) == -1)
			ft_putendl("usage: ");
		if (fil_core(begin) == -1)
			exit(-1);
		close(fd);
	}
	else
		ft_putendl("usage: ");
	return (0);
}

//TODO:	malloc заменить на strnew где возможно
//		упаковать инкремент/декремент индекса (?)
//		защитить malloc и защитить от утечек в случае неудачи