#include "fillit.h"

t_flist	*fil_crt_struct(char **array)
{
	int		i;
	t_flist	*temp;

	i = 0;
	if (!(temp = (t_flist *)malloc(sizeof(t_flist))))
		return (NULL);
	if (!array)
	{
		temp->array = NULL;
		temp->next = NULL;
	}
	else
	{
		if (!(temp->array = (char **)malloc(sizeof(char *) * 5)))
		{
			free(temp);
			return (NULL);
		}
		(temp->array)[4] = NULL;
		while (i < 4)
		{
			if (!(temp->array[i] = (char *)malloc(sizeof(char) * 5)))
			{
				while (i > 0)
				{
					free((temp->array)[i - 1]);
					i--;
				}
				free(temp->array);
				free(temp);
				return (NULL);
			}
			ft_memcpy((temp->array)[i], array[i], 5);
			i++;
		}
		temp->next = NULL;
	}
	return (temp);
}

void	fil_add_struct(t_flist **begin, t_flist *list)
{
	t_flist	*
}

if (!(array[j] = (char *)malloc(sizeof(char) * (len + 1))))
	{
		while (j > 0)
		{
			free(array[j - 1]);
			array[j - 1] = NULL;
			j--;
		}
		free(array);
		array = NULL;
		return (0);
	}