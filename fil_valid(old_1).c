#include "fillit.h"

// TODO	валидность фигур из списка 19
//		напрашивается закинуть фигуры в структуру, чтобы обращаться к ней одной, а не "выискивать ее в массиве"
//		функцию можно переделать в плане возвращаемого значения (char** NULL - плохо, массив -хорошо),
//		тогда параметров станет три, мб меньше проблем со звезочками

int		fil_valid(int lns_num, char *line, char ***array)
{
	int		i;
	int		j;
	int		sim_count;
	char	**spl_line;

	i = 0;
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
	}

/*	i = 0;	// для valgrind
	while (spl_line[i])
	{
		free(spl_line[i]);
		i++;
	}
	free(spl_line);	*/
	*array = spl_line;
	return (1);
}

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
