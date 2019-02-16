#include <stdio.h>

int        fil_min_map(int num_ttr)
{
    int        side;

    side = 0;
    while (side * side < num_ttr)
        side++;
    return (side);
}

int main()
{
  int   num = 0;
  int   side = 0;
  
  while (num < 40)
  {
    side = fil_min_map(num);
    printf("num of tetrominos (&sharps) %d (%d), map %d x %d \n",\
    num / 4, num, side, side);
    num += 4;
  }
  return 0;
}