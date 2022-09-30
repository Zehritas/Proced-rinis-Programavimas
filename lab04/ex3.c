#include <stdio.h>

int main()
{
  //variables
  int a, b, c, fc;
  //input
  printf("This program takes three not negative whole numbers\na, b, c, it then outputs c-th member of fc = f(c-1) + f(c-2) sequence.\n");
  printf("Input 3 whole numbers : a, b, c.\n");

  //foolproof
  while (scanf("%d %d %d", &a, &b, &c) != 3 || (a < 0 || b < 0 || c < 0))
  {
    printf("Please input whole numbers!\n");
    while(getchar() != '\n')
    {

    }
  }

  //algorithm
  for (int i = 2; i <= c; ++i)
  {
    fc = a + b;
    a = b;
    b = fc;
  }
  //output
  printf("%dth number of this sequence is: %d", c, fc);

}
