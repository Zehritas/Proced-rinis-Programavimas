#include <stdio.h>

int main()
{
  //variables
  int a, b, c, check;
  //input
  printf("This program prints positive whole numbers from interval (a; b],\nwhich, when divided by c give a remainder of 1.\n");
  printf("Input 3 whole numbers : a, b, c.\n");
  //foolproof
  while (scanf("%d %d %d", &a, &b, &c) != 3 || (getchar() != '\n'))
  {
    printf("Please input whole numbers!\n");
    while(getchar() != '\n')
    {

    }
  }

  printf("The numbers that fit the criteria:\n");
  check = 0;
  //main algorithm
  for (a += 1; a <= b; ++a)
  {
    if (a % c == 1 && a >= 0 )
    {
      printf("%d\n", a);
      check = 1;
    }
  }
  //check if there are soloutions
  if (check == 0)
  {
    printf("Numbers from the interval (a;b] fit the criteria!");
  }
}
