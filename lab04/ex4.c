#include <stdio.h>

int main()
{
  //variables
  int a, b, c, gcd, lcm, largestNumb;
  //input
  printf("This program takes three natural numbers a, b, c,\nit then outputs Greatest common divisor and Least common multiple.\n");
  printf("Input 3 natural numbers : a, b, c.\n");
  //foolproof
  while (scanf("%d %d %d", &a, &b, &c) != 3 || (a <= 0 || b <= 0 || c <= 0))
  {
    printf("Please input whole numbers!\n");
    while(getchar() != '\n')
    {

    }
  }
  //largest number
  largestNumb = a > b ? (a > c ? a : c) : (b > c ? b : c);

  //brute algorithm for gcd
  gcd = 1;
  for (int i = 1; i <= largestNumb; ++i)
  {
    if ((a % i == 0) && (b % i == 0) && (c % i == 0))
    {
      gcd = i;
    }
  }

  //brute algorithm for lcm
  for (int i = 1; ; ++i)
  {
    if((i % a == 0) && (i % b == 0) && (i % c == 0))
    {
      lcm = i;
      break;
    }
  }


  //output
  printf("Greatest common divisor: %d \n", gcd);
  printf("Least common multiple: %d \n", lcm);
}
