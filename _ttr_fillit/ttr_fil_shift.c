#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  char  **arr = NULL;
  int   i = 0;
  int   j = 0;

  arr = (char**)malloc(sizeof(char*) * 5);
  arr[0] = strdup("....");
  arr[1] = strdup("###.");
  arr[2] = strdup("..#.");
  arr[3] = strdup("....");
  arr[4] = NULL;
  printf("%s\n%s\n%s\n%s\n\n", arr[0], arr[1], arr[2], arr[3]);
  memcpy(arr[0], arr[1], 4);
  memcpy(arr[1], arr[2], 4);
  memcpy(arr[2], arr[3], 4);
  memcpy(arr[3], "....", 4);
  printf("%s\n%s\n%s\n%s\n\n", arr[0], arr[1], arr[2], arr[3]);
  return 0;
}