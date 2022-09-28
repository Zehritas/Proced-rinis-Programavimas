#include <stdio.h>

int main()
{
  int x, y, z;
  int max = 0, min = 0;
  //Input

  printf("Iveskite 3 skaicius\n");
  scanf("%d%d%d", &x, &y, &z);

  //MAX
  max = (x > z ? (x > y ? x : y) : (z > y ? z : y));

  //MIN
  printf(x < z ? (x < y ? x : y) : (z < y ? z : y));

  printf("MAX: %d  MIN: %d\n", max, min);

}
