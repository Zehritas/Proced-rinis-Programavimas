#include <stdio.h>

int main()
{
  //variables
  int a, b, c, fc, check;
  //input
  printf("This program takes three not negative whole numbers\na, b, c, it then outputs c-th member of the fibonacci sequence.\n");
  printf("Input 3 whole numbers : a, b, c.\n");
  //foolproof
  //(a >= 0 || b >= 0 || c >= 0)

  while (scanf("%d %d %d", &a, &b, &c) != 3 || (getchar() != '\n'))
  {
    printf("Please input whole numbers!\n");
    while(getchar() != '\n')
    {

    }
  }

  for (int i = 2; i < c; ++i)
  {
    a = b;
    b = fc;
    fc = a + b;
  }
  printf("%d", fc);



}
