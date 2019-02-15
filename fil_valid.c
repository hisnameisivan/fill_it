#include "fillit.h"

// TODO	+ валидность фигур из списка 19
//		напрашивается закинуть фигуры в структуру, чтобы обращаться к ней одной, а не "выискивать ее в массиве"
//		функцию можно переделать в плане возвращаемого значения (char** NULL - плохо, массив -хорошо),
//		тогда параметров станет больше, мб меньше проблем со звезочками

int		fil_valid(char *line, int *flag)
{
	int		i;
	int		count_sharp;
	int		count_dot;
	int		count_sn;
	char	**spl_line;

	i = 0;
	count_sharp = 0;
	count_dot = 0;
	count_sn = 0;


	spl_line = ft_strsplit(line, '\n');


	while (line[i])
	{
		if (line[i] == '#')
			count_sharp++;
		else if (line[i] == '.')
			count_dot++;
		else if (line[i] == '\n')
		{
			count_sn++;
			if (!((i + 1) % 5 == 0 || i == 20))		// проверка на то, что в строке четыре символа (кратность 5)
				return (-1);						// и последний перенос строки, если тетраминок больше одной
		}
		else
			return (-1);
		i++;
	}


	if ((count_sharp != 4) || (count_dot != 12)\
		|| (count_sn < 4 || count_sn > 5))			// 4 звезды, 12 точек, 4 или 5 переносов
		return (-1);
	*flag = (count_sn == 5 ? 1 : 0);


	fil_shift(&spl_line);


	i = 0;
	while (spl_line[i])								// валидность строк
	{
		if (!ft_strcmp(spl_line[i], ".#.#") || !ft_strcmp(spl_line[i], "##.#")\
			|| !ft_strcmp(spl_line[i], "#.#.") || !ft_strcmp(spl_line[i], "#.##")\
			|| !ft_strcmp(spl_line[i], "#..#"))
			return (-1);
		else
			i++;
	}


	i = 0;
	while (line[i] != '\n')							// валидность столбцов
	{
		if ((line[i] == '.' && line[i + 5] == '#' && line[i + 10] == '.' && line[i + 15] == '#')\
			|| (line[i] == '#' && line[i + 5] == '#' && line[i + 10] == '.' && line[i + 15] == '#')\
			|| (line[i] == '#' && line[i + 5] == '.' && line[i + 10] == '#' && line[i + 15] == '.')\
			|| (line[i] == '#' && line[i + 5] == '.' && line[i + 10] == '#' && line[i + 15] == '#')\
			|| (line[i] == '#' && line[i + 5] == '.' && line[i + 10] == '.' && line[i + 15] == '#'))
			return (-1);
		else
			i++;
	}


	static t_flist	*begin;
	t_flist			*temp;

	temp = NULL;
	if(!begin)
	{
		begin = fil_crt_struct(spl_line);
		fil_print_one_struct(begin);
		ft_putstr("\n");
	}
	else
	{
		fil_add_struct(&begin, temp = fil_crt_struct(spl_line));
		fil_print_one_struct(temp);
		ft_putstr("\n");
	}


	return (1);
}



































/*	i = 0;
	j = 0;
	sim_count = 0;
	spl_line = ft_strsplit(line, '\n');

	while (spl_line[i])						// проверка на то, что в строке четыре символа
	{
		if (ft_strlen(spl_line[i]) == 4)
			i++;
		else
			return (-1);
	}

	i = 0;
	while (spl_line[i])						// проверка на то, что четыре решетки (убрать? - нет,
	{										// ибо простыня ниже будет работать некорректно)
		j = 0;
		while (spl_line[i][j])
		{
			if (spl_line[i][j] == '#')
			{
				sim_count++;
				j++;
			}
			else if (spl_line[i][j] == '.')
				j++;
			else
				return (-1);
			if (j == 3 && (i + 1) % 4 == 0)	// кратность четырем (одна поданная тетраминка).
			{								// + 1 т.к. нумерация с нуля
				if (sim_count != 4)
					return (-1);
				else
					sim_count = 0;
			}
		}
		i++;
	}

	if (lns_num != (i * 5 / 4 - 1))			// количество без \n (в массиве spl_line) после преобразования
		return (-1);						// должно равняться начальному количетву \n (lns_num)

	i = 0;
	while (spl_line[i])						// валидность строк
	{
		if (ft_strcmp(spl_line[i], ".#.#") && ft_strcmp(spl_line[i], "##.#")\
		&& ft_strcmp(spl_line[i], "#.#.") && ft_strcmp(spl_line[i], "#.##")\
		&& ft_strcmp(spl_line[i], "#.#."))
			return (-1);
		else
			i++;
	}

	i = 0;
	while (line[i])							// валидность столбцов
	{
		while ((lns_num + 1) * 4 / 5)

		if (line[i] == '0' && line[i + 5] == '0' && line[i] == '0' && line[i] == '0' &&)
	}*/

/*	i = 0;	// для valgrind
	while (spl_line[i])
	{
		free(spl_line[i]);
		i++;
	}
	free(spl_line);	*/
	//*array = spl_line;

/*	i = 0;
	while (spl_line[i])						// проверка на форму тетраминок
	{
		j = 0;
		sim_count = 0;
		while (spl_line[i][j])
		{
			if (spl_line[i][j] == '#')
			{
				if (i % 4 == 0)	// первые строки
				{
					if (j == 0)	// первый столбец
					{
						if (spl_line[i + 1][j] == '#' || spl_line[i][j + 1] == '#')	// ниже и правее
							continue ;
						else
							return (-1);
					}
					if (j == 1)	// второй столбец
					{
						if (spl_line[i + 1][j] == '#' || spl_line[i][j + 1] == '#' || spl_line[i][j - 1] == '#')	// ниже, правее и левее
							continue ;
						else
							return (-1);
					}
					if (j == 2)	// третий столбец
					{
						if (spl_line[i + 1][j] == '#' || spl_line[i][j + 1] == '#' || spl_line[i][j - 1] == '#')	// ниже, правее и левее
							continue ;
						else
							return (-1);
					}
					if (j == 3)	// четвертый столбец
					{
						if (spl_line[i + 1][j] == '#' || spl_line[i][j - 1] == '#')
							continue ;
						else
							return (-1);
					}
				}
			}
		}
		i++;
	}*/
