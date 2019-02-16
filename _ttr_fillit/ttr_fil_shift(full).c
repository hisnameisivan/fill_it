#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void    fil_shift(char ***array)
{
    int        i;
    int        j;

    i = 0;
    j = 0;
    while ((*array)[i])
    {
        j = 0;
        while ((*array)[i][j])
        {
            if ((*array)[i][j] == '#')
                break ;
            j++;
        }
        if (j == 4 && i == 0)
        {
            memcpy((*array)[i], (*array)[i + 1], 4);
            memcpy((*array)[i + 1], (*array)[i + 2], 4);
            memcpy((*array)[i + 2], (*array)[i + 3], 4);
            memcpy((*array)[i + 3], "....", 4);
            i = -1;
        }
        i++;
    }
    while (((*array)[0][0] == '.') && ((*array)[1][0] == '.')\
        && ((*array)[2][0] == '.') && ((*array)[3][0] == '.'))
    {
        i = 0;
        while ((*array)[i])
        {
            j = 0;
            while ((*array)[i][j])
            {
                (*array)[i][j] = (*array)[i][j + 1];
                j++;
            }
            (*array)[i][3] = '.';
            i++;
        }
    }
}

int   main(void)
{
  char  **mas;
  int   i = 0;
  
  mas = (char**)malloc(sizeof(char*) * 5);
  mas[0] = strdup("....");
  mas[1] = strdup("....");
  mas[2] = strdup("..##");
  mas[3] = strdup("..##");
  mas[4] = NULL;
  while (mas[i])
    printf("%s\n", mas[i++]);
  fil_shift(&mas);
  i = 0;
  while (mas[i])
    printf("%s\n", mas[i++]);
  return (0);
}