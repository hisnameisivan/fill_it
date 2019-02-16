#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void  func(char ***array)
{
  int   i = 0;
  
  memcpy((*array)[i], (*array)[i + 1], 4);
  memcpy((*array)[i + 1], (*array)[i + 2], 4);
  memcpy((*array)[i + 2], (*array)[i + 3], 4);
  memcpy((*array)[i + 3], "....", 4);
}

int   main(void)
{
  char **temp = NULL;
  int   i = 0;
  
  temp = (char **)malloc(sizeof(char *) * 5);
  temp[0] = strdup("....");
  temp[1] = strdup(".###");
  temp[2] = strdup("..#.");
  temp[3] = strdup("....");
  temp[4] = NULL;
  while (temp[i])
    printf("%s\n", temp[i++]);
  func(&temp);
  i = 0;
  while (temp[i])
    printf("%s\n", temp[i++]);
  return (0);
}