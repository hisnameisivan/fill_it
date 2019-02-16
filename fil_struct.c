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
	t_flist	*temp;

	if (begin && list)
	{
		temp = *begin;
		while (temp->next)
			temp = temp->next;
		temp->next = list;
	}
}

int		fil_len_struct(t_flist *begin)
{
	int		len;

	len = 0;
	if (begin)
	{
		while (begin)
		{
			len++;
			begin = begin->next;
		}
	}
	return (len);
}

// DEMO
void	fil_print_struct(t_flist *begin)
{
	int		i;
	t_flist	*temp;

	i = 0;
	if (begin)
	{
		temp = begin;
		while (temp)
		{
			i = 0;
			while ((temp->array)[i])
				ft_putendl((temp->array)[i++]);
			temp = temp->next;
			if (temp)
				ft_putstr("\n");
		}
	}
}

// DEMO
void	fil_print_one_struct(t_flist *list)
{
	int		i;

	i = 0;
	if (list)
	{
		while ((list->array)[i])
			ft_putendl((list->array)[i++]);
	}
}
