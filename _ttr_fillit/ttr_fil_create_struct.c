#include <stdio.h>
#include <stdlib.h>

typedef struct        s_flist
{
    char            **array;
    struct s_flist    *next;
}                    t_flist;


t_flist    *fil_crt_struct(char **array)
{
    int        i;
    t_flist    *temp;

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
            memcpy((temp->array)[i], array[i], 5);
            i++;
        }
        temp->next = NULL;
    }
    return (temp);
}

int main()
{
  char     **mas;
  t_flist  *list;
  int      i = 0;
  
  mas = (char**)malloc(sizeof(char*) * 5);
  mas[0] = strdup("....");
  mas[1] = strdup("....");
  mas[2] = strdup("..##");
  mas[3] = strdup("..##");
  mas[4] = NULL;
  while (mas[i])
    printf("%s\n", mas[i++]);
  list = fil_crt_struct(mas);
  i = 0;
  while ((list->array)[i])
    printf("%s\n", (list->array)[i++]);
  return 0;
}