#include <stdio.h>
#include <math.h>
int main()
{
  //variables
  int a, b, c;
  float d;
  //input
  printf("This program calculates the number of quadratic equations roots and their values!\n");
  printf("Input 3 whole numbers : a, b, c. These will be the numerical coefficients of the quadratic equation.\n");
  //foolproof
  while (scanf("%d %d %d", &a, &b, &c) != 3 || (getchar() != '\n'))
  {
    printf("Please input whole numbers!\n");
    while(getchar() != '\n')
    {

    }

  }

  d = ((b*b)-(4*a*c));

  //When discriminant is > 0
  if (d > 0)
  {
    printf("Quadratic equation has 2 roots!\n");
    float x1, x2;
    x1 = ((-b)+sqrt(d))/(2*a);
    x2 = ((-b)-sqrt(d))/(2*a);
    printf("x1: %f    x2: %f", x1, x2);

  }

  //When discriminant is 0
  else if (d == 0)
  {
    printf("Quadratic equation has 1 root!\n");
    float x;
    x = (-b)/(2*a);
    printf("x: %f", x);
  }
  //When discriminant < 0
  else
  {
    printf("Quadratic equation has no roots!\n");
  }

}
